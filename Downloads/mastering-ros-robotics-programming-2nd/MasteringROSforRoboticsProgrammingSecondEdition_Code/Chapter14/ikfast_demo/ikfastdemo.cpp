 = (*it);
      name = serverMode->getName();
      ArLog::log(ArLog::Normal,"UnlockModeCheck(%s): Trying to activate %s", 
		 getName(), name.c_str());
      
      ourRequestedActivateModes.pop_front();

      serverMode->activate();

      if (ourActiveMode == ourIdleMode)
      {
	ArLog::log(ArLog::Normal, "UnlockModeCheck(%s): Idle mode activated instead, so leaving the requestedActivateModes alone", getName());
	return;
      }
      
      if (ourActiveMode != this && ourActiveMode != NULL)
      {
	ArLog::log(ArLog::Normal, "UnlockModeCheck(%s): Activated another mode  (%s) assuming it takes care of the rest", getName(), 
		   ourActiveMode->getName());
	return;
      }
    } // end while modes to activate
    ArLog::log(ArLog::Normal, 
	       "UnlockModeCheck(%s): No other mode activated",
	       getName());
  }
  else
  {
    ArLog::log(ArLog::Normal, "UnlockModeCheck: Our next active mode %s, removing it from requested activate modes", ourNextActiveMode->getName());
    ourRequestedActivateModes.remove(ourNextActiveMode);
    return;
  }
  ArLog::log(ArLog::Normal,
             "UnlockModeCheck: Nothing else wanted to activate after %s unlocked", getName());

}

/**
   This should only be called from places where a forced unlock _HAS_
   to happen, ie on a robot joystick, but modes should do whatever
   they have to in this to turn things off or what not.
**/
AREXPORT void ArServerMode::forceUnlock(void)
{
  ArLog::log(ArLog::Terse, "Mode %s being forcibly unlocked", getName()); 
  unlockMode();
}

/// Gets whether we'll unlock if requested or not
AREXPORT bool ArServerMode::willUnlockIfRequested(void) 
{
  if (ourActiveMode == NULL || !ourActiveModeLocked || 
      (ourActiveModeLocked && ourActiveModeWillUnlockIfRequested))
    return true;
  else
    return false;
}

/// Gets if the active mode is locked or not 
AREXPORT bool ArServerMode::isLocked(void) 
{
  if (ourActiveMode == NULL || !ourActiveModeLocked)
    return false;
  else
    return true;
}

AREXPORT bool ArServerMode::isAutoResumeAfterInterrupt()
{
  return false;
}


/**
   Makes this mode active if it can... If this returns false then the
   mode's activate() method should just return... Note that before calling
   this a mode should have already made sure it can activate... This also 
   calls the activate callbacks (only if the mode will be allowed to
   activate of course).

   IMPORTANT: This method must only be called within the context of the
   activate() method.
 **/

