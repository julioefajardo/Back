;
    supdrvOSCleanupSession(pDevExt, pSession);

    /*
     * Free the rest of the session stuff.
     */
    RTSpinlockDestroy(pSession->Spinlock);
    pSession->Spinlock = NIL_RTSPINLOCK;
    pSession->pDevExt = NULL;
    RTMemFree(pSession);
    LogFlow(("supdrvDestroySession: returns\n"));
}


/**
 * Inserts the session into the global hash table.
 *
 * @retval  VINF_SUCCESS on success.
 * @retval  VERR_WRONG_ORDER if the session was already inserted (asserted).
 * @retval  VERR_INVALID_PARAMETER if the session handle is invalid or a ring-0
 *          session (asserted).
 * @retval  VERR_DUPLICATE if there is already a session for that pid.
 *
 * @param   pDevExt         The device extension.
 * @param   pSession        The session.
 * @param   ppOsSessionPtr  Pointer to the OS session pointer, if any is
 *                          available and used.  This will set to point to the
 *                          session while under the protection of the session
 *                          hash table spinlock.  It will also be kept in
 *                          PSUPDRVSESSION::ppOsSessionPtr for lookup and
 *                          cleanup use.
 * @param   pvUser          Argument for supdrvOSSessionHashTabInserted.
 */
int VBOXCALL supdrvSessionHashTabInsert(PSUPDRVDEVEXT pDevExt, PSUPDRVSESSION pSession, PSUPDRVSESSION *ppOsSessionPtr,
                                        void *pvUser)
{
    PSUPDRVSESSION  pCur;
    unsigned        iHash;

    /*
     * Validate input.
     */
    AssertReturn(SUP_IS_SESSION_VALID(pSession), VERR_INVALID_PARAMETER);
    AssertReturn(pSession->R0Process != NIL_RTR0PROCESS, VERR_INVALID_PARAMETER);

    /*
     * Calculate the hash table index and acquire the spinlock.
     */
    iHash = SUPDRV_SESSION_HASH(pSession->Process);

    RTSpinlockAcquire(pDevExt->hSessionHashTabSpinlock);

    /*
     * If there are a collisions, we need to carefully check if we got a
     * duplicate.  There can only be one open session per process.
     */
    pCur = pDevExt->apSessionHashTab[iHash];
    if (pCur)
    {
        while (pCur && pCur->Process != pSession->Process)
            pCur = pCur->pCommonNextHash;

        if (pCur)
        {
            RTSpinlockRelease(pDevExt->hSessionHashTabSpinlock);
            if (pCur == pSession)
            {
                Assert(pSession->fInHashTable);
                AssertFailed();
                return VERR_WRONG_ORDER;
            }
            Assert(!pSession->fInHashTable);
            if (pCur->R0Process == pSession->R0Process)
                return VERR_RESOURCE_IN_USE;
            return VERR_DUPLICATE;
        }
    }
    Assert(!pSession->fInHashTable);
    Assert(!pSession->ppOsSessionPtr);

    /*
     * Insert it, doing a callout to the OS specific code in case it has
     * anything it wishes to do while we're holding the spinlock.
     */
    pSession->pCommonNextHash = pDevExt->apSessionHashTab[iHash];
    pDevExt->apSessionHashTab[iHash] = pSession;
    pSession->fInHashTable    = true;
    ASMAtomicIncS32(&pDevExt->cSessions);

    pSession->ppOsSessionPtr = ppOsSessionPtr;
    if (ppOsSessionPtr)
        ASMAtomicWritePtr(ppOsSessionPtr, pSession);

    supdrvOSSessionHashTabInserted(pDevExt, pSession, pvUser);

    /*
     * Retain a reference for the pointer in the session table.
     */
    ASMAtomicIncU32(&pSession->cRefs);

    RTSpinlockRelease(pDevExt->hSessionHashTabSpinlock);
    return VINF_SUCCESS;
}


/**
 * Removes the session from the global hash table.
 *
 * @retval  VINF_SUCCESS on success.
 * @retval  VERR_NOT_FOUND if the session was already removed (asserted).
 * @retval  VERR_INVALID_PARAMETER if the session handle is invalid or a ring-0
 *          session (asserted).
 *
 * @param   pDevExt     The device extension.
 * @param   pSession    The session. The caller is expected to have a reference
 *                      to this so it won't croak on us when we release the hash
 *                      table reference.
 * @param   pvUser      OS specific context value for the
 *                      supdrvOSSessionHashTabInserted callback.
 */