AREXPORT bool ArServerMode::baseActivate(bool canSelfActivateIfLocked)
{

  // if we're locked then return false so nothing else activates
  if (ourActiveMode != NULL && ourActiveModeLocked && 
      (ourActiveMode != this || !canSelfActivateIfLocked))
  {
    ArLog::log(myVerboseLogLevel, "ArServerMode: Could not switch to %s mode because of lock (%s).", 
	       getName(), ArUtil::convertBool(canSelfActivateIfLocked));
 
    // request our active mode to unlock
    //
    // KMC: Moved the following line so that it is called after this mode is pushed
    // onto the ourRequestedActivatedModes queue.  Under certain conditions, 
    // the requestUnlock() call results in a mode being deactivated and the next
    // queued mode being activated. This mode will essentially be pushed onto the 
    // queue too late -- and will either be ignored or activated at an unexpected
    // time.  (An example scenario occurs when the robot is going to dock, and the
    // go-to-goal mode attempts to activate.)
    // ourActiveMode->requestUnlock();

    ArLog::log(myVerboseLogLevel, "ArServerMode: Removing this (%s) from requested activate modes",
               getName());

    ourRequestedActivateModes.remove(this);
    ArLog::log(myVerboseLogLevel, "ArServerMode: Mode %s wants to be activated, adding to requested activate modes.", getName());

    ourRequestedActivateModes.push_front(this);

    ourActiveMode->requestUnlock();
    
    return false;
  
  }

  if (this != ourIdleMode && myServer->idleProcessingPending())
  {
    if (ourActiveMode == ourIdleMode)
    {
      /* MPL this is the old behavior that caused by 13711 ... now we
       * add it toe the queue isntead

      ArLog::log(myVerboseLogLevel, 
		 "Since idle already active didn't set nextActiveMode when mode %s tried to activate, just returning", this->getName());      
      return false;
      */
      ArLog::log(myVerboseLogLevel, 
		 "ArServerMode: Since idle already active didn't set nextActiveMode when mode %s tried to activate, just adding to requested activate modes", this->getName());      
      ourRequestedActivateModes.remove(this);
      ourRequestedActivateModes.push_front(this);
      return false;
    }
    ourNextActiveMode = ourIdleMode;
    if (ourActiveMode != NULL)
      ArLog::log(myVerboseLogLevel, 
		 "ArServerMode: Setting nextActiveMode explicitly to idle mode from mode %s trying to activate while %s is active", this->getName(), ourActiveMode->getName());
    else
      ArLog::log(myVerboseLogLevel, 
		 "ArServerMode: Setting nextActiveMode explicitly to idle mode from mode %s trying to activate while no mode is active", this->getName());
		       
    if (ourActiveMode != NULL && ourActiveMode != ourIdleMode)
    {
      ourIdleMode->setModeInterrupted(ourActiveMode);
      ourActiveMode->deactivate();
    }
    ArLog::log(myVerboseLogLevel, "ArServerMode: Removing this (%s) from requested activate modes",
               getName());
    ourRequestedActivateModes.remove(this);
    ArLog::log(myVerboseLogLevel, "ArServerMode: Mode %s wants to be activated, denying for now because of idle, but adding to requested activate modes", getName());
    ourRequestedActivateModes.push_front(this);
    ourIdleMode->activate();
    return false;
  }

  ourNextActiveMode = this;
  if (ourActiveMode != NULL)
    ArLog::log(myVerboseLogLevel, "ArServerMode: Setting nextActiveMode to mode %s (ourActiveMode %s)",
	       ourNextActiveMode->getName(), ourActiveMode->getName());
  else
    ArLog::log(myVerboseLogLevel, "ArServerMode: Setting nextActiveMode to mode %s (ourActiveMode NULL)",
	       ourNextActiveMode->getName());
  if (ourActiveMode != NULL)
    ourActiveMode->deactivate();

  myIsActive = true;
  myActivityTimeMutex.lock();
  myActivityTime.setToNow(); 
  myActivityTimeMutex.unlock();

  /*
  if (myRobot != NULL)
  {
    myRobot->addUserTask(myName.c_str(), 50, &myUserTaskCB);
  }
  */
  ourLastActiveMode = ourActiveMode;
  ourActiveMode = this;
  ourNextActiveMode = NULL;

  ArLog::log(myVerboseLogLevel, "ArServerMode: Setting nextActiveMode to NULL");
  if (myRobot != NULL)
  {
    myRobot->stop();
    myRobot->clearDirectMotion();
  }
  /// Call our activate callbacks
  myActivateCallbacks.invoke();
  /// Set the activity time to now, but do NOT set the flag, since that flag is used to determine if a particular mode has used it or not
  ArLog::log(myVerboseLogLevel, "ArServerMode: Activated %s mode", getName());
  checkBroadcastModeInfoPacket();
  return true;
}

/**
   Whenever a mode uses this it should already have done all of its
   own deactivations (this also calls the deactive callbacks)
 **/