int VBOXCALL supdrvSessionHashTabRemove(PSUPDRVDEVEXT pDevExt, PSUPDRVSESSION pSession, void *pvUser)
{
    PSUPDRVSESSION  pCur;
    unsigned        iHash;
    int32_t         cRefs;

    /*
     * Validate input.
     */
    AssertReturn(SUP_IS_SESSION_VALID(pSession), VERR_INVALID_PARAMETER);
    AssertReturn(pSession->R0Process != NIL_RTR0PROCESS, VERR_INVALID_PARAMETER);

    /*
     * Calculate the hash table index and acquire the spinlock.
     */
    iHash = SUPDRV_SESSION_HASH(pSession->Process);

    RTSpinlockAcquire(pDevExt->hSessionHashTabSpinlock);

    /*
     * Unlink it.
     */
    pCur = pDevExt->apSessionHashTab[iHash];
    if (pCur == pSession)
        pDevExt->apSessionHashTab[iHash] = pSession->pCommonNextHash;
    else
    {
        PSUPDRVSESSION pPrev = pCur;
        while (pCur && pCur != pSession)
        {
            pPrev = pCur;
            pCur  = pCur->pCommonNextHash;
        }
        if (pCur)
            pPrev->pCommonNextHash = pCur->pCommonNextHash;
        else
        {
            Assert(!pSession->fInHashTable);
            RTSpinlockRelease(pDevExt->hSessionHashTabSpinlock);
            return VERR_NOT_FOUND;
        }
    }

    pSession->pCommonNextHash = NULL;
    pSession->fInHashTable    = false;

    ASMAtomicDecS32(&pDevExt->cSessions);

    /*
     * Clear OS specific session pointer if available and do the OS callback.
     */
    if (pSession->ppOsSessionPtr)
    {
        ASMAtomicCmpXchgPtr(pSession->ppOsSessionPtr, NULL, pSession);
        pSession->ppOsSessionPtr = NULL;
    }

    supdrvOSSessionHashTabRemoved(pDevExt, pSession, pvUser);

    RTSpinlockRelease(pDevExt->hSessionHashTabSpinlock);

    /*
     * Drop the reference the hash table had to the session.  This shouldn't
     * be the last reference!
     */
    cRefs = ASMAtomicDecU32(&pSession->cRefs);
    Assert(cRefs > 0 && cRefs < _1M);
    if (cRefs == 0)
        supdrvDestroySession(pDevExt, pSession);

    return VINF_SUCCESS;
}


/**
 * Looks up the session for the current process in the global hash table or in
 * OS specific pointer.
 *
 * @returns Pointer to the session with a reference that the caller must
 *          release.  If no valid session was found, NULL is returned.
 *
 * @param   pDevExt         The device extension.
 * @param   Process         The process ID.
 * @param   R0Process       The ring-0 process handle.
 * @param   ppOsSessionPtr  The OS session pointer if available.  If not NULL,
 *                          this is used instead of the hash table.  For
 *                          additional safety it must then be equal to the
 *                          SUPDRVSESSION::ppOsSessionPtr member.
 *                          This can be NULL even if the OS has a session
 *                          pointer.
 */
PSUPDRVSESSION VBOXCALL supdrvSessionHashTabLookup(PSUPDRVDEVEXT pDevExt, RTPROCESS Process, RTR0PROCESS R0Process,
                                                   PSUPDRVSESSION *ppOsSessionPtr)
{
    PSUPDRVSESSION  pCur;
    unsigned        iHash;

    /*
     * Validate input.
     */
    AssertReturn(R0Process != NIL_RTR0PROCESS, NULL);

    /*
     * Calculate the hash table index and acquire the spinlock.
     */
    iHash = SUPDRV_SESSION_HASH(Process);

    RTSpinlockAcquire(pDevExt->hSessionHashTabSpinlock);

    /*
     * If an OS session pointer is provided, always use it.
     */
    if (ppOsSessionPtr)
    {
        pCur = *ppOsSessionPtr;
        if (   pCur
            && (   pCur->ppOsSessionPtr != ppOsSessionPtr
                || pCur->Process        != Process
                || pCur->R0Process      != R0Process) )
            pCur = NULL;
    }
    