AREXPORT void ArServerMode::baseDeactivate(void)
{
  std::list<ArServerMode *>::iterator it;
  /*
  for (it = ourDefaultModes.begin(); 
       it != ourDefaultModes.end();
       it++)
  {
    ArLog::log(myVerboseLogLevel, "ArServerMode: defaults are %s mode", (*it)->getName());
  }
  */
  // if we're the active mode, we're deactivating, and we're locked, then unlock
  if (ourActiveMode != NULL && ourActiveMode == this && ourActiveModeLocked)
    unlockMode();
  // if the unlock mode caused the deactivation of this mode to happen just return
  if (!myIsActive || ourActiveMode != this)
    return;
  /*
    if (myRobot != NULL)
    myRobot->remUserTask(&myUserTaskCB);
  */
  myIsActive = false;
  if (ourActiveMode == this)
  {
    ourLastActiveMode = ourActiveMode;
    ourActiveMode = NULL;
  }
  myDeactivateCallbacks.invoke();
  mySingleShotDeactivateCallbacks.invoke();
  
  ArLog::log(myVerboseLogLevel, "ArServerMode: Deactivated %s mode", getName());

  if (ourNextActiveMode == NULL)
  {
    ArLog::log(myVerboseLogLevel, "ArServerMode: No next active mode %s", getName());

    // walk through until one of these is ready
    while ((it = ourRequestedActivateModes.begin()) != 
	   ourRequestedActivateModes.end())
    {
      std::string name;
      name = (*it)->getName();
      ArLog::log(myVerboseLogLevel, "ArServerMode: Trying to activate %s", name.c_str());
      
      (*it)->activate();

      if (ourActiveMode == ourIdleMode)
      {
	ArLog::log(myVerboseLogLevel, "ArServerMode: Idle mode activated instead, so leaving the requestedActivateModes alone");
	mySingleShotPostDeactivateCallbacks.invoke();
	return;
      }
      
      ArLog::log(myVerboseLogLevel, "ArServerMode: Popping front of requested activate modes (%s)", getName());
      
      ourRequestedActivateModes.pop_front();
      
      if (ourActiveMode != NULL)
      {
	ArLog::log(myVerboseLogLevel, "ArServerMode: and did, clearing requested activate modes (size = %i)",
                   ourRequestedActivateModes.size());
	// now clear out the old modes so that we don't wind up
	// stacking too much. First, notify them that they will not be activated.
        for (std::list<ArServerMode *>::iterator dIter = ourRequestedActivateModes.begin();
             dIter != ourRequestedActivateModes.end();
             dIter++) 
	{
          ArServerMode *deniedMode = *dIter;
          if (deniedMode != NULL) 
	  {
            deniedMode->activationDenied();
          }
        }
	
	ourRequestedActivateModes.clear();
	
        ArLog::log(myVerboseLogLevel,
                   "ArServerMode: Deactivate %s mode returns (1)", getName());
	mySingleShotPostDeactivateCallbacks.invoke();
	return;
      }
    } // end while modes to activate

    ArLog::log(myVerboseLogLevel, "ArServerMode: Deactivate did not activate any modes, clearing requested activate modes (size = %i)", ourRequestedActivateModes.size());
    
    // now clear out the old modes so that we don't wind up stacking
    // too much (should be empty anyways here, just make sure.  (Same logic
    // as above about notifying the mode that it won't be activated.)
    for (std::list<ArServerMode *>::iterator dIter = ourRequestedActivateModes.begin();
         dIter != ourRequestedActivateModes.end();
         dIter++) {
      ArServerMode *deniedMode = *dIter;
      if (deniedMode != NULL) {
        deniedMode->activationDenied();
      }
    }
    ourRequestedActivateModes.clear();
    
    for (it = ourDefaultModes.begin(); 
	 it != ourDefaultModes.end() && ourActiveMode == NULL;
	 it++)
    {
      ArLog::log(ArLog::Normal, "Checking default on %s mode", (*it)->getName());
      (*it)->checkDefault();
      if (ourActiveMode != NULL)
      {
	//printf("and did\n");
        ArLog::log(myVerboseLogLevel,
                   "ArServerMode: Deactivate %s mode returns (2)", getName());
	mySingleShotPostDeactivateCallbacks.invoke();
	return;
      }
    }
  }
  else
  {
    ArLog::log(myVerboseLogLevel, "ArServerMode: Our next active mode %s, removing it from requested activate modes", ourNextActiveMode->getName());
    ourRequestedActivateModes.remove(ourNextActiveMode);
  }
  ArLog::log(myVerboseLogLevel,
             "ArServerMode: Deactivate %s mode returns (3)", getName());
  mySingleShotPostDeactivateCallbacks.invoke();
  
}

/**
   The default mode is activated whenever a mode is deactivated, even
   if a mode is deactivated only for another mode to be activated
 **/
AREXPORT void ArServerMode::addAsDefaultMode(ArListPos::Pos pos)
{
  ArLog::log(ArLog::Normal, "Mode %s added as default mode", getName());
  if (pos == ArListPos::LAST)
    ourDefaultModes.push_back(this);
  else if (pos == ArListPos::FIRST)
    ourDefaultModes.push_front(this);
  else
  {
    ArLog::log(ArLog::Terse, "ArServerMode::addAsDefaultMode: bad list position.");
    ourDefaultModes.push_front(this);
  }
}

AREXPORT ArTime ArServerMode::getActivityTime(void) 
{ 
  ArTime ret;
  myActivityTimeMutex.lock();
  ret = myActivityTime;
  myActivityTimeMutex.unlock();
  return ret;
}

AREXPORT void ArServerMode::setActivityTimeToNow(void)     
{ 
  myActivityTimeMutex.lock();
  myHasSetActivityTime = true; 
  mySetActivityThisCycle = true;
  myActivityTime.setToNow(); 
  myActivityTimeMutex.unlock();
}

void ArServerMode::internalSetActivityTime(ArTime time)     
{ 
  myActivityTimeMutex.lock();
  myHasSetActivityTime = true; 
  mySetActivityThisCycle = false;
  myActivityTime = time;
  myActivityTimeMutex.unlock();
}

AREXPORT int ArServerMode::getActiveModeActivityTimeSecSince(void) 
{ 
  // chop this to an int so its easier to use, if you care about it
  // use the getActivityTime on the ourActiveMode
  if (ourActiveMode != NULL)
    return (int)ourActiveMode->getActivityTime().secSince();
  else 
    return -1;
}

AREXPORT bool ArServerMode::getActiveModeSetActivityThisCycle(void) 
{ 
  return ourActiveModeSetActivityThisCycle;
}

AREXPORT const char *ArServerMode::getActiveModeModeString(void) 
{ 
  if (ourActiveMode != NULL)
    return ourActiveMode->getMode();
  else 
    return NULL;
}


AREXPORT const char *ArServerMode::getActiveModeStatusString(void) 
{ 
  if (ourActiveMode != NULL)
    return ourActiveMode->getStatus();
  else 
    return NULL;
}

AREXPORT const char *ArServerMode::getActiveModeExtendedStatusString(void) 
{ 
  if (ourActiveMode != NULL)
    return ourActiveMode->getExtendedStatus();
  else 
    return NULL;
}

/**
   This basically just notes the commands associated with a mode so
   that clients can know what can and can't happen based on what mode
   is active/locked/etc.  You should call it only if the addData on
   the ArServerBase returns true (since otherwise it means that
   command wasn't added).
**/
AREXPORT bool ArServerMode::addModeData(
	const char *name, const char *description,
	ArFunctor2<ArServerClient *, ArNetPacket *> *functor,
	const char *argumentDescription, const char *returnDescription,
	const char *commandGroup, const char *dataFlags)
{
  if (myServer->addData(name, description, functor, argumentDescription,
			returnDescription, commandGroup, dataFlags))
  {
    ourModeDataMapMutex.lock();
    ourModeDataMap.insert(std::pair<std::string, std::string>(myName, name));
    ourModeDataMapMutex.unlock();
    return true;
  }
  else
  {
    ArLog::log(ArLog::Normal, "ArServerMode %s: Could not add mode data %s",
	       myName.c_str(), name);
    return false;
  }
      
}

/**
   This returns the list of which data is in which mode
**/
AREXPORT void ArServerMode::getModeDataList(ArServerClient *client, 
					    ArNetPacket *packet)

{
  ourModeDataMapMutex.lock();
  ArNetPacket sending;
  sending.uByte4ToBuf(ourModeDataMap.size());
  std::multimap<std::string, std::string>::iterator it;
  for (it = ourModeDataMap.begin(); it != ourModeDataMap.end(); it++)
  {
    sending.strToBuf((*it).first.c_str());
    sending.strToBuf((*it).second.c_str());
  }
  ourModeDataMapMutex.unlock();
  client->sendPacketTcp(&sending);
}

/**
   This will get the info about the current active mode
**/
AREXPORT void ArServerMode::getModeInfo(ArServerClient *client, 
					ArNetPacket *packet)
{
  ArNetPacket sending;
  buildModeInfoPacket(&sending);
  client->sendPacketTcp(&sending);
}

AREXPORT void ArServerMode::buildModeInfoPacket(ArNetPacket *sending)
{  
  if (ourActiveMode != NULL)
  {
    sending->strToBuf(ourActiveMode->getName());
    if (ourActiveModeLocked)
      sending->uByteToBuf(1);
    else
      sending->uByteToBuf(0);
    if (ourActiveModeWillUnlockIfRequested)
      sending->uByteToBuf(1);
    else
      sending->uByteToBuf(0);
  }
  else
  {
    sending->strToBuf("");
    sending->uByteToBuf(0);
    sending->uByteToBuf(0);
  }
  return;
}

AREXPORT void ArServerMode::checkBroadcastModeInfoPacket(void)
{
  if (ourActiveMode != ourBroadcastActiveMode || 
      ourActiveModeLocked != ourBroadcastActiveModeLocked ||
      ourActiveModeWillUnlockIfRequested != 
              ourBroadcastActiveModeWillUnlockIfRequested)
  {
    ArNetPacket sending;
    buildModeInfoPacket(&sending);
    myServer->broadcastPacketTcp(&sending, "getModeInfo");
  }
  
  ourBroadcastActiveMode = ourActiveMode;
  ourBroadcastActiveModeLocked = ourActiveModeLocked;
  ourBroadcastActiveModeWillUnlockIfRequested = ourActiveModeWillUnlockIfRequested;
}

AREXPORT ArServerMode* ArServerMode::getActiveMode(void) 
{ 
	return ourActiveMode; 
}
  
AREXPORT ArServerMode* ArServerMode::getLastActiveMode() 
{ 
	return ourLastActiveMode; 
}

AREXPORT ArServerModeIdle* ArServerMode::getIdleMode(void) { return ourIdleMode; }

AREXPORT std::list<ArServerMode *> *ArServerMode::getRequestedActivateModes(void)
{
  return &ourRequestedActivateModes;
}

AREXPORT void ArServerMode::getModeBusy(ArServerClient *client, 
					                              ArNetPacket *packet)
{
  ArNetPacket sending;
  sending.byteToBuf(ourIsBusy);
  client->sendPacketTcp(&sending);
}



                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
#include "Aria.h"
#include "ArExport.h"

#include "ArClientArgUtils.h"

#include <ArConfigArg.h>

#include "ArNetPacket.h"

//#define ARDEBUG_CLIENTARGUTILS

#if (defined(_DEBUG) && defined(ARDEBUG_CLIENTARGUTILS))
#define IFDEBUG(code) {code;}
#else
#define IFDEBUG(code)
#endif 

AREXPORT ArClientArg::ArClientArg(bool isDisplayHintParsed,
                                  ArPriority::Priority lastPriority,
                                  int version,
                                  bool isSingleParam) :
  myIsDisplayHintParsed(isDisplayHintParsed),
  myLastPriority(lastPriority),
  myVersion(version),
  myIsSingleParam(isSingleParam),
  myBuffer(),
  myDisplayBuffer(),
  myParentPathNameBuffer()
{}

AREXPORT ArClientArg::~ArClientArg()
{}

AREXPORT bool ArClientArg::isSendableParamType(const ArConfigArg &arg,
                                               bool isIncludeSeparator)
{
  switch (arg.getType()) {
  case ArConfigArg::INT:
  case ArConfigArg::DOUBLE:
  case ArConfigArg::BOOL:
  case ArConfigArg::LIST:
  case ArConfigArg::STRING:
    return true;
  case ArConfigArg::SEPARATOR:
    return isIncludeSeparator;

  default:
    return false;
  }
}


AREXPORT bool ArClientArg::createArg(ArNetPacket *packet, 
							                       ArConfigArg &argOut,
                                     std::string *parentPathNameOut) 
{
	if (packet == NULL) {
    ArLog::log(ArLog::Verbose, "ArClientArg::createArg() cannot unpack NULL packet");
		return false;
	}

	bool isSuccess = true;

	char name[32000];
	char description[32000];
  myDisplayBuffer[0] = '\0';

	packet->bufToStr(name, sizeof(name));
	packet->bufToStr(description, sizeof(description));


	char priorityVal = packet->bufToByte();
 
	ArPriority::Priority priority = myLastPriority;
  if ((priorityVal >= 0) && (priorityVal <= myLastPriority)) {
    priority = (ArPriority::Priority) priorityVal;
  }

	char argType = packet->bufToByte();

 switch (argType) {
	
 case 'B':
 case 'b': // Lower case indicates display information contained in packet...
	  {
      if ((argType == 'B') || (myIsDisplayHintParsed)) {

		    bool boolVal = false;
		    if (packet->bufToByte()) {
			    boolVal = true;
		    }
		    //packet->bufToStr(myDisplayBuffer, BUFFER_LENGTH);
		    argOut = ArConfigArg(name, boolVal, description);
      }
      else {
        isSuccess = false;
      }
	  }
    break;

  case 'I':
  case 'i':  // Lower case indicates display information contained in packet...
	  {
      if ((argType == 'I') || (myIsDisplayHintParsed)) {
  
		    int intVal = packet->bufToByte4();
		    int intMin = packet-