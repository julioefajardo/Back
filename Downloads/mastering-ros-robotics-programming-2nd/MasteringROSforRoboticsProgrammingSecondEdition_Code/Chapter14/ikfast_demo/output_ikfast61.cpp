Acquire process stops running."""
        base.AcquireProgress.stop(self)
        # Trick for getting a translation from apt
        self._write((_("Fetched %sB in %s (%sB/s)\n") % (
                    apt_pkg.size_to_str(self.fetched_bytes),
                    apt_pkg.time_to_str(self.elapsed_time),
                    apt_pkg.size_to_str(self.current_cps))).rstrip("\n"))

        # Delete the signal again.
        import signal
        signal.signal(signal.SIGWINCH, self._signal)


class CdromProgress(base.CdromProgress, TextProgress):
    """Text CD-ROM progress."""

    def ask_cdrom_name(self):
        """Ask the user to provide a name for the disc."""
        base.CdromProgress.ask_cdrom_name(self)
        self._write(_("Please provide a name for this Disc, such as "
                      "'Debian 2.1r1 Disk 1'"), False)
        try:
            return input(":")
        except KeyboardInterrupt:
            return

    def update(self, text, current):
        """Set the current progress."""
        base.CdromProgress.update(self, text, current)
        if text:
            self._write(text, False)

    def change_cdrom(self):
        """Ask the user to change the CD-ROM."""
        base.CdromProgress.change_cdrom(self)
        self._write(_("Please insert a Disc in the drive and press enter"),
                    False)
        try:
            return (input() == '')
        except KeyboardInterrupt:
            return False
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
Y4WV�*  �               @   s�   d  Z  d d l m Z d d l Z d d l Z d d l Z d d l Z d d l Z d d l Z d d l	 Z	 d d d d g Z
 Gd d �  d e � Z Gd	 d �  d e � Z Gd
 d �  d e � Z Gd d �  d e � Z d S)z�Base classes for progress reporting.

Custom progress classes should inherit from these classes. They can also be
used as dummy progress classes which simply do nothing.
�    )�print_functionN�AcquireProgress�CdromProgress�InstallProgress�
OpProgressc               @   s�   e  Z d  Z d Z d Z Z Z Z Z d Z	 Z
 Z d d �  Z d d �  Z d d	 �  Z d
 d �  Z d d �  Z d d �  Z d d �  Z d d �  Z d S)r   z�Monitor object for downloads controlled by the Acquire class.

    This is an mostly abstract class. You should subclass it and implement the
    methods to get something useful.
    g        r   c             C   s   d S)z<Invoked when an item is successfully and completely fetched.N� )�self�itemr   r   �3/usr/lib/python3/dist-packages/apt/progress/base.py�done2   s    zAcquireProgress.donec             C   s   d S)z*Invoked when an item could not be fetched.Nr   )r   r	   r   r   r
   �fail5   s    zAcquireProgress.failc             C   s   d S)z0Invoked when some of the item's data is fetched.Nr   )r   r	   r   r   r
   �fetch8   s    zAcquireProgress.fetchc             C   s   d S)z�Invoked when an item is confirmed to be up-to-date.

        Invoked when an item is confirmed to be up-to-date. For instance,
        when an HTTP download is informed that the file on the server was
        not modified.
        Nr   )r   r	   r   r   r
   �ims_hit;   s    zAcquireProgress.ims_hitc             C   s   d S)a�  Prompt the user to change the inserted removable media.

        The parameter 'media' decribes the name of the media type that
        should be changed, whereas the parameter 'drive' should be the
        identifying name of the drive whose media should be changed.

        This method should not return until the user has confirmed to the user
        interface that the media change is complete. It must return True if
        the user confirms the media change, or False to cancel it.
        Fr   )r   Zmedia�driver   r   r
   �media_changeC   s    zAcquireProgress.media_changec             C   s   d S)a  Periodically invoked while the Acquire process is underway.

        This method gets invoked while the Acquire progress given by the
        parameter 'owner' is underway. It should display information about
        the current state.

        This function returns a boolean value indicating whether the
        acquisition should be continued (True) or cancelled (False).
        Tr   )r   �ownerr   r   r
   �pulseP   s    
zAcquireProgress.pulsec             C   sL   d |  _  d |  _ d |  _ d |  _ d |  _ d |  _ d |  _ d |  _ d S)z0Invoked when the Acquire process starts running.g        r   N)�current_bytes�current_cps�current_items�elapsed_time�fetched_bytes�
last_bytes�total_bytes�total_items)r   r   r   r
   �start\   s    							zAcquireProgress.startc             C   s   d S)z/Invoked when the Acquire process stops running.Nr   )r   r   r   r
   �stoph   s    zAcquireProgress.stopN)�__name__�
__module__�__qualname__�__doc__r   r   r   r   r   r   r   r   r   r   r   r   r   r   r   r   r   r   r   r
   r   '   s   c               @   s@   e  Z d  Z d Z d Z d d �  Z d d �  Z d d �  Z d	 S)
r   a
  Base class for reporting the progress of adding a cdrom.

    Can be used with apt_pkg.Cdrom to produce an utility like apt-cdrom. The
    attribute 'total_steps' defines the total number of steps and can be used
    in update() to display the current progress.
    r   c             C   s   d S)z�Ask for the name of the cdrom.

        If a name has been provided, return it. Otherwise, return None to
        cancel the operation.
        Nr   )r   r   r   r
   �ask_cdrom_namev   s    zCdromProgress.ask_cdrom_namec             C   s   d S)z�Ask for the CD-ROM to be changed.

        Return True once the cdrom has been changed or False to cancel the
        operation.
        Nr   )r   r   r   r
   �change_cdrom}   s    zCdromProgress.change_cdromc             C   s   d S)z�Periodically invoked to update the interface.

        The string 'text' defines the text which should be displayed. The
        integer 'current' defines the number of completed steps.
        Nr   )r   �text�currentr   r   r
   �update�   s    zCdromProgress.updateN)r   r   r   r    Ztotal_stepsr!   r"   r%   r   r   r   r
   r   l   s
   c               @   s�   e  Z d  Z d Z d \ Z Z Z Z d d �  Z d d	 �  Z	 d
 d �  Z
 d d �  Z d d �  Z d d �  Z d d �  Z d d �  Z d d �  Z d d �  Z d d �  Z d d �  Z d S) r   z4Class to report the progress of installing packages.r   �        皙�����?� c             C   sh   t  j �  \ |  _ |  _ t  j |  j d � |  _ t  j |  j d � |  _ t j |  j t j t  j	 � d  S)N�w�r)
�os�pipeZstatusfdZwritefd�fdopen�write_stream�status_stream�fcntlZF_SETFL�
O_NONBLOCK)r   r   r   r
   �__init__�   s    zInstallProgress.__init__c             C   s   d S)z(Abstract) Start update.Nr   )r   r   r   r
   �start_update�   s    zInstallProgress.start_updatec             C   s   d S)z+(Abstract) Called when update has finished.Nr   )r   r   r   r
   �finish_update�   s    zInstallProgress.finish_updatec             C   s   d S)z>(Abstract) Called when a error is detected during the install.Nr   )r   �pkgZerrormsgr   r   r
   �error�   s    zInstallProgress.errorc             C   s   d S)zA(Abstract) Called when a conffile question from dpkg is detected.Nr   )r   r$   �newr   r   r
   �conffile�   s    zInstallProgress.conffilec             C   s   d S)z.(Abstract) Called when the APT status changed.Nr   )r   r5   �percent�statusr   r   r
   �status_change�   s    zInstallProgress.status_changec             C   s   d S)z/(Abstract) Called when the dpkg status changed.Nr   )r   r5   r:   r   r   r
   �dpkg_status_change�   s    z"InstallProgress.dpkg_status_changec             C   s   d S)z�(Abstract) Sent just before a processing stage starts.

        The parameter 'stage' is one of "upgrade", "install"
        (both sent before unpacking), "configure", "trigproc", "remove",
        "purge". This method is used for dpkg only.
        Nr   )r   r5   Zstager   r   r
   �
processing�   s    zInstallProgress.processingc             C   s�   |  j  �  } | d k r� y# t j | j |  j j �  � � Wn� t k
 r� t j t j t j d d d t	 |  j j �  � d | � � YnL t
 k
 r� } z, t j j d | � t j t j j � WYd d } ~ Xn X| |  _ |  j �  } t j | � S)a�  Install using the object 'obj'.

        This functions runs install actions. The parameter 'obj' may either
        be a PackageManager object in which case its do_install() method is
        called or the path to a deb file.

        If the object is a PackageManager, the functions returns the result
        of calling its do_install() method. Otherwise, the function returns
        the exit status of dpkg. In both cases, 0 means that there were no
        problems.
        r   Zdpkgz--status-fdz-iz%s
N)�forkr+   �_exit�
do_installr.   �fileno�AttributeError�spawnlp�P_WAIT�str�	Exception�sys�stderr�write�apt_pkg�PackageManager�RESULT_FAILED�	child_pid�
wait_child�WEXITSTATUS)r   �obj�pid�e�resr   r   r
   �run�   s    #&	zInstallProgress.runc             C   s
   t  j �  S)zFork.)r+   r>   )r   r   r   r
   r>   �   s    zInstallProgress.forkc       	      C   s�  y |  j  j �  } WnZ t k
 ro } z: | j t j k rY | j t j k rY t | j � d SWYd d } ~ Xn Xd } } } } } | j d � r� y" | j	 d d � \ } } } } Wq}t
 k
 r� d SYq}Xn� | j d � r7y" | j	 d d � \ } } } } Wq}t
 k
 r3| j	 d d � \ } } } Yq}XnF | j d � r}| j	 d d � \ } } } |  j | j �  | j �  � | j �  } | j �  } | j �  } | d	 k s�| d
 k r�|  j | | � n� | d k s�| d k r!t j d | � } | r�|  j | j d � | j d � � n� | d k r�t | � |  j k sQ| |  j k r�|  j | t | � | j �  � t | � |  _ | j �  |  _ n | d k r�|  j | | � d S)zUpdate the interface.Nr(   Zpm�:�   r:   �   r=   Zpmerrorr6   zconffile-promptZ
pmconffilez\s*'(.*)'\s*'(.*)'.*�   Zpmstatus)r/   �readline�IOError�errno�EAGAIN�EWOULDBLOCK�print�strerror�
startswith�split�
ValueErrorr=   �stripr6   �re�matchr8   �group�floatr9   r:   r;   r<   )	r   �line�errZpkgnamer:   Z
status_strr9   �basere   r   r   r
   �update_interface�   sH    $""#%$z InstallProgress.update_interfacec             C   s  d \ } } x� y# t  j  |  j g g  g  |  j � WnI t  j k
 r} } z& | j \ } } | t j k rk �  WYd d } ~ Xn X|  j �  y2 t j	 |  j
 t j � \ } } | |  j
 k r� PWq t k
 r	} z- | j t j k r� P| j t j k r� �  WYd d } ~ Xq Xq W| S)a  Wait for child progress to exit.

        This method is responsible for calling update_interface() from time to
        time. It exits once the child has exited. The return values is the
        full status returned from os.waitpid() (not only the return code).
        r   N)r   r   )�selectr/   �select_timeoutr6   �argsr[   ZEINTRrk   r+   �waitpidrM   �WNOHANG�OSErrorZECHILD)r   rQ   rS   r6   Zerrno_Z_errstrri   r   r   r
   rN     s(    
zInstallProgress.wait_childN)r   r&   r'   r(   )r   r   r   r    rM   r9   rm   r:   r2   r3   r4   r6   r8   r;   r<   r=   rT   r>   rk   rN   r   r   r   r
   r   �   s   !/c               @   sC   e  Z d  Z d Z d
 \ Z Z Z Z d d d � Z d d	 �  Z	 d S)r   zbMonitor objects for operations.

    Display the progress of operations such as opening the cache.Fr(   �        Nc             C   s   | d k	 r | |  _  d S)z�Called periodically to update the user interface.

        You may use the optional argument 'percent' to set the attribute
        'percent' in this call.
        N)r9   )r   r9   r   r   r
   r%   ,  s    zOpProgress.updatec             C   s   d S)z,Called once an operation has been completed.Nr   )r   r   r   r
   r   5  s    zOpProgress.done)Fr(   rr   r(   )
r   r   r   r    �major_change�opr9   Zsubopr%   r   r   r   r   r
   r   %  s   	)r    �
__future__r   r[   r0   r+   rd   rl   rG   rJ   �__all__�objectr   r   r   r   r   r   r   r
   �<module>   s   E �                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
Y4WV�%  �               @   s�   d  Z  d d l m Z d d l Z d d l Z d d l Z d d l m Z d d d g Z e j	 j
 d k  rt e Z n e Z d	 d
 �  Z Gd d �  d e � Z Gd d �  d e j e � Z Gd d �  d e j e � Z Gd d �  d e j e � Z d S)z'Progress reporting for text interfaces.�    )�print_functionN)�base�AcquireProgress�CdromProgress�
OpProgress�   c             C   s1   t  j |  � } | |  k r- t  j |  d � } | S)z>Translate the message, also try apt if translation is missing.�apt)�apt_pkg�gettext)�msg�res� r   �3/usr/lib/python3/dist-packages/apt/progress/text.py�_"   s    r   c               @   s7   e  Z d  Z d Z d d d � Z d d d d � Z d S)	�TextProgressz.Internal Base class for text progress classes.Nc             C   s   | p t  j |  _ d |  _ d  S)Nr   )�sys�stdout�_file�_width)�self�outfiler   r   r   �__init__-   s    zTextProgress.__init__TFc             C   s�   |  j  j d � |  j  j | � |  j t | � k rY |  j  j |  j t | � d � n! | rz t |  j t | � � |  _ | r� |  j  j d � n |  j  j �  d S)z8Write the message on the terminal, fill remaining space.�� �
N)r   �writer   �len�max�flush)r   r   �newlineZmaximizer   r   r   �_write1   s    $zTextProgress._write)�__name__�
__module__�__qualname__�__doc__r   r    r   r   r   r   r   *   s   r   c               @   s@   e  Z d  Z d Z d d d � Z d d d � Z d d �  Z d S)	r   z\Operation progress reporting.

    This closely resembles OpTextProgress in libapt-pkg.
    Nc             C   s-   t  j |  | � t j j |  � d |  _ d  S)N� )r   r   r   r   �old_op)r   r   r   r   r   r   H   s    zOpProgress.__init__c             C   sh   t  j j |  | � |  j r5 |  j r5 |  j |  j � |  j d |  j |  j f d d � |  j |  _ d S)z1Called periodically to update the user interface.z%s... %i%%FTN)r   r   �updateZmajor_changer&   r    �op�percent)r   r)   r   r   r   r'   M   s
    #zOpProgress.updatec             C   sL   t  j j |  � |  j r? |  j t d � d |  j f d d � d |  _ d S)z,Called once an operation has been completed.z%c%s... Doner   Tr%   N)r   r   �doner&   r    r   )r   r   r   r   r*   U   s    	&zOpProgress.done)r!   r"   r#   r$   r   r'   r*   r   r   r   r   r   B   s   c               @   s�   e  Z d  Z d Z d d d � Z d d �  Z d d �  Z d	 d
 �  Z d d �  Z d d �  Z	 d d �  Z
 d d �  Z d d �  Z d S)r   z'AcquireProgress for the text interface.Nc             C   sE   t  j |  | � t j j |  � d  |  _ d |  _ t d � |  _ d  S)N�P   �   )r   r   r   r   �_signalr   �long�_id)r   r   r   r   r   r   `   s
    		zAcquireProgress.__init__c             C   sT   t  j j |  � d d l } | j | j |  j � |  _ |  j �  t d � |  _ d S)z�Start an Acquire progress.

        In this case, the function sets up a signal handler for SIGWINCH, i.e.
        window resize signals. And it also sets id to 1.
        r   Nr,   )	r   r   �start�signal�SIGWINCH�_winchr-   r.   r/   )r   r1   r   r   r   r0   g   s
    
zAcquireProgress.startc             G   s�   t  |  j d � r� t j |  j j �  � r� d d l } d d l } d d l } | j |  j | j	 d � } | j
 d | � \ } } } } | d |  _ d S)	z)Signal handler for window resize signals.�filenor   N�   r   Zhhhhr,   z        )�hasattrr   �os�isattyr4   �fcntl�termios�structZioctlZ
TIOCGWINSZ�unpackr   )r   �dummyr9   r:   r;   �buf�colr   r   r   r3   t   s    *zAcquireProgress._winchc             C   s`   t  j j |  | � t d � | j } | j j rO | d t j | j j � 7} |  j	 | � d S)z@Called when an item is update (e.g. not modified on the server).zHit z [%sB]N)
r   r   �ims_hitr   �description�owner�filesizer	   �size_to_strr    )r   �item�liner   r   r   r@   ~   s
    zAcquireProgress.ims_hitc             C   s}   t  j j |  | � | j j | j j k rH |  j t d � | j � n1 |  j t d � | j � |  j d | j j	 � d S)zCalled when an item is failed.zIgn zErr z  %sN)
r   r   �failrB   �status�	STAT_DONEr    r   rA   �
error_text)r   rE   r   r   r   rG   �   s
    zAcquireProgress.failc             C   s�   t  j j |  | � | j j r# d S|  j | j _ |  j d 7_ t d � d | j j | j f } | j j	 r� | d t
 j | j j	 � 7} |  j | � d S)z/Called when some of the item's data is fetched.Nr,   zGet:z%s %sz [%sB])r   r   �fetchrB   �completer/   �idr   rA   rC   r	   rD   r    )r   rE   rF   r   r   r   rK   �   s    #zAcquireProgress.fetchc       	      C   s�  t  j j |  | � t |  j d � rB t j |  j j �  � rB d S|  j |  j	 d t
 |  j |  j � } d } d | } d } |  j r� t t
 |  j |  j � |  j � } d t j |  j � t j | � f } x�| j D]} d } | j sC| j r� d | j } t | � t | � t | � |  j k r0P| | 7} d } q� d } | j j j r~| d	 | j j j | j j f 7} n | d
 | j j 7} | j j j r�| d | j j j 7} | d t j | j � 7} | j r| j j j r| d t j | j � | j d | j f 7} | d 7} t | � t | � t | � |  j k rPPq� | | 7} q� W| st| t d � 7} |  j r�| |  j t | � t | � d | 7} |  j  | d � d S)z�Periodically invoked while the Acquire process is underway.

        Return False if the user asked to cancel the whole Acquire process.r4   Tg      Y@Fz%i%%r%   z	 %sB/s %sz [%s]z [%i %sz [%sz %sz %sBz	/%sB %i%%�]z
 [Working]r   )!r   r   �pulser6   r   r7   r8   r4   Zcurrent_bytesZcurrent_items�float�total_bytesZtotal_items�current_cpsr.   r	   rD   �time_to_str�workers�current_itemrH   r   r   rB   rM   �	shortdescrA   �active_subprocess�current_size�
total_sizerL   r   r    )	r   rB   r)   ZshownZtval�endZetaZworker�valr   r   r   rO   �   s\    
			)

)	)zAcquireProgress.pulsec             C   s@   t  j j |  | | � |  j t d � | | f � t �  d k S)z7Prompt the user to change the inserted removable media.zUMedia change: please insert the disc labeled
 '%s'
in the drive '%s' and press enter
�c�C)r\   r]   )r   r   �media_changer    r   �input)r   ZmediumZdriver   r   r   r^   �   s    zAcquireProgress.media_changec             C   s�   t  j j |  � |  j t d � t j |  j � t j |  j	 � t j |  j
 � f j d � � d d l } | j | j |  j � d S)z/Invoked when the Acquire process stops running.zFetched %sB in %s (%sB/s)
r   r   N)r   r   �stopr    r   r	   rD   Zfetched_bytesrS   Zelapsed_timerR   �rstripr1   r2   r-   )r   r1   r   r   r   r`   �   s     zAcquireProgress.stop)r!   r"   r#   r$   r   r0   r3   r@   rG   rK   rO   r^   r`   r   r   r   r   r   ]   s   
	Dc               @   s:   e  Z d  Z d Z d d �  Z d d �  Z d d �  Z d S)	r   zText CD-ROM progress.c             C   sQ   t  j j |  � |  j t d � d � y t d � SWn t k
 rL d SYn Xd S)z,Ask the user to provide a name for the disc.zBPlease provide a name for this Disc, such as 'Debian 2.1r1 Disk 1'F�:N)r   r   �ask_cdrom_namer    r   r_   �KeyboardInterrupt)r   r   r   r   rc   �   s    zCdromProgress.ask_cdrom_namec             C   s0   t  j j |  | | � | r, |  j | d � d S)zSet the current progress.FN)r   r   r'   r    )r   �text�currentr   r   r   r'     s    zCdromProgress.updatec             C   sT   t  j j |  � |  j t d � d � y t �  d k SWn t k
 rO d SYn Xd S)z"Ask the user to change the CD-ROM.z1Please insert a Disc in the drive and press enterFr%   N)r   r   �change_cdromr    r   r_   rd   )r   r   r   r   rg   
  s    zCdromProgress.change_cdromN)r!   r"   r#   r$   rc   r'   rg   r   r   r   r   r   �   s   
)r$   �
__future__r   r7   r   r	   Zapt.progressr   �__all__�version_info�majorZ	raw_inputr_   �intr.   r   �objectr   r   r   r   r   r   r   r   �<module>   s   	�                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        #!/usr/bin/python
"""
The module provides a client to the PackageKit DBus interface. It allows to
perform basic package manipulation tasks in a cross distribution way, e.g.
to search for packages, install packages or codecs.
"""
# Copyright (C) 2008 Canonical Ltd.
# Copyright (C) 2008 Aidan Skinner <aidan@skinner.me.uk>
# Copyright (C) 2008 Martin Pitt <martin.pitt@ubuntu.com>
# Copyright (C) 2008 Tim Lauridsen <timlau@fedoraproject.org>
# Copyright (C) 2008-2009 Sebastian Heinlein <devel@glatzor.de>
#
# Licensed under the GNU General Public License Version 2
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

import locale
import os.path
import shutil
import weakref
import sys

import dbus
import dbus.mainloop.glib
dbus.mainloop.glib.DBusGMainLoop(set_as_default=True)

from gi.repository import GObject, GLib

from . import enums
from . import debconf
import defer
from defer.utils import deferable
from .errors import convert_dbus_exception, TransactionFailed

__all__ = ("AptTransaction", "AptClient", "get_transaction", "get_aptdaemon")


# the default timeout for dbus method calls
_APTDAEMON_DBUS_TIMEOUT = 86400


class AptTransaction(GObject.Object):

    """Represents an aptdaemon transaction.

    .. note:: This class cannot be inherited since it makes use of
              a metaclass.

    .. signal:: allow-unauthenticated -> allow

        The signal is emitted when :attr:`allow_unauthenticated` changed.

        :param allow: If unauthenticated packages are allowed to be installed.

    .. signal:: cancellable-changed -> cancellable

        The signal is emitted when :attr:`cancellable` changed.

        :param cancellable: If the transaction can be cancelled now.

    .. signal:: config-file-conflict -> cur, new

        The signal is emitted when :attr:`config_file_conflict` changed.

        :param cur: The path to the current configuration file.
        :param new: The path to the new configuration file.

    .. signal:: debconf-socket-changed -> path

        The signal is emitted when :attr:`debconf_socket` changed.

        :param path: The path to the socket which will be used to forward
            debconf communication to the user session.

    .. signal:: dependencies-changed -> installs, re-installs, removals, \
                                        purges, upgrades, downgrades, kepts

        The signal is emitted when :attr:`dependencies` changed.

        Most likely after :meth:`simulate()` was called.

        :param installs: List of package which will be installed.
        :param reinstalls: List of package which will be re-installed.
        :param removals: List of package which will be removed,
        :param purges: List of package which will be removed including
            configuration files.
        :param upgrades: List of package which will be upgraded.
        :param downgrades: List of package which will be downgraded to an older
            version.
        :param kepts: List of package which will be skipped from upgrading.

    .. signal:: download-changed -> download

        The signal is emitted when :attr:`download` changed.

        :param download: Download size integer in Bytes.

    .. signal:: error -> error_code, error_details

        The signal is emitted when an error occured.

        :param error_code: The error code enumeration, e.g.
             :data:`aptdaemon.enums.ERROR_NO_CACHE`.
        :param error_details: The error description string.

    .. signal:: finished -> exit_state

        The signal is emitted when the transaction is completed or has
        failed.

        :param exit_state: The exit status enumeration string.

    .. signal:: http-proxy-changed -> uri

        The signal is emitted when :attr:`http_proxy` changed.

        :param uri: The URI of the proxy server, e.g. "http://proxy:8080".

    .. signal:: locale-changed -> locale

        The signal is emitted when :attr:`locale` changed.

        :param locale: The language which should be used for messages,
            eg. "de_DE".

    .. signal:: meta-data-changed -> meta_data

        The signal is emitted when :attr:`meta_data` changed.

        :param meta_data: The latest meta data dictionary.

    .. signal:: medium-required -> name, device

        The signal is emitted when :attr:`required_medium` changed.

        :param name: The name of the volume.
        :param device: The path of the device in which the volume should
            be inserted.

    .. signal:: remove-obsoleted-depends-changed -> remove

        The signal is emitted when :attr:`remove_obsoleted_depends` changed.

        :param remove: If obsolete dependencies should also be removed.

    .. signal:: role-changed -> role

        The signal is emitted when :attr:`role` changed.

        :param role: The new role enum, e.g.
            :data:`~aptdaemon.enums.ROLE_UPDATE_CACHE`.

    .. signal:: space-changed -> space

        The signal is emitted when :attr:`space` changed.
        Most likely after :meth:`simulate()` was called.

        :param space: Required disk space integer in Bytes. Can be negative
            if disk space will be freed.

    .. signal:: packages-changed -> installs, re-installs, removals, \
                                    purges, upgrades, downgrades

        The signal is emitted when :attr:`packages` changed.

        :param installs: List of package which will be installed.
        :param reinstalls: List of package which will be re-installed.
        :param removals: List of package which will be removed,
        :param purges: List of package which will be removed including
            configuration files.
        :param upgrades: List of package which will be upgraded.
        :param downgrades: List of package which will be downgraded to an older
            version.

    .. signal:: paused

        The signal is emitted when the transaction was paused.
        See :attr:`paused` and :sig:`resumed`.

    .. signal:: progress-changed -> progress

        The signal is emitted when :attr:`progress` changed.

        :param progress: The progress integer.

    .. signal:: progress-details-changed -> current_items, total_items, \
                                            currenty_bytes, total_bytes, \
                                            current_cps, eta

        The signal is emitted when detailed information of the progress
        is available.

        :param current_items: The number of already processed items.
        :param total_items: The number of all items.
        :param current_bytes: The number of already downloaded byte.
        :param total_bytes: The number of bytes which have to be downloaded
            totally.
        :param current_cps: The current download speed in bytes per second.
        :param eta: The elapsed time in seconds to accomplish the task.

    .. signal:: progress-download-changed -> uri, short_desc, total_size, \
                                             current_size, msg

        The signal is emitted when progress information about a single
        download is available.

        :param uri: The URI of the file which is downloaded.
        :param status: The status of the downloade, e.g.
            :data:`~aptdaemon.enums.DOWNLOAD_AUTH_FAILED`.
        :param short_desc: A short description of the file.
        :param total_size: The size of the file in Bytes.
        :param current_size: How much of the file in Bytes has already be
            downloaded.
        :param msg: The status or error description.

    .. signal:: resumed

        The signal is emitted when a paused transaction was resumed.
        See :attr:`paused` and :sig:`paused`.

    .. signal:: terminal-changed -> path

        The signal is emitted when :attr:`terminal` changed.

        :param path: The path to the slave end of the controlling terminal
            for the underlying dpkg call.

    .. signal:: terminal-attached-changed -> attached

        The signal is emitted when :attr:`term_attached` changed.

        :param attached: If the controlling terminal can be used.

    .. signal:: unauthenticated-changed -> unauthenticated

        The signal is emitted when :attr:`unauthenticated` changed.

        :param unauthenticated: List of unauthenticated packages.

    .. attribute:: cancellable

        If the transaction can be currently cancelled.

    .. attribute:: config_file_conflict

        If there is a conflict in the configuration file handling during
        an installation this attribute contains a tuple of the path to the
        current and the new temporary configuration file.

        The :meth:`resolve_config_file_conflict()` can be used to
        resolve the conflict and continue the processing of the
        transaction.

    .. attribute:: dependencies

        List of dependencies lists in the following order: packages to
        install, to re-install, to remove, to purge, to upgrade,
        to downgrade and to keep.

        You have to call :meth:`simulate()` to calculate the
        dependencies before the transaction will be executed.

    .. attribute:: download

        The number of Bytes which have to be downloaed.

        You have to call :meth:`simulate()` to calculate the
        download size before the transaction will be executed.

    .. attribute:: error

        In the case of a failed transaction this attribute holds the
        corresponding :exc:`errors.TransactionFailed` instance.

    .. attribute:: error_code

        In the case of a failed transaction this attribute is set to the
        underlying error code, e.g.
        :data:`enums.ERROR_PACKAGE_DOWNLOAD_FAILED`.

    .. attribute:: error_details

        In the case of a failed transaction this attribute contains a
        detailed error message in the language of the transaction.

    .. attribute:: exit

        Contains the exit status enum if the transaction has been completed,
        e.g. :data:`enums.EXIT_SUCCESS` or :data:`enums.EXIT_FAILED`.

    .. attribute:: http_proxy

        The URI to the http proxy server which should be used only for this
        transaction, e.g. "http://proxy:8080". It is recommended to set
        the system wide proxy server instead of setting this attribute
        for every transaction.

        See :meth:`set_http_proxy()`.

    .. attribute:: meta_data

        Dictionary of optional meta data which can be set by client
        applications. See :meth:`set_meta_data()`.

    .. attribute:: packages

       List of package lists which will be explicitly changed in the
       following order: packages to install, to re-install, to remove,
       to purge, to upgrade, to downgrade.

    .. attribute:: paused

        If the transaction is currently paused, e.g. it is required to
        insert a medium to install from.

    .. attribute:: progress

        An integer ranging from 0 to 101 to describe the progress of the
        transaction.

        .. note:: A value of 101 indicates that there cannot be made any
                  assumptions on the progress of the transaction.

    .. attribute:: remove_obsoleted_depends

        If dependencies which have been required by a removed package only
        should be removed, too.

    .. attribute:: required_medium

        If a medium should be inserted to continue the fetch phase of a
        transaction, this attribute contains a tuple of the device path of
        of the drive which should be used and secondly of the name of the
        medium.

        The :func:`provide_medium()` method should be used to notify aptdaemon
        about an inserted medium and to continue processing the transaction.

    .. attribute:: role

        The kind of action which is performed by the transaction, e.g.
        :data:`enums.ROLE_UPGRADE_SYSTEM`.

    .. attribute:: space

        The required disk space in Bytes. Will be negative if space is
        freed.

        You have to call :meth:`simulate()` to calculate the
        download size before the transaction will be executed.

    .. attribute:: status

        The enum of the current status, e.g.
        :data:`enums.STATUS_DOWNLOADING`.

    .. attribute:: status_details

        A string describing the current status of the transaction.

    .. attribute:: tid

        The unique identifier of the transaction. It is also the D-Bus path
        of the corresponding transaction object.

    .. attribute:: term_attached

        If the the package manager can be controlled using the controlling
        terminal specified by :func:`set_terminal()`.

    .. attribute:: unauthenticated

        List of packages which are going to be installed but are not
        downloaded from an authenticated repository.

        You have to call :meth:`simulate()` to calculate the
        dependencies before the transaction will be executed.
    """

    __gsignals__ = {"finished": (GObject.SIGNAL_RUN_FIRST,
                                 GObject.TYPE_NONE,
                                 (GObject.TYPE_STRING,)),
                    "dependencies-changed": (GObject.SIGNAL_RUN_FIRST,
                                             GObject.TYPE_NONE,
                                             (GObject.TYPE_PYOBJECT,
                                              GObject.TYPE_PYOBJECT,
                                              GObject.TYPE_PYOBJECT,
                                              GObject.TYPE_PYOBJECT,
                                              GObject.TYPE_PYOBJECT,
                                              GObject.TYPE_PYOBJECT,
                                              GObject.TYPE_PYOBJECT)),
                    "download-changed": (GObject.SIGNAL_RUN_FIRST,
                                         GObject.TYPE_NONE,
                                         (GObject.TYPE_INT64,)),
                    "space-changed": (GObject.SIGNAL_RUN_FIRST,
                                      GObject.TYPE_NONE,
                                      (GObject.TYPE_INT64,)),
                    "error": (GObject.SIGNAL_RUN_FIRST,
                              GObject.TYPE_NONE,
                              (GObject.TYPE_STRING, GObject.TYPE_STRING)),
                    "role-changed": (GObject.SIGNAL_RUN_FIRST,
                                     GObject.TYPE_NONE,
                                     (GObject.TYPE_STRING,)),
                    "terminal-attached-changed": (GObject.SIGNAL_RUN_FIRST,
                                                  GObject.TYPE_NONE,
                                                  (GObject.TYPE_BOOLEAN,)),
                    "cancellable-changed": (GObject.SIGNAL_RUN_FIRST,
                                            GObject.TYPE_NONE,
                                            (GObject.TYPE_BOOLEAN,)),
                    "meta-data-changed": (GObject.SIGNAL_RUN_FIRST,
                                          GObject.TYPE_NONE,
                                          (GObject.TYPE_PYOBJECT,)),
                    "status-changed": (GObject.SIGNAL_RUN_FIRST,
                                       GObject.TYPE_NONE,
                                       (GObject.TYPE_STRING,)),
                    "status-details-changed": (GObject.SIGNAL_RUN_FIRST,
                                               GObject.TYPE_NONE,
                                               (GObject.TYPE_STRING,)),
                    "progress-changed": (GObject.SIGNAL_RUN_FIRST,
                                         GObject.TYPE_NONE,
                                         (GObject.TYPE_INT,)),
                    "progress-details-changed": (GObject.SIGNAL_RUN_FIRST,
                                                 GObject.TYPE_NONE,
                                                 (GObject.TYPE_INT,
                                                  GObject.TYPE_INT,
                                                  GObject.TYPE_INT64,
                                                  GObject.TYPE_INT64,
                                                  GObject.TYPE_INT,
                                                  GObject.TYPE_INT64)),
                    "progress-download-changed": (GObject.SIGNAL_RUN_FIRST,
                                                  GObject.TYPE_NONE,
                                                  (GObject.TYPE_STRING,
                                                   GObject.TYPE_STRING,
                                                   GObject.TYPE_STRING,
                                                   GObject.TYPE_INT64,
                                                   GObject.TYPE_INT64,
                                                   GObject.TYPE_STRING)),
                    "packages-changed": (GObject.SIGNAL_RUN_FIRST,
                                         GObject.TYPE_NONE,
                                         (GObject.TYPE_PYOBJECT,
                                          GObject.TYPE_PYOBJECT,
                                          GObject.TYPE_PYOBJECT,
                                          GObject.TYPE_PYOBJECT,
                                          GObject.TYPE_PYOBJECT,
                                          GObject.TYPE_PYOBJECT)),
                    "unauthenticated-changed": (GObject.SIGNAL_RUN_FIRST,
                                                GObject.TYPE_NONE,
                                                (GObject.TYPE_PYOBJECT,)),
                    "paused": (GObject.SIGNAL_RUN_FIRST,
                               GObject.TYPE_NONE,
                               ()),
                    "resumed": (GObject.SIGNAL_RUN_FIRST,
                                GObject.TYPE_NONE,
                                ()),
                    "allow-unauthenticated-changed": (GObject.SIGNAL_RUN_FIRST,
                                                      GObject.TYPE_NONE,
                                                      (GObject.TYPE_BOOLEAN,)),
                    "remove-obsoleted-depends-changed": (
                        GObject.SIGNAL_RUN_FIRST,
                        GObject.TYPE_NONE,
                        (GObject.TYPE_BOOLEAN,)),
                    "locale-changed": (GObject.SIGNAL_RUN_FIRST,
                                       GObject.TYPE_NONE,
                                       (GObject.TYPE_STRING,)),
                    "terminal-changed": (GObject.SIGNAL_RUN_FIRST,
                                         GObject.TYPE_NONE,
                                         (GObject.TYPE_STRING,)),
                    "debconf-socket-changed": (GObject.SIGNAL_RUN_FIRST,
                                               GObject.TYPE_NONE,
                                               (GObject.TYPE_STRING,)),
                    "http-proxy-changed": (GObject.SIGNAL_RUN_FIRST,
                                           GObject.TYPE_NONE,
                                           (GObject.TYPE_STRING,)),
                    "medium-required": (GObject.SIGNAL_RUN_FIRST,
                                        GObject.TYPE_NONE,
                                        (GObject.TYPE_STRING,
                                         GObject.TYPE_STRING)),
                    "config-file-conflict": (GObject.SIGNAL_RUN_FIRST,
                                             GObject.TYPE_NONE,
                                             (GObject.TYPE_STRING,
                                              GObject.TYPE_STRING)),
                    }

    _tid_cache = weakref.WeakValueDictionary()

    def __new__(cls, tid, *args, **kwargs):
        """Cache transactions with identical tid."""
        try:
            return AptTransaction._tid_cache[tid]
        except KeyError:
            value = GObject.Object.__new__(cls, tid, *args, **kwargs)
            AptTransaction._tid_cache[tid] = value
            return value

    def __init__(self, tid, bus=None):
        GObject.GObject.__init__(self)
        self.tid = tid
        self.role = enums.ROLE_UNSET
        self.error = None
        self.error_code = None
        self.error_details = None
        self.exit = enums.EXIT_UNFINISHED
        self.cancellable = False
        self.term_attached = False
        self.required_medium = None
        self.config_file_conflict = None
        self.status = None
        self.status_details = ""
        self.progress = 0
        self.paused = False
        self.http_proxy = None
        self.dependencies = [[], [], [], [], [], [], []]
        self.packages = [[], [], [], [], []]
        self.unauthenticated = []
        self.meta_data = {}
        self.remove_obsoleted_depends = False
        self.download = 0
        self.downloads = {}
        self.space = 0
        self.locale = ""
        self._method = None
        self._args = []
        self._debconf_helper = None
        # Connect the signal handlers to the DBus iface
        if not bus:
            bus = dbus.SystemBus()
        self._proxy = bus.get_object("org.debian.apt", tid)
        self._iface = dbus.Interface(self._proxy, "org.debian.apt.transaction")
        # Watch for a crashed daemon which orphaned the dbus object
        self._owner_watcher = bus.watch_name_owner("org.debian.apt",
                                                   self._on_name_owner_changed)
        # main signals
        self._signal_matcher = \
            self._iface.connect_to_signal("PropertyChanged",
                                          self._on_property_changed)

    def _on_name_owner_changed(self, connection):
        """Fail the transaction if the daemon died."""
        if connection == "" and self.exit == enums.EXIT_UNFINISHED:
            self._on_property_changed("Error", (enums.ERROR_DAEMON_DIED,
                                                "It seems that the daemon "
                                                "died."))
            self._on_property_changed("Cancellable", False)
            self._on_property_changed("TerminalAttached", False)
            self._on_property_changed("ExitState", enums.EXIT_FAILED)

    def _on_property_changed(self, property_name, value):
        """Callback for the PropertyChanged signal."""
        if property_name == "TerminalAttached":
            self.term_attached = value
            self.emit("terminal-attached-changed", value)
        elif property_name == "Cancellable":
            self.cancellable = value
            self.emit("cancellable-changed", value)
        elif property_name == "DebconfSocket":
            self.emit("debconf-socket-changed", value)
        elif property_name == "RemoveObsoletedDepends":
            self.emit("remove-obsoleted-depends-changed", value)
            self.remove_obsoleted_depends = value
        elif property_name == "AllowUnauthenticated":
            self.emit("allow-unauthenticated-changed", value)
        elif property_name == "Terminal":
            self.emit("terminal-changed", value)
        elif property_name == "Dependencies":
            self.dependencies = value
            self.emit("dependencies-changed", *value)
        elif property_name == "Packages":
            self.packages = value
            self.emit("packages-changed", *value)
        elif property_name == "Unauthenticated":
            self.unauthenticated = value
            self.emit("unauthenticated-changed", value)
        elif property_name == "Locale":
            self.locale = value
            self.emit("locale-changed", value)
        elif property_name == "Role":
            self.role = value
            self.emit("role-changed", value)
        elif property_name == "Status":
            self.status = value
            self.emit("status-changed", value)
        elif property_name == "StatusDetails":
            self.status_details = value
            self.emit("status-details-changed", value)
        elif property_name == "ProgressDownload":
            uri, status, desc, size, download, msg = value
            if uri:
                self.downloads[uri] = (status, desc, size, download, msg)
                self.emit("progress-download-changed", *value)
        elif property_name == "Progress":
            self.progress = value
            self.emit("progress-changed", value)
        elif property_name == "ConfigFileConflict":
            self.config_file_conflict = value
            if value != ("", ""):
                self.emit("config-file-conflict", *value)
        elif property_name == "MetaData":
            self.meta_data = value
            self.emit("meta-data-changed", value)
        elif property_name == "Paused":
            self.paused = value
            if value:
                self.emit("paused")
            else:
                self.emit("resumed")
        elif property_name == "RequiredMedium":
            self.required_medium = value
            if value != ("", ""):
                self.emit("medium-required", *value)
        elif property_name == "ProgressDetails":
            self.emit("progress-details-changed", *value)
        elif property_name == "Download":
            self.download = value
            self.emit("download-changed", value)
        elif property_name == "Space":
            self.space = value
            self.emit("space-changed", value)
        elif property_name == "HttpProxy":
            self.http_proxy = value
            self.emit("http-proxy-changed", value)
        elif property_name == "Error":
            self.error_code, self.error_details = value
            if self.error_code != "":
                self.error = TransactionFailed(self.error_code,
                                               self.error_details)
                self.emit("error", *value)
        elif property_name == "ExitState":
            if value != enums.EXIT_UNFINISHED and value != self.exit:
                self.exit = value
                if self._debconf_helper:
                    self._debconf_helper.stop()
                self._disconnect_from_dbus()
                # Finally sync all properties a last time. We cannot ensure
                # that the ExitState signal is the last one, so some
                # other PropertyChanged signals could be lost, see LP#747172
                self.sync(reply_handler=self._on_final_sync_done,
                          error_handler=self._on_final_sync_done)

    def _on_final_sync_done(self, data):
        self._owner_watcher.cancel()
        self.emit("finished", self.exit)

    @deferable
    @convert_dbus_exception
    def sync(self, reply_handler=None, error_handler=None):
        """Sync the properties of the transaction with the daemon.

        This method is called automatically on the creation of the
        AptTransaction instance.

        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: dbus.DBusException
        """
        def sync_properties(prop_dict):
            for property_name, value in prop_dict.items():
                self._on_property_changed(property_name, value)
            if reply_handler:
                reply_handler(self)
        if reply_handler and error_handler:
            self._proxy.GetAll("org.debian.apt.transaction",
                               dbus_interface=dbus.PROPERTIES_IFACE,
                               reply_handler=sync_properties,
                               error_handler=error_handler)
        else:
            properties = self._proxy.GetAll(
                "org.debian.apt.transaction",
                dbus_interface=dbus.PROPERTIES_IFACE)
            sync_properties(properties)

    @deferable
    @convert_dbus_exception
    def run_after(self, transaction, reply_handler=None, error_handler=None):
        """Chain this transaction after the given one. The transaction will
        fail if the previous one fails.

        To start processing of the chain you have to call :meth:`run()`
        of the first transaction. The others will be queued after it
        automatically.

        :param transaction: An AptTransaction on which this one depends.
        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: dbus.DBusException
         """
        try:
            return self._iface.RunAfter(transaction.tid,
                                        error_handler=error_handler,
                                        reply_handler=reply_handler,
                                        timeout=_APTDAEMON_DBUS_TIMEOUT)
        except Exception as error:
            if error_handler:
                error_handler(error)
            else:
                raise

    @deferable
    @convert_dbus_exception
    def run(self, reply_handler=None, error_handler=None):
        """Queue the transaction for processing.

        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: aptdaemon.errors.TransactionFailed, dbus.DBusException
        """
        try:
            return self._iface.Run(error_handler=error_handler,
                                   reply_handler=reply_handler,
                                   timeout=_APTDAEMON_DBUS_TIMEOUT)
        except Exception as error:
            if error_handler:
                error_handler(error)
            else:
                raise

    @deferable
    @convert_dbus_exception
    def simulate(self, reply_handler=None, error_handler=None):
        """Simulate the transaction to calculate the dependencies, the
        required download size and the required disk space.

        The corresponding properties of the AptTransaction will be updated.

        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: aptdaemon.errors.TransactionFailed, dbus.DBusException
        """
        self._iface.Simulate(reply_handler=reply_handler,
                             error_handler=error_handler)

    @deferable
    @convert_dbus_exception
    def cancel(self, reply_handler=None, error_handler=None):
        """Cancel the running transaction.

        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: aptdaemon.errors.NotAuthorizedError, dbus.DBusException
        """
        self._iface.Cancel(reply_handler=reply_handler,
                           error_handler=error_handler)

    @deferable
    @convert_dbus_exception
    def set_http_proxy(self, proxy, reply_handler=None, error_handler=None):
        """Use the given http proxy for downloading packages in this
        transaction.

        :param proxy: The URL of the proxy server, e.g. "http://proxy:8080"
        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: aptdaemon.errors.NotAuthorizedError, dbus.DBusException
            aptdaemon.errors.ForeignTransaction,
        """
        if reply_handler:
            _reply_handler = lambda: reply_handler(self)
        else:
            _reply_handler = None
        self._proxy.Set("org.debian.apt.transaction", "HttpProxy", proxy,
                        dbus_interface=dbus.PROPERTIES_IFACE,
                        reply_handler=_reply_handler,
                        error_handler=error_handler)

    @deferable
    @convert_dbus_exception
    def set_remove_obsoleted_depends(self, remove_obsoleted_depends,
                                     reply_handler=None, error_handler=None):
        """Include no longer required dependencies which have been installed
        automatically when removing packages.

        :param remove_obsoleted_depends: If obsolete dependencies should be
            also removed.
        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: aptdaemon.errors.ForeignTransaction, dbus.DBusException
        """
        if reply_handler:
            _reply_handler = lambda: reply_handler(self)
        else:
            _reply_handler = None
        self._proxy.Set("org.debian.apt.transaction",
                        "RemoveObsoletedDepends", remove_obsoleted_depends,
                        dbus_interface=dbus.PROPERTIES_IFACE,
                        reply_handler=_reply_handler,
                        error_handler=error_handler)

    @deferable
    @convert_dbus_exception
    def set_allow_unauthenticated(self, allow_unauthenticated,
                                  reply_handler=None, error_handler=None):
        """Allow to install unauthenticated packages.

        Unauthenticated packages are from the repository of a vendor whose
        key hasn't been installed. By default this is not allowed.

        :param allow_unauthenticated: If unauthenticated packages can be
            installed.
        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: aptdaemon.errors.ForeignTransaction, dbus.DBusException
        """
        if reply_handler:
            _reply_handler = lambda: reply_handler(self)
        else:
            _reply_handler = None
        self._proxy.Set("org.debian.apt.transaction",
                        "AllowUnauthenticated", allow_unauthenticated,
                        dbus_interface=dbus.PROPERTIES_IFACE,
                        reply_handler=_reply_handler,
                        error_handler=error_handler)

    @deferable
    @convert_dbus_exception
    def set_debconf_frontend(self, frontend, reply_handler=None,
                             error_handler=None):
        """Setup a debconf frontend to answer questions of the maintainer
        scripts.

        Debian allows packages to interact with the user during installation,
        configuration and removal phase via debconf. Aptdaemon forwards the
        communication to a debconf instance running as the user of the
        client application.

        :param frontend: The name of the debconf frontend which should be
            launched, e.g. gnome or kde. Defaults to gnome.
        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: aptdaemon.errors.ForeignTransaction, dbus.DBusException
         """
        if reply_handler:
            _reply_handler = lambda: reply_handler(self)
        else:
            _reply_handler = None
        self._debconf_helper = debconf.DebconfProxy(frontend)
        self._proxy.Set("org.debian.apt.transaction", "DebconfSocket",
                        self._debconf_helper.socket_path,
                        dbus_interface=dbus.PROPERTIES_IFACE,
                        reply_handler=_reply_handler,
                        error_handler=error_handler)
        self._debconf_helper.start()

    @deferable
    @convert_dbus_exception
    def set_meta_data(self, **kwargs):
        """Store additional meta information of the transaction in the
        MetaData property of the transaction.

        The method accepts key=value pairs. The key has to be prefixed with
        an underscore separated identifier of the client application.

        In the following example Software-Center sets an application name
        and icon:

        >>> Transaction.set_meta_data(sc_icon="shiny", sc_app="xterm")

        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: aptdaemon.errors.ForeignTransaction, dbus.DBusException
        """
        reply_handler = kwargs.pop("reply_handler", None)
        error_handler = kwargs.pop("error_handler", None)
        if reply_handler:
            _reply_handler = lambda: reply_handler(self)
        else:
            _reply_handler = None
        meta_data = dbus.Dictionary(kwargs, signature="sv")
        self._proxy.Set("org.debian.apt.transaction", "MetaData", meta_data,
                        dbus_interface=dbus.PROPERTIES_IFACE,
                        reply_handler=_reply_handler,
                        error_handler=error_handler)

    @deferable
    @convert_dbus_exception
    def set_terminal(self, ttyname, reply_handler=None, error_handler=None):
        """Allow to set a controlling terminal for the underlying dpkg call.

        See the source code of gtk3widgets.AptTerminal or console.ConsoleClient
        as example.

        >>> master, slave = pty.openpty()
        >>> transaction.set_terminal(os.ttyname(slave))

        :param terminal: The slave end of a tty.
        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: aptdaemon.errors.ForeignTransaction, dbus.DBusException
        """
        if reply_handler:
            _reply_handler = lambda: reply_handler(self)
        else:
            _reply_handler = None
        self._proxy.Set("org.debian.apt.transaction", "Terminal", ttyname,
                        dbus_interface=dbus.PROPERTIES_IFACE,
                        reply_handler=_reply_handler,
                        error_handler=error_handler)

    def _disconnect_from_dbus(self):
        """Stop monitoring the progress of the transaction."""
        if hasattr(self, "_signal_matcher"):
            self._signal_matcher.remove()
            del self._signal_matcher

    @deferable
    @convert_dbus_exception
    def set_locale(self, locale_name, reply_handler=None, error_handler=None):
        """Set the language for status and error messages.

        :param locale: The locale name, e.g. de_DE@UTF-8.
        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: aptdaemon.errors.ForeignTransaction, dbus.DBusException
        """
        if reply_handler:
            _reply_handler = lambda: reply_handler(self)
        else:
            _reply_handler = None
        self._proxy.Set("org.debian.apt.transaction", "Locale", locale_name,
                        dbus_interface=dbus.PROPERTIES_IFACE,
                        reply_handler=_reply_handler,
                        error_handler=error_handler)

    @deferable
    @convert_dbus_exception
    def provide_medium(self, medium, reply_handler=None, error_handler=None):
        """Continue a paused transaction which waits for a medium to install
        from.

        :param medium: The name of the provided medium.
        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: aptdaemon.errors.ForeignTransaction, dbus.DBusException
         """
        self._iface.ProvideMedium(medium, reply_handler=reply_handler,
                                  error_handler=error_handler)

    @deferable
    @convert_dbus_exception
    def resolve_config_file_conflict(self, config, answer, reply_handler=None,
                                     error_handler=None):
        """Continue a paused transaction which waits for the resolution of a
        configuration file conflict.

        :param config: The path to the current version of the configuration
            file.
        :param answer: Can be either "keep" or "replace".
        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: aptdaemon.errors.ForeignTransaction, dbus.DBusException
         """
        self._iface.ResolveConfigFileConflict(config, answer,
                                              reply_handler=reply_handler,
                                              error_handler=error_handler)


class AptClient(object):

    """Provides a complete client for aptdaemon."""

    def __init__(self, bus=None):
        """Return a new AptClient instance."""
        if bus:
            self.bus = bus
        else:
            self.bus = dbus.SystemBus()
        # Catch an invalid locale
        try:
            self._locale = "%s.%s" % locale.getdefaultlocale()
        except ValueError:
            self._locale = None
        self.terminal = None

    @convert_dbus_exception
    def get_trusted_vendor_keys(self, reply_handler=None, error_handler=None):
        """Get the list of the installed vendor keys which are used to
        authenticate packages.

        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: dbus.DBusException

        :returns: Fingerprints of all installed vendor keys.
        """
        daemon = get_aptdaemon(self.bus)
        keys = daemon.GetTrustedVendorKeys(reply_handler=reply_handler,
                                           error_handler=error_handler)
        return keys

    @deferable
    @convert_dbus_exception
    def upgrade_system(self, safe_mode=True, wait=False, reply_handler=None,
                       error_handler=None):
        """Create a new transaction to apply all avaibale upgrades.

        :param safe_mode: If True only already installed packages will be
            updated. Updates which require to remove installed packages or to
            install additional packages will be skipped.

        :param wait: if True run the transaction immediately and return its
            exit state instead of the transaction itself.
        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a
            defer.Deferred. This options is only available as a keyword.

        :raises: dbus.DBusException

        :returns: An AptTransaction instance.
        """
        return self._run_transaction("UpgradeSystem", [safe_mode],
                                     wait, reply_handler, error_handler)

    @deferable
    @convert_dbus_exception
    def install_packages(self, package_names, wait=False, reply_handler=None,
                         error_handler=None):
        """Create a new transaction to install the given packages from the
        reporitories.

        The version number and target release of the packages can be specified
        using the traditional apt-get syntax, e.g. "xterm=281.1" to force
        installing the version 281.1 of xterm or "xterm/experimental" to
        force installing xterm from the experimental release.

        :param package_names: List of names of the packages which should be
            installed.

        :param wait: if True run the transaction immediately and return its
            exit state instead of the transaction itself.
        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a
            defer.Deferred. This options is only available as a keyword.

        :raises: dbus.DBusException

        :returns: An AptTransaction instance.
        """
        return self._run_transaction("InstallPackages", [package_names],
                                     wait, reply_handler, error_handler)

    @deferable
    @convert_dbus_exception
    def add_repository(self, src_type, uri, dist, comps=None, comment="",
                       sourcesfile="", wait=False, reply_handler=None,
                       error_handler=None):
        """Create a new transaction to enable a repository.

        :param src_type: The type of the repository (deb, deb-src).
        :param uri: The main repository URI
           (e.g. http://archive.ubuntu.com/ubuntu)
        :param dist: The distribution to use (e.g. stable or lenny-backports).
        :param comps: List of components (e.g. main, restricted).
        :param comment: A comment which should be added to the sources.list.
        :param sourcesfile: (Optoinal) filename in sources.list.d.

        :param wait: if True run the transaction immediately and return
            its exit state instead of the transaction itself.
        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: dbus.DBusException

        :returns: An AptTransaction instance.
        """
        # dbus can not deal with empty lists and will error
        if not comps:
            comps = [""]
        return self._run_transaction("AddRepository",
                                     [src_type, uri, dist, comps, comment,
                                      sourcesfile],
                                     wait, reply_handler, error_handler)

    @deferable
    @convert_dbus_exception
    def add_vendor_key_from_keyserver(self, keyid, keyserver, wait=False,
                                      reply_handler=None, error_handler=None):
        """Create a new transaction to download and install the key of a
        software vendor. The key is used to authenticate packages of the
        vendor.

        :param keyid: The id of the GnuPG key (e.g. 0x0EB12F05)
        :param keyserver: The server to get the key from (e.g.
            keyserver.ubuntu.com)

        :param wait: if True run the transaction immediately and return its
            exit state instead of the transaction itself.
        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: dbus.DBusException

        :returns: An AptTransaction instance.
        """
        return self._run_transaction("AddVendorKeyFromKeyserver",
                                     [keyid, keyserver],
                                     wait, reply_handler, error_handler)

    @deferable
    @convert_dbus_exception
    def add_vendor_key_from_file(self, path, wait=False, reply_handler=None,
                                 error_handler=None):
        """Create a new transaction to install the key file of a software
        vendor. The key is used to authenticate packages of the vendor.

        :param path: The absolute path to the key file.

        :param wait: if True run the transaction immediately and return its
            exit state instead of the transaction itself.
        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: dbus.DBusException

        :returns: An AptTransaction instance.
        """
        return self._run_transaction("AddVendorKeyFromFile", [path],
                                     wait, reply_handler, error_handler)

    @deferable
    @convert_dbus_exception
    def remove_vendor_key(self, fingerprint, wait=False, reply_handler=None,
                          error_handler=None):
        """Create a new transaction to remove the key of a software vendor
        from the list of trusted ones.

        The key is used to authenticate the origin of packages.

        :param fingerprint: The fingerprint of the key.

        :param wait: if True run the transaction immediately and return its
            exit state instead of the transaction itself.
        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: dbus.DBusException

        :returns: An AptTransaction instance.
        """
        return self._run_transaction("RemoveVendorKey", [fingerprint],
                                     wait, reply_handler, error_handler)

    @deferable
    @convert_dbus_exception
    def install_file(self, path, force=False, wait=False, reply_handler=None,
                     error_handler=None):
        """Create a new transaction to install a local package file.

        :param path: The absolute path to the .deb-file.
        :param force: Force the installation of a .deb-file even if it
            violates the quality standard defined in the packaging policy.

        :param wait: if True run the transaction immediately and return its
            exit state instead of the transaction itself.
        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: dbus.DBusException

        :returns: An AptTransaction instance.
        """
        # Root is not allowed to access FUSE file systems. So copy files
        # to the local system.
        # FIXME: the locally cached one should be removed afterwards
        home = os.getenv("HOME", None)
        if home and path.startswith(os.path.join(home, ".gvfs")):
            shutil.copy(path, "/tmp")
            path = os.path.join("/tmp", os.path.basename(path))
        return self._run_transaction("InstallFile", [path, force],
                                     wait, reply_handler, error_handler)

    @deferable
    @convert_dbus_exception
    def upgrade_packages(self, package_names, wait=False, reply_handler=None,
                         error_handler=None):
        """Create a new transaction to upgrade installed packages.

        The version number and target release of the packages can be specified
        using the traditional apt-get syntax, e.g. "xterm=281.1" to force
        installing the version 281.1 of xterm or "xterm/experimental" to
        force installing xterm from the experimental release.

        :param package_names: The list of package which should be upgraded.

        :param wait: if True run the transaction immediately and return its
            exit state instead of the transaction itself.
        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: dbus.DBusException

        :returns: An AptTransaction instance.
        """
        return self._run_transaction("UpgradePackages", [package_names],
                                     wait, reply_handler, error_handler)

    @deferable
    @convert_dbus_exception
    def remove_packages(self, package_names, wait=False,
                        reply_handler=None, error_handler=None):
        """Create a new transaction to remove installed packages.

        :param package_names: The list of packages which should be removed.

        :param wait: if True run the transaction immediately and return its
            exit state instead of the transaction itself.
        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: dbus.DBusException

        :returns: An AptTransaction instance.
        """
        return self._run_transaction("RemovePackages", [package_names],
                                     wait, reply_handler, error_handler)

    @deferable
    @convert_dbus_exception
    def commit_packages(self, install, reinstall, remove, purge, upgrade,
                        downgrade, wait=False, reply_handler=None,
                        error_handler=None):
        """Create a new transaction to perform a complex package management
        task which allows to install, remove, upgrade or downgrade several
        packages at the same time.

        The version number and target release of the packages can be specified
        using the traditional apt-get syntax, e.g. "xterm=281.1" to force
        installing the version 281.1 of xterm or "xterm/experimental" to
        force installing xterm from the experimental release.

        :param install: List of packages to install.
        :param reinstall: List of packages to re-install.
        :param remove: List of packages to remove.
        :param purge: List of packages to purge.
        :param upgrade: List of packages to upgrade.
        :param downgrade: List of packages to downgrade. The version of the
            package has to be appended to the name separated by a "=", e.g.
            "xterm=272-1".

        :param wait: if True run the transaction immediately and return its
            exit state instead of the transaction itself.
        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: dbus.DBusException

        :returns: An AptTransaction instance.
        """
        def check_empty_list(lst):
            if not lst:
                return [""]
            else:
                return lst
        pkgs = [check_empty_list(lst) for lst in [install, reinstall, remove,
                                                  purge, upgrade, downgrade]]
        return self._run_transaction("CommitPackages", pkgs,
                                     wait, reply_handler, error_handler)

    @deferable
    @convert_dbus_exception
    def fix_broken_depends(self, wait=False, reply_handler=None,
                           error_handler=None):
        """Create a new transaction to fix unsatisfied dependencies of
        already installed packages.

        Corresponds to the ``apt-get -f install`` call.

        :param wait: if True run the transaction immediately and return its
            exit state instead of the transaction itself.
        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: dbus.DBusException

        :returns: An AptTransaction instance.
        """
        return self._run_transaction("FixBrokenDepends", [],
                                     wait, reply_handler, error_handler)

    @deferable
    @convert_dbus_exception
    def reconfigure(self, packages, priority="default",
                    wait=False, reply_handler=None, error_handler=None):
        """Create a new transaction to reconfigure already installed packages.

        Corresponds to the ``dpkg-reconfigure`` call.

        :param packages: List of package names which should be reconfigured.
        :param priority: The minimum priority of question that will be
            displayed.

        :param wait: if True run the transaction immediately and return its
            exit state instead of the transaction itself.
        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: dbus.DBusException

        :returns: An AptTransaction instance.
        """
        return self._run_transaction("Reconfigure", [packages, priority], wait,
                                     reply_handler, error_handler)

    @deferable
    @convert_dbus_exception
    def fix_incomplete_install(self, wait=False, reply_handler=None,
                               error_handler=None):
        """Create a new transaction to complete a previous interrupted
        installation.

        Corresponds to the ``dpkg --confgiure -a`` call.

        :param wait: if True run the transaction immediately and return its
            exit state instead of the transaction itself.
        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: dbus.DBusException

        :returns: An AptTransaction instance.
        """
        return self._run_transaction("FixIncompleteInstall", [], wait,
                                     reply_handler, error_handler)

    @deferable
    @convert_dbus_exception
    def update_cache(self, sources_list=None, wait=False,
                     reply_handler=None, error_handler=None):
        """Create a new transaction to update the package cache.

        The repositories will be queried for installable packages.

        :param sources_list: Path to a sources.list which contains repositories
            that should be updated only. The other repositories will
            be ignored in this case. Can be either the file name of a snippet
            in /etc/apt/sources.list.d or an absolute path.

        :param wait: if True run the transaction immediately and return its
            exit state instead of the transaction itself.
        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: dbus.DBusException

        :returns: An AptTransaction instance.
        """
        if sources_list:
            return self._run_transaction("UpdateCachePartially",
                                         [sources_list], wait,
                                         reply_handler, error_handler)
        else:
            return self._run_transaction("UpdateCache", [], wait,
                                         reply_handler, error_handler)

    @deferable
    @convert_dbus_exception
    def enable_distro_component(self, component, wait=False,
                                reply_handler=None, error_handler=None):
        """Create a new transaction to enable the component of the
        distribution repository.

        :param component: The name of the component, e.g. main or universe.

        :param wait: if True run the transaction immediately and return its
            exit state instead of the transaction itself.
        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: dbus.DBusException

        :returns: An AptTransaction instance.
        """
        return self._run_transaction("EnableDistroComponent", [component],
                                     wait, reply_handler, error_handler)

    @deferable
    @convert_dbus_exception
    def clean(self, wait=False, reply_handler=None, error_handler=None):
        """Remove all downloaded files.

        :param wait: if True run the transaction immediately and return its
            exit state instead of the transaction itself.
        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: dbus.DBusException

        :returns: An AptTransaction instance.
        """
        return self._run_transaction("Clean", [], wait, reply_handler,
                                     error_handler)

    @deferable
    @convert_dbus_exception
    def add_license_key(self, pkg_name, json_token, server_name, wait=False,
                        reply_handler=None, error_handler=None):
        """Install a license key to use a piece of proprietary software.

        :param pkg_name: The package which requires the license
        :param json_token: The oauth token in json format
        :param server_name: The server name (ubuntu-procduction,
            ubuntu-staging)

        :param wait: if True run the transaction immediately and return its
            exit state instead of the transaction itself.
        :param reply_handler: Callback function. If specified in combination
            with error_handler the method will be called asynchrounsouly.
        :param error_handler: Errback function. In case of an error the given
            callback gets the corresponding exception instance.
        :param defer: Run the method asynchrounsly and return a defer.Deferred.
            This options is only available as a keyword.

        :raises: dbus.DBusException

        :returns: An AptTransaction instance.
        """
        return self._run_transaction("AddLicenseKey",
                                     [pkg_name, json_token, server_name],
                                     wait, reply_handler,
                                     error_handler)

    def _run_transaction(self, method_name, args, wait, reply_handler,
                         error_handler):
        async = reply_handler and error_handler
        try:
            deferred = self._run_transaction_helper(method_name, args, wait,
                                                    async)
        except Exception as error:
            if async:
                error_handler(error)
                return
            else:
                raise
        if async:
            def on_error(error):
                """Convert the DeferredException to a normal exception."""
                try:
                    error.raise_exception()
                except Exception as error:
                    error_handler(error)
            deferred.add_callbacks(reply_handler)
            deferred.add_errback(on_error)
            return deferred
        else:
            # Iterate on the main loop - we cannot use a sub loop here,
            # since the D-Bus python bindings only work on the main loop
            context = GLib.main_context_default()
            while not hasattr(deferred, "result"):
                context.iteration(True)
            # If there has been an error in the helper raise it
            if isinstance(deferred.result, defer.DeferredException):
                deferred.result.raise_exception()
            trans = deferred.result
            if trans.error:
                raise trans.error
            if wait:
                # Wait until the transaction is complete and the properties
                # of the transaction have been updated
                while trans.exit == enums.EXIT_UNFINISHED:
                    context.iteration(True)
                return trans.exit
            else:
                return trans

    @defer.inline_callbacks
    def _run_transaction_helper(self, method_name, args, wait, async):
        daemon = get_aptdaemon(self.bus)
        dbus_method = daemon.get_dbus_method(method_name)
        if async:
            deferred = defer.Deferred()
            dbus_method(reply_handler=deferred.callback,
                        error_handler=deferred.errback, *args,
                        timeout=_APTDAEMON_DBUS_TIMEOUT)
            tid = yield deferred
        else:
            tid = dbus_method(*args, timeout=_APTDAEMON_DBUS_TIMEOUT)
        trans = AptTransaction(tid, self.bus)
        if self._locale:
            yield trans.set_locale(self._locale)
        if self.terminal:
            yield trans.set_terminal(self.terminal)
        yield trans.sync()
        if wait and async:
            deferred_wait = defer.Deferred()
            sig = trans.connect("finished",
                                lambda trans, exit:
                                (exit != enums.EXIT_UNFINISHED and
                                 deferred_wait.callback(exit)))
            yield trans.run()
            yield deferred_wait
            GLib.source_remove(sig)
            defer.return_value(trans.exit)
        elif wait:
            yield trans.run()
        defer.return_value(trans)


@deferable
@convert_dbus_exception
def get_transaction(tid, bus=None, reply_handler=None, error_handler=None):
    """Get an existing transaction by its identifier.

    :param tid: The identifer and D-Bus path of the transaction
        e.g. /org/debian/apt/transaction/78904e5f9fa34098879e768032789109
    :param bus: Optionally the D-Bus on which aptdaemon listens. Defaults
        to the system bus.

    :param reply_handler: Callback function. If specified in combination
        with error_handler the method will be called asynchrounsouly.
    :param error_handler: Errback function. In case of an error the given
        callback gets the corresponding exception instance.
    :param defer: Run the method asynchrounsly and return a defer.Deferred.
        This options is only available as a keyword.

    :raises: dbus.DBusException

    :returns: An AptTransaction instance.
    """
    if not bus:
        bus = dbus.SystemBus()
    trans = AptTransaction(tid, bus)
    if error_handler and reply_handler:
        trans.sync(reply_handler=reply_handler, error_handler=error_handler)
    else:
        trans.sync()
        return trans


def get_size_string(bytes):
    """Returns a human friendly string for a given byte size.

    Note: The bytes are skipped from the returned unit: 1024 returns 1K
    """
    for unit in ["", "K", "M", "G"]:
        if bytes < 1024.0:
            return "%3.1f%s" % (bytes, unit)
        bytes /= 1024.0
    return "%3.1f%s" % (bytes, "T")


def get_aptdaemon(bus=None):
    """Get the daemon D-Bus interface.

    :param bus: Optionally the D-Bus on which aptdaemon listens. Defaults
        to the system bus.

    :raises: dbus.DBusException

    :returns: An dbus.Interface instance.
    """
    if not bus:
        bus = dbus.SystemBus()
    return dbus.Interface(bus.get_object("org.debian.apt",
                                         "/org/debian/apt",
                                         False),
                          "org.debian.apt")

# vim:ts=4:sw=4:et
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               """Handling configuration files."""
# Copyright (C) 2010 Sebastian Heinlein <sevel@glatzor.de>
#
# Licensed under the GNU General Public License Version 2
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

__author__ = "Sebastian Heinlein <devel@glatzor.de>"

__all__ = ("ConfigWriter",)

import logging
import os

import apt_pkg

log = logging.getLogger("AptDaemon.ConfigWriter")


class Value(object):

    """Represents a value with position information.

    .. attribute:: string
        The value string.

    .. attribute:: line
        The line number of the configuration file in which the value is set.

    .. attribute:: start
        The position in the line at which the value starts.

    .. attribute:: end
        The position in the line at which the value ends.

    .. attribute:: quotes
        The outer qoutes of the value: ' or "
    """

    def __init__(self, line, start, quotes):
        self.string = ""
        self.start = start
        self.end = None
        self.line = line
        self.quotes = quotes

    def __cmp__(self, other):
        return self.string == other

    def __repr__(self):
        return "Value: '%s' (line %s: %s to %s)" % (self.string, self.line,
                                                    self.start, self.end)


class ConfigWriter(object):

    """Modifies apt configuration files."""

    def parse(self, lines):
        """Parse an ISC based apt configuration.

        :param lines: The list of lines of a configuration file.

        :returns: Dictionary of key, values found in the parsed configuration.
        """
        options = {}
        in_comment = False
        in_value = False
        prev_char = None
        option = []
        value = None
        option_name = ""
        value_list = []
        in_brackets = True
        level = 0
        for line_no, line in enumerate(lines):
            for char_no, char in enumerate(line):
                if not in_comment and char == "*" and prev_char == "/":
                    in_comment = True
                    prev_char = ""
                    continue
                elif in_comment and char == "/" and prev_char == "*":
                    # A multiline comment was closed
                    in_comment = False
                    prev_char = ""
                    option_name = option_name[:-1]
                    continue
                elif in_comment:
                    # We ignore the content of multiline comments
                    pass
                elif not in_value and ((char == "/" and prev_char == "/") or
                                       char == "#"):
                    # In the case of a line comment continue processing
                    # the next line
                    prev_char = ""
                    option_name = option_name[:-1]
                    break
                elif char in "'\"":
                    if in_value and value.quotes == char:
                        value.end = char_no
                        in_value = not in_value
                    elif not value:
                        value = Value(line_no, char_no, char)
                        in_value = not in_value
                    else:
                        value.string += char
                elif in_value:
                    value.string += char
                elif option_name and char == ":" and prev_char == ":":
                    option.append(option_name[:-1])
                    option_name = ""
                elif char.isalpha() or char in "/-:._+":
                    option_name += char.lower()
                elif char == ";":
                    if in_brackets:
                        value_list.append(value)
                        value = None
                        continue
                    if value_list:
                        log.debug("Found %s \"%s\"", "::".join(option),
                                  value_list)
                        options["::".join(option)] = value_list
                        value_list = []
                    elif value:
                        log.debug("Found %s \"%s\"", "::".join(option), value)
                        options["::".join(option)] = value
                    else:
                        log.debug("Skipping empty key %s", "::".join(option))
                    value = None
                    if level > 0:
                        option.pop()
                    else:
                        option = []
                elif char == "}":
                    level -= 1
                    in_brackets = False
                elif char == "{":
                    level += 1
                    if option_name:
                        option.append(option_name)
                        option_name = ""
                    in_brackets = True
                elif char in "\t\n ":
                    if option_name:
                        option.append(option_name)
                        option_name = ""
                        in_brackets = False
                else:
                    raise ValueError("Unknown char '%s' in line: '%s'" %
                                     (char, line))
                prev_char = char
        return options

    def set_value(self, option, value, defaultfile):
        """Change the value of an option in the configuration.

        :param option: The name of the option, e.g.
            'apt::periodic::AutoCleanInterval'.
        :param value: The value of the option. Will be converted to string.
        :param defaultfile: The filename of the ``/etc/apt/apt.conf.d``
            configuration snippet in which the option should be set.
            If the value is overriden by a later configuration file snippet
            it will be disabled in the corresponding configuration file.
        """
        # FIXME: Support value lists
        # Convert the value to string
        if value is True:
            value = "true"
        elif value is False:
            value = "false"
        else:
            value = str(value)
        # Check all configuration file snippets
        etc_parts = os.path.join(apt_pkg.config.find_dir("Dir::Etc"),
                                 apt_pkg.config.find_dir("Dir::Etc::Parts"))
        for filename in os.listdir(etc_parts):
            if filename < defaultfile:
                continue
            with open(os.path.join(etc_parts, filename)) as fd:
                lines = fd.readlines()
            config = self.parse(lines)
            try:
                val = config[option.lower()]
            except KeyError:
                if filename == defaultfile:
                    lines.append("%s '%s';\n" % (option, value))
                else:
                    continue
            else:
                # Check if the value needs to be changed at all
                if ((value == "true" and
                        val.string.lower() in ["yes", "with", "on",
                                               "enable"]) or
                        (value == "false" and
                         val.string.lower() in ["no", "without", "off",
                                                "disable"]) or
                        (str(value) == val.string)):
                    continue
                if filename == defaultfile:
                    line = lines[val.line]
                    new_line = line[:val.start + 1]
                    new_line += value
                    new_line += line[val.end:]
                    lines[val.line] = new_line
                else:
                    # Comment out existing values instead in non default
                    # configuration files
                    # FIXME Quite dangerous for brackets
                    lines[val.line] = "// %s" % lines[val.line]
            with open(os.path.join(etc_parts, filename), "w") as fd:
                log.debug("Writting %s", filename)
                fd.writelines(lines)
        if not os.path.exists(os.path.join(etc_parts, defaultfile)):
            with open(os.path.join(etc_parts, defaultfile), "w") as fd:
                log.debug("Writting %s", filename)
                line = "%s '%s';\n" % (option, value)
                fd.write(line)


def main():
    apt_pkg.init_config()
    cw = ConfigWriter()
    for filename in sorted(os.listdir("/etc/apt/apt.conf.d/")):
        lines = open("/etc/apt/apt.conf.d/%s" % filename).readlines()
        cw.parse(lines)
    print((cw.set_value("huhu::abc", "lumpi", "10glatzor")))

if __name__ == "__main__":
    main()

# vim:ts=4:sw=4:et
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             #!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Integration of debconf on the client side

Provides the DebconfProxy class which allows to run the debconf frontend
as normal user by connecting to the root running debconf through the
socket of the passthrough frontend.
"""
# Copyright (C) 2009 Sebastian Heinlein <devel@glatzor.de>
# Copyright (C) 2009 Michael Vogt <michael.vogt@ubuntu.com>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

__all__ = ("DebconfProxy",)

import copy
import logging
import os
import os.path
import socket
import subprocess
import tempfile
import sys

from gi.repository import GLib

log = logging.getLogger("AptClient.DebconfProxy")


class DebconfProxy(object):

    """The DebconfProxy class allows to run the debconf frontend
    as normal user by connecting to the root debconf through the socket of the
    passthrough frontend.
    """

    def __init__(self, frontend="gnome", socket_path=None):
        """Initialize a new DebconfProxy instance.

        Keyword arguments:
        frontend -- the to be used debconf frontend (defaults to gnome)
        socket_path -- the path to the socket of the passthrough frontend.
            Will be created if not specified
        """
        self.socket_path = socket_path
        self.temp_dir = None
        if socket_path is None:
            self.temp_dir = tempfile.mkdtemp(prefix="aptdaemon-")
            self.socket_path = os.path.join(self.temp_dir, "debconf.socket")
        log.debug("debconf socket: %s" % self.socket_path)
        self.socket = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
        self.socket.bind(self.socket_path)
        self.frontend = frontend
        self._listener_id = None
        self._active_conn = None
        self._watch_ids = []

    def _get_debconf_env(self):
        """Returns a dictonary of the environment variables required by
        the debconf frontend.
        """
        env = copy.copy(os.environ)
        env["DEBCONF_DB_REPLACE"] = "configdb"
        env["DEBCONF_DB_OVERRIDE"] = "Pipe{infd:none outfd:none}"
        env["DEBIAN_FRONTEND"] = self.frontend
        if log.level == logging.DEBUG:
            env["DEBCONF_DEBUG"] = "."
        return env

    def start(self):
        """Start listening on the socket."""
        logging.debug("debconf.start()")
        self.socket.listen(1)
        self._listener_id = GLib.io_add_watch(
            self.socket, GLib.PRIORITY_DEFAULT_IDLE,
            GLib.IO_IN, self._accept_connection)

    def stop(self):
        """Stop listening on the socket."""
        logging.debug("debconf.stop()")
        self.socket.close()
        if self._listener_id is not None:
            GLib.source_remove(self._listener_id)
            self._listener_id = None
        if self.temp_dir:
            try:
                os.remove(self.socket_path)
                os.rmdir(self.temp_dir)
            except OSError:
                pass

    def _accept_connection(self, socket, condition):
        if self._active_conn:
            log.debug("Delaying connection")
            return True
        conn, addr = socket.accept()
        self._active_conn = conn
        mask = GLib.IO_IN | GLib.IO_ERR | GLib.IO_HUP | GLib.IO_NVAL
        self.helper = subprocess.Popen(["debconf-communicate"],
                                       stdin=subprocess.PIPE,
                                       stdout=subprocess.PIPE,
                                       env=self._get_debconf_env())
        GLib.io_add_watch(conn, GLib.PRIORITY_HIGH_IDLE,
                          mask, self._copy_conn, self.helper.stdin)
        GLib.io_add_watch(self.helper.stdout, GLib.PRIORITY_HIGH_IDLE,
                          mask, self._copy_stdout, conn)
        return True

    def _copy_stdout(self, source, condition, conn):
        """Callback to copy data from the stdout of debconf-communicate to
        the passthrough frontend."""
        logging.debug("_copy_stdout")
        try:
            debconf_data = source.readline()
            if debconf_data:
                log.debug("From debconf: %s", debconf_data)
                conn.send(debconf_data)
                return True
        except (socket.error, IOError) as error:
            log.debug(error)
        # error, stop listening
        log.debug("Stop reading from stdout")
        self.helper.stdout.close()
        self._active_conn.close()
        self._active_conn = None
        return False

    def _copy_conn(self, source, condition, stdin):
        """Callback to copy data from the passthrough frontend to stdin of
        debconf-communicate."""
        logging.debug("_copy_conn")
        try:
            socket_data = source.recv(1024)
            if socket_data:
                log.debug("From socket: %s", socket_data)
                stdin.write(socket_data)
                stdin.flush()
                return True
        except (socket.error, IOError) as error:
            log.debug(error)
        # error, stop listening
        log.debug("Stop reading from conn")
        self.helper.stdin.close()
        return False


def _test():
    """Run the DebconfProxy from the command line for testing purposes.

    You have to execute the following commands before in a separate terminal:
    $ echo "fset debconf/frontend seen false" | debconf-communicate
    $ export DEBCONF_PIPE=/tmp/debconf.socket
    $ dpkg-reconfigure debconf -f passthrough
    """
    logging.basicConfig(level=logging.DEBUG)
    socket_path = "/tmp/debconf.socket"
    if os.path.exists(socket_path):
        os.remove(socket_path)
    proxy = DebconfProxy("gnome", socket_path)
    proxy.start()
    loop = GLib.MainLoop()
    loop.run()

if __name__ == "__main__":
    _test()

# vim:ts=4:sw=4:et
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          #!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Handles the apt system lock"""
# Copyright (C) 2010 Sebastian Heinlein <devel@glatzor.de>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

__author__ = "Sebastian Heinlein <devel@glatzor.de>"

__all__ = ("LockFailedError", "system")

import fcntl
import os
import struct

import apt_pkg
from gi.repository import GLib

from aptdaemon import enums
from aptdaemon.errors import TransactionCancelled


class LockFailedError(Exception):

    """The locking of file failed."""

    def __init__(self, flock, process=None):
        """Return a new LockFailedError instance.

        Keyword arguments:
        flock -- the path of the file lock
        process -- the process which holds the lock or None
        """
        msg = "Could not acquire lock on %s." % flock
        if process:
            msg += " The lock is hold by %s." % process
        Exception.__init__(self, msg)
        self.flock = flock
        self.process = process


class FileLock(object):

    """Represents a file lock."""

    def __init__(self, path):
        self.path = path
        self.fd = None

    @property
    def locked(self):
        return self.fd is not None

    def acquire(self):
        """Return the file descriptor of the lock file or raise
        LockFailedError if the lock cannot be obtained.
        """
        if self.fd:
            return self.fd
        fd_lock = apt_pkg.get_lock(self.path)
        if fd_lock < 0:
            process = get_locking_process_name(self.path)
            raise LockFailedError(self.path, process)
        else:
            self.fd = fd_lock
            return fd_lock

    def release(self):
        """Relase the lock."""
        if self.fd:
            os.close(self.fd)
            self.fd = None


def get_locking_process_name(lock_path):
    """Return the name of a process which holds a lock. It will be None if
    the name cannot be retrivied.
    """
    try:
        fd_lock_read = open(lock_path, "r")
    except IOError:
        return None
    else:
        # Get the pid of the locking application
        flk = struct.pack('hhQQi', fcntl.F_WRLCK, os.SEEK_SET, 0, 0, 0)
        flk_ret = fcntl.fcntl(fd_lock_read, fcntl.F_GETLK, flk)
        pid = struct.unpack("hhQQi", flk_ret)[4]
        # Get the command of the pid
        try:
            with open("/proc/%s/status" % pid, "r") as fd_status:
                try:
                    for key, value in (line.split(":") for line in
                                       fd_status.readlines()):
                        if key == "Name":
                            return value.strip()
                except Exception:
                    return None
        except IOError:
            return None
        finally:
            fd_lock_read.close()
    return None

apt_pkg.init()

#: The lock for dpkg status file
_status_dir = os.path.dirname(apt_pkg.config.find_file("Dir::State::status"))
status_lock = FileLock(os.path.join(_status_dir, "lock"))

#: The lock for the package archive
_archives_dir = apt_pkg.config.find_dir("Dir::Cache::Archives")
archive_lock = FileLock(os.path.join(_archives_dir, "lock"))

#: The lock for the repository indexes
lists_lock = FileLock(os.path.join(
    apt_pkg.config.find_dir("Dir::State::lists"), "lock"))


def acquire():
    """Acquire an exclusive lock for the package management system."""
    try:
        for lock in archive_lock, status_lock, lists_lock:
            if not lock.locked:
                lock.acquire()
    except:
        release()
        raise


def release():
    """Release an exclusive lock for the package management system."""
    for lock in archive_lock, status_lock, lists_lock:
        lock.release()


def wait_for_lock(trans, alt_lock=None):
    """Acquire the system lock or the optionally given one. If the lock
    cannot be obtained pause the transaction in the meantime.

    :param trans: the transaction
    :param lock: optional alternative lock
    """
    def watch_lock():
        """Helper to unpause the transaction if the lock can be obtained.

        Keyword arguments:
        trans -- the corresponding transaction
        alt_lock -- alternative lock to the system lock
        """
        try:
            if alt_lock:
                alt_lock.acquire()
            else:
                acquire()
        except LockFailedError:
            return True
        trans.paused = False
        return True

    try:
        if alt_lock:
            alt_lock.acquire()
        else:
            acquire()
    except LockFailedError as error:
        trans.paused = True
        trans.status = enums.STATUS_WAITING_LOCK
        if error.process:
            # TRANSLATORS: %s is the name of a package manager
            msg = trans.gettext("Waiting for %s to exit")
            trans.status_details = msg % error.process
        lock_watch = GLib.timeout_add_seconds(3, watch_lock)
        while trans.paused and not trans.cancelled:
            GLib.main_context_default().iteration()
        GLib.source_remove(lock_watch)
        if trans.cancelled:
            raise TransactionCancelled()

# vim:ts=4:sw=4:et
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   #!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Main loop for aptdaemon."""
# Copyright (C) 2008-2009 Sebastian Heinlein <devel@glatzor.de>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

__author__ = "Sebastian Heinlein <devel@glatzor.de>"

__all__ = ("mainloop", "get_main_loop")

from gi.repository import GLib

mainloop = GLib.MainLoop()


def get_main_loop():
    """Return the glib main loop as a singleton."""
    return mainloop

# vim:ts=4:sw=4:et
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    # !/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Provides helper functions for the PackageKit layer

Copyright (C) 2007 Ali Sabil <ali.sabil@gmail.com>
Copyright (C) 2007 Tom Parker <palfrey@tevp.net>
Copyright (C) 2008-2013 Sebastian Heinlein <glatzor@ubuntu.com>

Licensed under the GNU General Public License Version 2

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.
"""

__author__ = "Sebastian Heinlein <devel@glatzor.de>"


def bitfield_summarize(*enums):
    """Return the bitfield with the given PackageKit enums."""
    field = 0
    for enum in enums:
        field |= 2 ** int(enum)
    return field


def bitfield_add(field, enum):
    """Add a PackageKit enum to a given field"""
    field |= 2 ** int(enum)
    return field


def bitfield_remove(field, enum):
    """Remove a PackageKit enum to a given field"""
    field = field ^ 2 ** int(enum)
    return field


def bitfield_contains(field, enum):
    """Return True if a bitfield contains the given PackageKit enum"""
    return field & 2 ** int(enum)


# vim: ts=4 et sts=4
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         """
This module provides a command line client for the aptdaemon
"""
# Copyright (C) 2008-2009 Sebastian Heinlein <sevel@glatzor.de>
#
# Licensed under the GNU General Public License Version 2
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

__author__ = "Sebastian Heinlein <devel@glatzor.de>"

__all__ = ("ConsoleClient", "main")

import array
import fcntl
from gettext import gettext as _
from gettext import ngettext
import locale
from optparse import OptionParser
import os
import pty
import re
import termios
import time
import tty
import signal
import sys

from aptsources.sourceslist import SourceEntry
from gi.repository import GLib
import dbus.mainloop.glib
dbus.mainloop.glib.DBusGMainLoop(set_as_default=True)

import aptdaemon
from . import client
from . import enums
from . import errors

ANSI_BOLD = chr(27) + "[1m"
ANSI_RESET = chr(27) + "[0m"

PY3K = sys.version_info.major > 2


class ConsoleClient:
    """
    Command line interface client to aptdaemon
    """
    def __init__(self, show_terminal=True, allow_unauthenticated=False,
                 details=False):
        self._client = client.AptClient()
        self.master_fd, self.slave_fd = pty.openpty()
        self._signals = []
        signal.signal(signal.SIGINT, self._on_cancel_signal)
        signal.signal(signal.SIGQUIT, self._on_cancel_signal)
        signal.signal(signal.SIGWINCH, self._on_terminal_resize)
        self._terminal_width = self._get_terminal_width()
        self._watchers = []
        self._old_tty_mode = None
        self._show_status = True
        self._status = ""
        self._percent = 0
        self._show_terminal = show_terminal
        self._details = details
        self._allow_unauthenticated = allow_unauthenticated
        self._show_progress = True
        self._status_details = ""
        self._progress_details = ""
        # Used for a spinning line to indicate a still working transaction
        self._spin_elements = "|/-\\"
        self._spin_cur = -1
        self._spin_stamp = time.time()
        self._transaction = None
        self._loop = GLib.MainLoop()

    def add_repository(self, line="", sourcesfile=""):
        """Add repository to the sources list."""
        entry = SourceEntry(line)
        self._client.add_repository(entry.type, entry.uri, entry.dist,
                                    entry.comps, entry.comment,
                                    sourcesfile,
                                    reply_handler=self._run_transaction,
                                    error_handler=self._on_exception)

    def add_vendor_key_from_file(self, path):
        """Install repository key file."""
        self._client.add_vendor_key_from_file(
            path,
            reply_handler=self._run_transaction,
            error_handler=self._on_exception)

    def add_vendor_key_from_keyserver(self, keyid, keyserver):
        """Install repository key file."""
        self._client.add_vendor_key_from_keyserver(
            keyid, keyserver,
            reply_handler=self._run_transaction,
            error_handler=self._on_exception)

    def remove_vendor_key(self, fingerprint):
        """Remove repository key."""
        self._client.remove_vendor_key(fingerprint,
                                       reply_handler=self._run_transaction,
                                       error_handler=self._on_exception)

    def install_file(self, path):
        """Install package file."""
        self._client.install_file(path, reply_handler=self._run_transaction,
                                  error_handler=self._on_exception)

    def list_trusted_vendor_keys(self):
        """List the keys of the trusted vendors."""
        def on_done(keys):
            for key in keys:
                print(key)
            self._loop.quit()
        self._client.get_trusted_vendor_keys(reply_handler=on_done,
                                             error_handler=self._on_exception)

    def commit_packages(self, install, reinstall, remove, purge, upgrade,
                        downgrade):
        """Commit changes"""
        self._client.commit_packages(install, reinstall, remove, purge,
                                     upgrade, downgrade,
                                     reply_handler=self._run_transaction,
                                     error_handler=self._on_exception)

    def fix_incomplete_install(self):
        """Fix incomplete installs"""
        self._client.fix_incomplete_install(
            reply_handler=self._run_transaction,
            error_handler=self._on_exception)

    def fix_broken_depends(self):
        """Repair broken dependencies."""
        self._client.fix_broken_depends(reply_handler=self._run_transaction,
                                        error_handler=self._on_exception)

    def update_cache(self):
        """Update cache"""
        self._client.update_cache(reply_handler=self._run_transaction,
                                  error_handler=self._on_exception)

    def upgrade_system(self, safe_mode):
        """Upgrade system"""
        self._client.upgrade_system(safe_mode,
                                    reply_handler=self._run_transaction,
                                    error_handler=self._on_exception)

    def reconfigure(self, packages, priority):
        """Reconfigure packages."""
        self._client.reconfigure(packages, priority,
                                 reply_handler=self._run_transaction,
                                 error_handler=self._on_exception)

    def clean(self):
        """Clean archives."""
        self._client.clean(reply_handler=self._run_transaction,
                           error_handler=self._on_exception)

    def run(self):
        """Start the console client application."""
        try:
            self._loop.run()
        except KeyboardInterrupt:
            pass

    def _set_transaction(self, transaction):
        """Monitor the given transaction"""
        for handler in self._signals:
            GLib.source_remove(handler)
        self._transaction = transaction
        self._signals = []
        self._signals.append(transaction.connect("terminal-attached-changed",
                                                 self._on_terminal_attached))
        self._signals.append(transaction.connect("status-changed",
                                                 self._on_status))
        self._signals.append(transaction.connect("status-details-changed",
                                                 self._on_status_details))
        self._signals.append(transaction.connect("progress-changed",
                                                 self._on_progress))
        self._signals.append(transaction.connect("progress-details-changed",
                                                 self._on_progress_details))
        self._signals.append(transaction.connect("finished", self._on_exit))
        if self._show_terminal:
            transaction.set_terminal(os.ttyname(self.slave_fd))
        transaction.set_allow_unauthenticated(self._allow_unauthenticated)

    def _on_exit(self, trans, enum):
        """Callback for the exit state of the transaction"""
        # Make sure to dettach the terminal
        self._detach()
        if self._show_progress:
            output = "[+] 100%% %s %-*.*s%s\n" % (
                ANSI_BOLD,
                self._terminal_width - 9,
                self._terminal_width - 9,
                enums.get_exit_string_from_enum(enum),
                ANSI_RESET)
            sys.stderr.write(output)

        if enum == enums.EXIT_FAILED:
            msg = "%s: %s\n%s\n\n%s" % (
                _("ERROR"),
                enums.get_error_string_from_enum(trans.error_code),
                enums.get_error_description_from_enum(trans.error_code),
                trans.error_details)
            print(msg)
        self._loop.quit()

    def _on_terminal_attached(self, transaction, attached):
        """Callback for the terminal-attachabed-changed signal of the
        transaction.
        """
        if self._show_terminal and attached and not self._watchers:
            self._clear_progress()
            self._show_progress = False
            self._attach()
        elif not attached:
            self._show_progress = True
            self._detach()

    def _on_status(self, transaction, status):
        """Callback for the Status signal of the transaction"""
        self._status = enums.get_status_string_from_enum(status)
        self._update_progress()

    def _on_status_details(self, transaction, text):
        """Callback for the StatusDetails signal of the transaction."""
        self._status_details = text
        self._update_progress()

    def _on_progress_details(self, transaction, items_done, items_total,
                             bytes_done, bytes_total, speed, eta):
        """Callback for the ProgressDetails signal of the transaction."""
        if bytes_total and speed:
            self._progress_details = (
                _("Downloaded %(cur)sB of %(total)sB at %(rate)sB/s") %
                {'cur': client.get_size_string(bytes_done),
                 'total': client.get_size_string(bytes_total),
                 'rate': client.get_size_string(speed)})
        elif bytes_total:
            self._progress_details = (
                _("Downloaded %(cur)sB of %(total)sB") %
                {'cur': client.get_size_string(bytes_done),
                 'total': client.get_size_string(bytes_total)})
        else:
            self._progress_details = ""
        self._update_progress()

    def _on_progress(self, transaction, percent):
        """Callback for the Progress signal of the transaction"""
        self._percent = percent
        self._update_progress()

    def _update_progress(self):
        """Update the progress bar."""
        if not self._show_progress:
            return
        text = ANSI_BOLD + self._status + ANSI_RESET
        if self._status_details:
            text += " " + self._status_details
        if self._progress_details:
            text += " (%s)" % self._progress_details
        text_width = self._terminal_width - 9
        # Spin the progress line (maximum 5 times a second)
        if self._spin_stamp + 0.2 < time.time():
            self._spin_cur = (self._spin_cur + 1) % len(self._spin_elements)
            self._spin_stamp = time.time()
        spinner = self._spin_elements[self._spin_cur]
        # Show progress information if available
        if self._percent > 100:
            percent = "---"
        else:
            percent = self._percent
        sys.stderr.write("[%s] " % spinner +
                         "%3.3s%% " % percent +
                         "%-*.*s" % (text_width, text_width, text) + "\r")

    def _update_custom_progress(self, msg, percent=None, spin=True):
        """Update the progress bar with a custom status message."""
        text = ANSI_BOLD + msg + ANSI_RESET
        text_width = self._terminal_width - 9
        # Spin the progress line (maximum 5 times a second)
        if spin:
            self._spin_cur = (self._spin_cur + 1) % len(self._spin_elements)
            self._spin_stamp = time.time()
            spinner = self._spin_elements[self._spin_cur]
        else:
            spinner = "+"
        # Show progress information if available
        if percent is None:
            percent = "---"
        sys.stderr.write("[%s] " % spinner +
                         "%3.3s%% " % percent +
                         "%-*.*s" % (text_width, text_width, text) + "\r")
        return True

    def _stop_custom_progress(self):
        """Stop the spinner which shows non trans status messages."""
        if self._progress_id is not None:
            GLib.source_remove(self._progress_id)

    def _clear_progress(self):
        """Clear progress information on stderr."""
        sys.stderr.write("%-*.*s\r" % (self._terminal_width,
                                       self._terminal_width,
                                       " "))

    def _on_cancel_signal(self, signum, frame):
        """Callback for a cancel signal."""
        if (self._transaction and
                self._transaction.status != enums.STATUS_SETTING_UP):
            self._transaction.cancel()
        else:
            self._loop.quit()

    def _on_terminal_resize(self, signum, frame):
        """Callback for a changed terminal size."""
        self._terminal_width = self._get_terminal_width()
        self._update_progress()

    def _detach(self):
        """Dettach the controlling terminal to aptdaemon."""
        for wid in self._watchers:
            GLib.source_remove(wid)
        if self._old_tty_mode:
            tty.tcsetattr(pty.STDIN_FILENO, tty.TCSAFLUSH,
                          self._old_tty_mode)

    def _attach(self):
        """Attach the controlling terminal to aptdaemon.
        Based on pty.spwan()
        """
        try:
            self._old_tty_mode = tty.tcgetattr(pty.STDIN_FILENO)
            tty.setraw(pty.STDIN_FILENO)
        except tty.error:    # This is the same as termios.error
            self._old_tty_mode = None
        flags = GLib.IO_IN | GLib.IO_ERR | GLib.IO_HUP
        self._watchers.append(
            GLib.io_add_watch(pty.STDIN_FILENO,
                              GLib.PRIORITY_HIGH_IDLE, flags,
                              self._copy_io, self.master_fd))
        self._watchers.append(
            GLib.io_add_watch(self.master_fd, GLib.PRIORITY_HIGH_IDLE,
                              flags, self._copy_io, pty.STDOUT_FILENO))

    def _copy_io(self, source, condition, target):
        """Callback to copy data between terminals."""
        if condition == GLib.IO_IN:
            data = os.read(source, 1024)
            if target:
                os.write(target, data)
            return True
        os.close(source)
        return False

    def _get_terminal_width(self):
        """Return the witdh in characters of the current terminal."""
        try:
            return array.array("h", fcntl.ioctl(sys.stderr, termios.TIOCGWINSZ,
                                                "\0" * 8))[1]
        except IOError:
            # Fallback to the "default" size
            return 80

    def _on_exception(self, error):
        """Error callback."""
        self._detach()
        try:
            raise error
        except errors.PolicyKitError:
            msg = "%s %s\n\n%s" % (_("ERROR:"),
                                   _("You are not allowed to perform "
                                     "this action."),
                                   error.get_dbus_message())
        except dbus.DBusException:
            msg = "%s %s - %s" % (_("ERROR:"), error.get_dbus_name(),
                                  error.get_dbus_message())
        except:
            msg = str(error)
        self._loop.quit()
        sys.exit(msg)

    def _run_transaction(self, trans):
        """Callback which runs a requested transaction."""
        self._set_transaction(trans)
        self._stop_custom_progress()
        if self._transaction.role in [enums.ROLE_UPDATE_CACHE,
                                      enums.ROLE_ADD_VENDOR_KEY_FILE,
                                      enums.ROLE_ADD_VENDOR_KEY_FROM_KEYSERVER,
                                      enums.ROLE_REMOVE_VENDOR_KEY,
                                      enums.ROLE_FIX_INCOMPLETE_INSTALL]:
            # TRANSLATORS: status message
            self._progress_id = GLib.timeout_add(250,
                                                 self._update_custom_progress,
                                                 _("Queuing"))
            self._transaction.run(
                error_handler=self._on_exception,
                reply_handler=lambda: self._stop_custom_progress())
        else:
            # TRANSLATORS: status message
            self._progress_id = GLib.timeout_add(250,
                                                 self._update_custom_progress,
                                                 _("Resolving dependencies"))
            self._transaction.simulate(reply_handler=self._show_changes,
                                       error_handler=self._on_exception)

    def _show_changes(self):
        def show_packages(pkgs):
            """Format the pkgs in a nice way."""
            line = " "
            pkgs.sort()
            for pkg in pkgs:
                try:
                    name, version = pkg.split("=", 1)[0:2]
                except ValueError:
                    name = pkg
                    version = None
                if self._details and version:
                    output = "%s=%s" % (name, version)
                else:
                    output = name
                if (len(line) + 1 + len(output) > self._terminal_width and
                        line != " "):
                    print(line)
                    line = " "
                line += " %s" % output
            if line != " ":
                print(line)
        self._stop_custom_progress()
        self._clear_progress()
        (installs, reinstalls, removals, purges, upgrades,
            downgrades) = self._transaction.packages
        (dep_installs, dep_reinstalls, dep_removals, dep_purges, dep_upgrades,
            dep_downgrades, dep_kepts) = self._transaction.dependencies
        installs.extend(dep_installs)
        upgrades.extend(dep_upgrades)
        removals.extend(purges)
        removals.extend(dep_removals)
        removals.extend(dep_purges)
        reinstalls.extend(dep_reinstalls)
        downgrades.extend(dep_downgrades)
        kepts = dep_kepts
        if installs:
            # TRANSLATORS: %s is the number of packages
            print((ngettext("The following NEW package will be installed "
                            "(%(count)s):",
                            "The following NEW packages will be installed "
                            "(%(count)s):",
                            len(installs)) % {"count": len(installs)}))
            show_packages(installs)
        if upgrades:
            # TRANSLATORS: %s is the number of packages
            print((ngettext("The following package will be upgraded "
                            "(%(count)s):",
                            "The following packages will be upgraded "
                            "(%(count)s):",
                            len(upgrades)) % {"count": len(upgrades)}))
            show_packages(upgrades)
        if removals:
            # TRANSLATORS: %s is the number of packages
            print((ngettext("The following package will be REMOVED "
                            "(%(count)s):",
                            "The following packages will be REMOVED "
                            "(%(count)s):",
                            len(removals)) % {"count": len(removals)}))
            # FIXME: mark purges
            show_packages(removals)
        if downgrades:
            # TRANSLATORS: %s is the number of packages
            print((ngettext("The following package will be DOWNGRADED "
                            "(%(count)s):",
                            "The following packages will be DOWNGRADED "
                            "(%(count)s):",
                            len(downgrades)) % {"count": len(downgrades)}))
            show_packages(downgrades)
        if reinstalls:
            # TRANSLATORS: %s is the number of packages
            print((ngettext("The following package will be reinstalled "
                            "(%(count)s):",
                            "The following packages will be reinstalled "
                            "(%(count)s):",
                            len(reinstalls)) % {"count": len(reinstalls)}))
            show_packages(reinstalls)
        if kepts:
            print((ngettext("The following package has been kept back "
                            "(%(count)s):",
                            "The following packages have been kept back "
                            "(%(count)s):",
                            len(kepts)) % {"count": len(kepts)}))
            show_packages(kepts)

        if self._transaction.download:
            print(_("Need to get %sB of archives.") %
                  client.get_size_string(self._transaction.download))
        if self._transaction.space > 0:
            print(_("After this operation, %sB of additional disk space "
                    "will be used.") %
                  client.get_size_string(self._transaction.space))
        elif self._transaction.space < 0:
            print(_("After this operation, %sB of additional disk space "
                    "will be freed.") %
                  client.get_size_string(self._transaction.space))
        if (self._transaction.space or self._transaction.download or
                installs or upgrades or downgrades or removals or kepts or
                reinstalls):
            try:
                if PY3K:
                    cont = input(_("Do you want to continue [Y/n]?"))
                else:
                    cont = raw_input(_("Do you want to continue [Y/n]?"))
            except EOFError:
                cont = "n"
            # FIXME: Listen to changed dependencies!
            if (not re.match(locale.nl_langinfo(locale.YESEXPR), cont) and
                    cont != ""):
                msg = enums.get_exit_string_from_enum(enums.EXIT_CANCELLED)
                self._update_custom_progress(msg, None, False)
                self._loop.quit()
                sys.exit(1)
        # TRANSLATORS: status message
        self._progress_id = GLib.timeout_add(250,
                                             self._update_custom_progress,
                                             _("Queuing"))
        self._transaction.run(
            error_handler=self._on_exception,
            reply_handler=lambda: self._stop_custom_progress())


def main():
    """Run a command line client for aptdaemon"""
    epilog = _("To operate on more than one package put the package "
               "names in quotation marks:\naptdcon --install "
               "\"foo bar\"")
    parser = OptionParser(version=aptdaemon.__version__, epilog=epilog)
    parser.add_option("-c", "--refresh", default="",
                      action="store_true", dest="refresh",
                      help=_("Refresh the cache"))
    parser.add_option("", "--fix-depends", default="",
                      action="store_true", dest="fix_depends",
                      help=_("Try to resolve broken dependencies. "
                             "Potentially dangerous operation since it could "
                             "try to remove many packages."))
    parser.add_option("", "--fix-install", default="",
                      action="store_true", dest="fix_install",
                      help=_("Try to finish a previous incompleted "
                             "installation"))
    parser.add_option("-i", "--install", default="",
                      action="store", type="string", dest="install",
                      help=_("Install the given packages"))
    parser.add_option("", "--reinstall", default="",
                      action="store", type="string", dest="reinstall",
                      help=_("Reinstall the given packages"))
    parser.add_option("-r", "--remove", default="",
                      action="store", type="string", dest="remove",
                      help=_("Remove the given packages"))
    parser.add_option("-p", "--purge", default="",
                      action="store", type="string", dest="purge",
                      help=_("Remove the given packages including "
                             "configuration files"))
    parser.add_option("-u", "--upgrade", default="",
                      action="store", type="string", dest="upgrade",
                      help=_("Install the given packages"))
    parser.add_option("", "--downgrade", default="",
                      action="store", type="string", dest="downgrade",
                      help=_("Downgrade the given packages"))
    parser.add_option("", "--upgrade-system",
                      action="store_true", dest="safe_upgrade",
                      help=_("Deprecated: Please use "
                             "--safe-upgrade"))
    parser.add_option("", "--safe-upgrade",
                      action="store_true", dest="safe_upgrade",
                      help=_("Upgrade the system in a safe way"))
    parser.add_option("", "--full-upgrade",
                      action="store_true", dest="full_upgrade",
                      help=_("Upgrade the system, possibly installing and "
                             "removing packages"))
    parser.add_option("", "--add-vendor-key", default="",
                      action="store", type="string", dest="add_vendor_key",
                      help=_("Add the vendor to the trusted ones"))
    parser.add_option("", "--add-vendor-key-from-keyserver", default="",
                      action="store", type="string",
                      help=_("Add the vendor keyid (also needs "
                             "--keyserver)"))
    parser.add_option("", "--keyserver", default="",
                      action="store", type="string",
                      help=_("Use the given keyserver for looking up "
                             "keys"))
    parser.add_option("", "--add-repository", default="",
                      action="store", type="string", dest="add_repository",
                      help=_("Add new repository from the given "
                             "deb-line"))
    parser.add_option("", "--sources-file", action="store", default="",
                      type="string", dest="sources_file",
                      help=_("Specify an alternative sources.list.d file to "
                             "which repositories should be added."))
    parser.add_option("", "--list-trusted-vendors", default="",
                      action="store_true", dest="list_trusted_vendor_keys",
                      help=_("List trusted vendor keys"))
    parser.add_option("", "--remove-vendor-key", default="",
                      action="store", type="string", dest="remove_vendor_key",
                      help=_("Remove the trusted key of the given "
                             "fingerprint"))
    parser.add_option("", "--clean",
                      action="store_true", dest="clean",
                      help=_("Remove downloaded package files"))
    parser.add_option("", "--reconfigure", default="",
                      action="store", type="string", dest="reconfigure",
                      help=_("Reconfigure installed packages. Optionally the "
                             "minimum priority of questions can be "
                             "specified"))
    parser.add_option("", "--priority", default="default",
                      action="store", type="string", dest="priority",
                      help=_("The minimum debconf priority of question to "
                             "be displayed"))
    parser.add_option("", "--hide-terminal",
                      action="store_true", dest="hide_terminal",
                      help=_("Do not attach to the apt terminal"))
    parser.add_option("", "--allow-unauthenticated",
                      action="store_true", dest="allow_unauthenticated",
                      default=False,
                      help=_("Allow packages from unauthenticated "
                             "sources"))
    parser.add_option("-d", "--show-details",
                      action="store_true", dest="details",
                      help=_("Show additional information about the packages. "
                             "Currently only the version number"))
    (options, args) = parser.parse_args()
    con = ConsoleClient(show_terminal=not options.hide_terminal,
                        allow_unauthenticated=options.allow_unauthenticated,
                        details=options.details)
    # TRANSLATORS: status message
    con._progress_id = GLib.timeout_add(250, con._update_custom_progress,
                                        _("Waiting for authentication"))
    if options.safe_upgrade:
        con.upgrade_system(True)
    elif options.full_upgrade:
        con.upgrade_system(False)
    elif options.refresh:
        con.update_cache()
    elif options.reconfigure:
        con.reconfigure(options.reconfigure.split(), options.priority)
    elif options.clean:
        con.clean()
    elif options.fix_install:
        con.fix_incomplete_install()
    elif options.fix_depends:
        con.fix_broken_depends()
    elif options.install and options.install.endswith(".deb"):
        con.install_file(options.install)
    elif (options.install or options.reinstall or options.remove or
          options.purge or options.upgrade or options.downgrade):
        con.commit_packages(options.install.split(),
                            options.reinstall.split(),
                            options.remove.split(),
                            options.purge.split(),
                            options.upgrade.split(),
                            options.downgrade.split())
    elif options.add_repository:
        con.add_repository(options.add_repository, options.sources_file)
    elif options.add_vendor_key:
        # FIXME: Should detect if from stdin or file
        con.add_vendor_key_from_file(options.add_vendor_key)
    elif options.add_vendor_key_from_keyserver and options.keyserver:
        con.add_vendor_key_from_keyserver(
            options.add_vendor_key_from_keyserver,
            options.keyserver)
    elif options.remove_vendor_key:
        con.remove_vendor_key(options.remove_vendor_key)
    elif options.list_trusted_vendor_keys:
        con.list_trusted_vendor_keys()
    else:
        parser.print_help()
        sys.exit(1)
    con.run()

if __name__ == "__main__":
    main()
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  #!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Core components of aptdaemon.

This module provides the following core classes of the aptdaemon:
AptDaemon - complete daemon for managing software via DBus interface
Transaction - represents a software management operation
TransactionQueue - queue for aptdaemon transactions

The main function allows to run the daemon as a command.
"""
# Copyright (C) 2008-2009 Sebastian Heinlein <devel@glatzor.de>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

__author__ = "Sebastian Heinlein <devel@glatzor.de>"

__all__ = ("Transaction", "TransactionQueue", "AptDaemon",
           "APTDAEMON_TRANSACTION_DBUS_INTERFACE", "APTDAEMON_DBUS_INTERFACE"
           "APTDAEMON_DBUS_PATH", "APTDAEMON_DBUS_SERVICE",
           "APTDAEMON_IDLE_CHECK_INTERVAL", "APTDAEMON_IDLE_TIMEOUT",
           "TRANSACTION_IDLE_TIMEOUT", "TRANSACTION_DEL_TIMEOUT")

import collections
from xml.etree import ElementTree
import gettext
from hashlib import md5
import locale
import logging
import logging.handlers
from optparse import OptionParser
import os
import re
import signal
import sys
import time
import uuid

from gi.repository import GObject, GLib
import dbus.exceptions
import dbus.service
import dbus.mainloop.glib

from .config import ConfigWriter
from . import errors
from . import enums
from defer import inline_callbacks, return_value, Deferred
from defer.utils import dbus_deferred_method
from . import policykit1
from .utils import split_package_id
from .worker import DummyWorker
from .worker.aptworker import (AptWorker,
                               trans_only_installs_pkgs_from_high_trust_repos)
from .loop import mainloop
from .logger import ColoredFormatter

# Setup i18n
_ = lambda msg: gettext.dgettext("aptdaemon", msg)
if sys.version >= '3':
    _gettext_method = "gettext"
    _ngettext_method = "ngettext"
else:
    _gettext_method = "ugettext"
    _ngettext_method = "ungettext"

APTDAEMON_DBUS_INTERFACE = 'org.debian.apt'
APTDAEMON_DBUS_PATH = '/org/debian/apt'
APTDAEMON_DBUS_SERVICE = 'org.debian.apt'

APTDAEMON_TRANSACTION_DBUS_INTERFACE = 'org.debian.apt.transaction'

APTDAEMON_IDLE_CHECK_INTERVAL = 60
APTDAEMON_IDLE_TIMEOUT = 10 * 60

# Maximum allowed time between the creation of a transaction and its queuing
TRANSACTION_IDLE_TIMEOUT = 300
# Keep the transaction for the given time alive on the bus after it has
# finished
TRANSACTION_DEL_TIMEOUT = 30

# regexp for the pkgname and optional arch, for details see
#   http://www.debian.org/doc/debian-policy/ch-controlfields.html#s-f-Source
REGEX_VALID_PACKAGENAME = "^[a-z0-9][a-z0-9\-+.]+(:[a-z0-9]+)?$"
# regexp for the version number, for details see:
#   http://www.debian.org/doc/debian-policy/ch-controlfields.html#s-f-Version
REGEX_VALID_VERSION = "^[0-9][0-9.+\-A-Za-z:~]*$"
# regexp for the archive (Suite) as found in the Release file
REGEX_VALID_RELEASE = "^[a-zA-Z0-9_\-\.]+$"

# Setup the DBus main loop
dbus.mainloop.glib.DBusGMainLoop(set_as_default=True)

# Required for daemon mode
os.putenv("PATH",
          "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin")

# Setup logging to syslog and the console
log = logging.getLogger("AptDaemon")
try:
    _syslog_handler = logging.handlers.SysLogHandler(
        address="/dev/log",
        facility=logging.handlers.SysLogHandler.LOG_DAEMON)
    _syslog_handler.setLevel(logging.INFO)
    _syslog_formatter = logging.Formatter("%(name)s: %(levelname)s: "
                                          "%(message)s")
    _syslog_handler.setFormatter(_syslog_formatter)
except:
    pass
else:
    log.addHandler(_syslog_handler)
_console_handler = logging.StreamHandler()
_console_formatter = ColoredFormatter("%(asctime)s %(name)s [%(levelname)s]: "
                                      "%(message)s",
                                      "%T")
_console_handler.setFormatter(_console_formatter)
log.addHandler(_console_handler)
# FIXME: Use LoggerAdapter (requires Python 2.6)
log_trans = logging.getLogger("AptDaemon.Trans")

# Required for translations from APT
try:
    locale.setlocale(locale.LC_ALL, "")
except locale.Error:
    log.warning("Failed to unset LC_ALL. Translations are not available.")


def _excepthook(exc_type, exc_obj, exc_tb, apport_excepthook):
    """Handle exceptions of aptdaemon and avoid tiggering apport crash
    reports for valid DBusExceptions that are sent to the client.
    """
    # apport registers it's own excepthook as sys.excepthook. So we have to
    # send exceptions that we don't want to be tracked to Python's
    # internal excepthook directly
    if issubclass(exc_type, errors.AptDaemonError):
        sys.__excepthook__(exc_type, exc_obj, exc_tb)
    else:
        apport_excepthook(exc_type, exc_obj, exc_tb)

if sys.excepthook.__name__ == "apport_excepthook":
    apport_excepthook = sys.excepthook
    sys.excepthook = lambda etype, eobj, etb: _excepthook(etype, eobj, etb,
                                                          apport_excepthook)


class DBusObject(dbus.service.Object):

    """Enhanced D-Bus object class which supports properties."""

    WRITABLE_PROPERTIES = ()

    # pylint: disable-msg=C0103,C0322
    @dbus.service.signal(dbus_interface=dbus.PROPERTIES_IFACE,
                         signature="sa{sv}as")
    def PropertiesChanged(self, interface, changed_properties,
                          invalidated_properties):
        """The signal gets emitted if a property of the object's
        interfaces changed.

        :param property: The name of the interface.
        :param changed_properties: A dictrionary of changed
            property/value pairs
        :param invalidated_properties: An array of property names which
            changed but the value isn't conveyed.

        :type interface: s
        :type changed_properties: a{sv}
        :type invalidated_properties: as
        """
        log.debug("Emitting PropertiesChanged: %s, %s, %s" %
                  (interface, changed_properties, invalidated_properties))

    # pylint: disable-msg=C0103,C0322
    @dbus.service.method(dbus.INTROSPECTABLE_IFACE,
                         in_signature='', out_signature='s',
                         path_keyword='object_path',
                         connection_keyword='connection')
    def Introspect(self, object_path, connection):
        # Inject the properties into the introspection xml data
        data = dbus.service.Object.Introspect(self, object_path, connection)
        xml = ElementTree.fromstring(data)
        for iface in xml.findall("interface"):
            props = self._get_properties(iface.attrib["name"])
            for key, value in props.items():
                attrib = {"name": key}
                if key in self.WRITABLE_PROPERTIES:
                    attrib["access"] = "readwrite"
                else:
                    attrib["access"] = "read"
                if isinstance(value, dbus.String):
                    attrib["type"] = "s"
                elif isinstance(value, dbus.UInt32):
                    attrib["type"] = "u"
                elif isinstance(value, dbus.Int32):
                    attrib["type"] = "i"
                elif isinstance(value, dbus.UInt64):
                    attrib["type"] = "t"
                elif isinstance(value, dbus.Int64):
                    attrib["type"] = "x"
                elif isinstance(value, dbus.Boolean):
                    attrib["type"] = "b"
                elif isinstance(value, dbus.Struct):
                    attrib["type"] = "(%s)" % value.signature
                elif isinstance(value, dbus.Dictionary):
                    attrib["type"] = "a{%s}" % value.signature
                elif isinstance(value, dbus.Array):
                    attrib["type"] = "a%s" % value.signature
                else:
                    raise Exception("Type %s of property %s isn't "
                                    "convertable" % (type(value), key))
                iface.append(ElementTree.Element("property", attrib))
        new_data = ElementTree.tostring(xml, encoding="UTF-8")
        return new_data

    # pylint: disable-msg=C0103,C0322
    @dbus_deferred_method(dbus.PROPERTIES_IFACE,
                          in_signature="ssv", out_signature="",
                          sender_keyword="sender")
    def Set(self, iface, name, value, sender):
        """Set a property.

        Only the user who intiaited the transaction is
        allowed to modify it.

        :param iface: The interface which provides the property.
        :param name: The name of the property which should be modified.
        :param value: The new value of the property.

        :type iface: s
        :type name: s
        :type value: v
        """
        log.debug("Set() was called: %s, %s" % (name, value))
        return self._set_property(iface, name, value, sender)

    # pylint: disable-msg=C0103,C0322
    @dbus.service.method(dbus.PROPERTIES_IFACE,
                         in_signature="s", out_signature="a{sv}")
    def GetAll(self, iface):
        """Get all available properties of the given interface."""
        log.debug("GetAll() was called: %s" % iface)
        return self._get_properties(iface)

    # pylint: disable-msg=C0103,C0322
    @dbus.service.method(dbus.PROPERTIES_IFACE,
                         in_signature="ss", out_signature="v")
    def Get(self, iface, property):
        """Return the value of the given property provided by the given
        interface.
        """
        log.debug("Get() was called: %s, %s" % (iface, property))
        return self._get_properties(iface)[property]

    def _set_property(self, iface, name, value, sender):
        """Helper to set a property on the properties D-Bus interface."""
        raise dbus.exceptions.DBusException("Unknown or read only "
                                            "property: %s" % name)

    def _get_properties(self, iface):
        """Helper to get the properties of a D-Bus interface."""
        return {}


class Transaction(DBusObject):

    """Represents a transaction on the D-Bus.

    A transaction represents a single package management task, e.g.
    installation or removal of packages. This class allows to expose
    information and to controll the transaction via DBus using PolicyKit
    for managing privileges.
    """

    ROLE_ACTION_MAP = {
        enums.ROLE_PK_QUERY: None,
        enums.ROLE_INSTALL_PACKAGES: (
            policykit1.PK_ACTION_INSTALL_OR_REMOVE_PACKAGES),
        enums.ROLE_REMOVE_PACKAGES: (
            policykit1.PK_ACTION_INSTALL_OR_REMOVE_PACKAGES),
        enums.ROLE_INSTALL_FILE: (
            policykit1.PK_ACTION_INSTALL_FILE),
        enums.ROLE_UPGRADE_PACKAGES: (
            policykit1.PK_ACTION_UPGRADE_PACKAGES),
        enums.ROLE_UPGRADE_SYSTEM: (
            policykit1.PK_ACTION_UPGRADE_PACKAGES),
        enums.ROLE_UPDATE_CACHE: (
            policykit1.PK_ACTION_UPDATE_CACHE),
        enums.ROLE_COMMIT_PACKAGES: (
            policykit1.PK_ACTION_INSTALL_OR_REMOVE_PACKAGES),
        enums.ROLE_ADD_VENDOR_KEY_FILE: (
            policykit1.PK_ACTION_CHANGE_REPOSITORY),
        enums.ROLE_ADD_VENDOR_KEY_FROM_KEYSERVER: (
            policykit1.PK_ACTION_CHANGE_REPOSITORY),
        enums.ROLE_REMOVE_VENDOR_KEY: (
            policykit1.PK_ACTION_CHANGE_REPOSITORY),
        enums.ROLE_FIX_INCOMPLETE_INSTALL: (
            policykit1.PK_ACTION_INSTALL_OR_REMOVE_PACKAGES),
        enums.ROLE_FIX_BROKEN_DEPENDS: (
            policykit1.PK_ACTION_INSTALL_OR_REMOVE_PACKAGES),
        enums.ROLE_ADD_REPOSITORY: (
            policykit1.PK_ACTION_CHANGE_REPOSITORY),
        enums.ROLE_RECONFIGURE: (
            policykit1.PK_ACTION_INSTALL_OR_REMOVE_PACKAGES),
        enums.ROLE_CLEAN: (
            policykit1.PK_ACTION_CLEAN),
        enums.ROLE_ENABLE_DISTRO_COMP: (
            policykit1.PK_ACTION_CHANGE_REPOSITORY),
        enums.ROLE_ADD_LICENSE_KEY: (
            policykit1.PK_ACTION_INSTALL_OR_REMOVE_PACKAGES)}

    WRITABLE_PROPERTIES = ("HttpProxy", "Terminal", "AllowUnauthenticated",
                           "DebconfSocket", "MetaData", "Locale",
                           "RemoveObsoleteDepends")

    def __init__(self, tid, role, queue, pid, uid, gid, cmdline, sender,
                 connect=True, bus=None, packages=None, kwargs=None):
        """Initialize a new Transaction instance.

        Keyword arguments:
        tid -- The unique identifier
        role -- The role enum of the transaction
        queue -- TransactionQueue instance of the daemon
        pid -- the id of the process which created the transaction
        uid -- the uid of the user who created the transaction
        cmdline -- the cmdline of the calling process
        sender -- the DBus name of the sender who created the transaction
        connect -- if the Transaction should connect to DBus (default is True)
        bus -- the DBus connection which should be used
            (defaults to system bus)
        """
        if tid is None:
            tid = uuid.uuid4().hex
        self.tid = "/org/debian/apt/transaction/%s" % tid
        if connect is True:
            self.bus = bus
            if bus is None:
                self.bus = dbus.SystemBus()
            bus_name = dbus.service.BusName(APTDAEMON_DBUS_SERVICE, self.bus)
            dbus_path = self.tid
        else:
            bus = None
            bus_name = None
            dbus_path = None
        DBusObject.__init__(self, bus_name, dbus_path)
        if not packages:
            packages = ([], [], [], [], [], [])
        if not kwargs:
            kwargs = {}
        self.queue = queue
        self.uid = uid
        self.gid = gid
        self.locale = dbus.String("")
        self.allow_unauthenticated = dbus.Boolean(False)
        self.remove_obsoleted_depends = dbus.Boolean(False)
        self.cmdline = cmdline
        self.pid = pid
        self.http_proxy = dbus.String("")
        self.terminal = dbus.String("")
        self.debconf = dbus.String("")
        self.kwargs = kwargs
        self._translation = None
        # The transaction which should be executed after this one
        self.after = None
        self._role = dbus.String(role)
        self._progress = dbus.Int32(0)
        # items_done, total_items, bytes_done, total_bytes, speed, time
        self._progress_details = dbus.Struct((0, 0, 0, 0, 0.0, 0),
                                             signature="iixxdx")
        self._progress_download = dbus.Struct(("", "", "", 0, 0, ""),
                                              signature="sssxxs")
        self._progress_package = dbus.Struct(("", ""), signature="ss")
        self._exit = dbus.String(enums.EXIT_UNFINISHED)
        self._status = dbus.String(enums.STATUS_SETTING_UP)
        self._status_details = dbus.String("")
        self._error = None
        self._error_property = dbus.Struct(("", ""), signature="ss")
        self._cancellable = dbus.Boolean(True)
        self._term_attached = dbus.Boolean(False)
        self._required_medium = dbus.Struct(("", ""), signature="ss")
        self._config_file_conflict = dbus.Struct(("", ""), signature="ss")
        self._config_file_conflict_resolution = ""
        self.cancelled = dbus.Boolean(False)
        self.paused = dbus.Boolean(False)
        self._meta_data = dbus.Dictionary(signature="sv")
        self._download = dbus.Int64(0)
        self._space = dbus.Int64(0)
        self._depends = dbus.Struct([dbus.Array([], signature='s')
                                     for i in range(7)],
                                    signature="asasasasasasas")
        self._packages = dbus.Struct([dbus.Array(pkgs, signature="s")
                                      for pkgs in packages],
                                     signature="asasasasasas")
        self._unauthenticated = dbus.Array([], signature=dbus.Signature('s'))
        self._high_trust_packages = dbus.Array([],
                                               signature=dbus.Signature('s'))
        # Add a timeout which removes the transaction from the bus if it
        # hasn't been setup and run for the TRANSACTION_IDLE_TIMEOUT period
        self._idle_watch = GLib.timeout_add_seconds(
            TRANSACTION_IDLE_TIMEOUT, self._remove_from_connection_no_raise)
        # Handle a disconnect of the client application
        self.sender_alive = True
        if bus:
            self._sender_watch = bus.watch_name_owner(
                sender, self._sender_owner_changed)
        else:
            self._sender_watch = None
        self.sender = sender
        self.output = ""
        self.simulated = None
        self._simulated_cb = None

    def _sender_owner_changed(self, connection):
        """Callback if the owner of the original sender changed, e.g.
        disconnected."""
        if not connection:
            self.sender_alive = False

    def _remove_from_connection_no_raise(self):
        """Version of remove_from_connection that does not raise if the
        object isn't exported.
        """
        log_trans.debug("Removing transaction")
        try:
            self.remove_from_connection()
        except LookupError as error:
            log_trans.debug("remove_from_connection() raised LookupError: "
                            "'%s'" % error)
        # Forget a not yet queued transaction
        try:
            self.queue.limbo.pop(self.tid)
        except KeyError:
            pass
        return False

    def _convert_struct(self, lst, signature):
        """Convert a list to a DBus struct with the given signature. Currently
        integer, long, unsigned long, double, string and boolean are
        supported (ixtdsb).
        """
        struct = []
        for num, item in enumerate(lst):
            try:
                if signature[num] == "i":
                    struct.append(dbus.Int32(item))
                elif signature[num] == "x":
                    struct.append(dbus.Int64(item))
                elif signature[num] == "t":
                    struct.append(dbus.UInt64(item))
                elif signature[num] == "d":
                    struct.append(dbus.Double(item))
                elif signature[num] == "b":
                    struct.append(dbus.Boolean(item))
                elif signature[num] == "s":
                    struct.append(get_dbus_string(item))
                else:
                    raise Exception("Value %s with unknown signature %s" %
                                    (item, signature[num]))
            except Exception as error:
                raise error.__class__("Failed to convert item %s of %s with "
                                      "signature %s: %s" % (num, lst,
                                                            signature,
                                                            str(error)))
        return dbus.Struct(struct, signature=dbus.Signature(signature))

    def _set_meta_data(self, data):
        # Perform some checks
        if self.status != enums.STATUS_SETTING_UP:
            raise errors.TransactionAlreadyRunning()
        if not isinstance(data, dbus.Dictionary):
            raise errors.InvalidMetaDataError("The data value has to be a "
                                              "dictionary: %s" % data)
        if not data.signature.startswith("s"):
            raise errors.InvalidMetaDataError("Only strings are accepted "
                                              "as keys.")
        for key, value in data.items():
            if key in self._meta_data:
                raise errors.InvalidMetaDataError("The key %s already "
                                                  "exists. It is not allowed "
                                                  "to overwrite existing "
                                                  "data." % key)
            if not len(key.split("_")) > 1:
                raise errors.InvalidMetaDataError("The key %s has to be of "
                                                  "the format "
                                                  "IDENTIFIER-KEYNAME")
            if not isinstance(value, dbus.String):
                raise errors.InvalidMetaDataError("The value has to be a "
                                                  "string: %s" % value)
        # Merge new data into existing one:
        self._meta_data.update(data)
        self.PropertyChanged("MetaData", self._meta_data)

    def _get_meta_data(self):
        return self._meta_data

    meta_data = property(_get_meta_data, _set_meta_data,
                         doc="Allows client applications to store meta data "
                             "for the transaction in a dictionary.")

    def _set_role(self, enum):
        if self._role != enums.ROLE_UNSET:
            raise errors.TransactionRoleAlreadySet()
        self._role = dbus.String(enum)
        self.PropertyChanged("Role", self._role)

    def _get_role(self):
        return self._role

    role = property(_get_role, _set_role, doc="Operation type of transaction.")

    def _set_progress_details(self, details):
        # items_done, total_items, bytes_done, total_bytes, speed, time
        self._progress_details = self._convert_struct(details, "iixxdx")
        self.PropertyChanged("ProgressDetails", self._progress_details)

    def _get_progress_details(self):
        return self._progress_details

    progress_details = property(_get_progress_details, _set_progress_details,
                                doc="Tuple containing detailed progress "
                                    "information: items done, total items, "
                                    "bytes done, total bytes, speed and "
                                    "remaining time")

    def _set_error(self, excep):
        self._error = excep
        msg = self.gettext(excep.details) % excep.details_args
        self._error_property = self._convert_struct((excep.code, msg), "ss")
        self.PropertyChanged("Error", self._error_property)

    def _get_error(self):
        return self._error

    error = property(_get_error, _set_error, doc="Raised exception.")

    def _set_exit(self, enum):
        self.status = enums.STATUS_FINISHED
        self._exit = dbus.String(enum)
        self.PropertyChanged("ExitState", self._exit)
        self.Finished(self._exit)
        if self._sender_watch:
            self._sender_watch.cancel()
        # Remove the transaction from the Bus after it is complete. A short
        # timeout helps lazy clients
        GLib.timeout_add_seconds(TRANSACTION_DEL_TIMEOUT,
                                 self._remove_from_connection_no_raise)

    def _get_exit(self):
        return self._exit

    exit = property(_get_exit, _set_exit,
                    doc="The exit state of the transaction.")

    def _get_download(self):
        return self._download

    def _set_download(self, size):
        self._download = dbus.Int64(size)
        self.PropertyChanged("Download", self._download)

    download = property(_get_download, _set_download,
                        doc="The download size of the transaction.")

    def _get_space(self):
        return self._space

    def _set_space(self, size):
        self._space = dbus.Int64(size)
        self.PropertyChanged("Space", self._space)

    space = property(_get_space, _set_space,
                     doc="The required disk space of the transaction.")

    def _set_packages(self, packages):
        self._packages = dbus.Struct([dbus.Array(pkgs, signature="s")
                                      for pkgs in packages],
                                     signature="as")
        self.PropertyChanged("Packages", self._packages)

    def _get_packages(self):
        return self._packages

    packages = property(_get_packages, _set_packages,
                        doc="Packages which will be explictly installed, "
                            "reinstalled, removed, purged, upgraded or "
                            "downgraded.")

    def _get_unauthenticated(self):
        return self._unauthenticated

    def _set_unauthenticated(self, unauthenticated):
        self._unauthenticated = dbus.Array(unauthenticated, signature="s")
        self.PropertyChanged("Unauthenticated", self._unauthenticated)

    unauthenticated = property(_get_unauthenticated, _set_unauthenticated,
                               doc="Unauthenticated packages in this "
                                   "transaction")

    # package that can have a different auth schema, useful for e.g.
    # lightweight packages like unity-webapps or packages comming from
    # a high trust repository (e.g. a internal company repo)
    def _get_high_trust_packages(self):
        return self._high_trust_packages

    def _set_high_trust_packages(self, whitelisted_packages):
        self._high_trust_packages = dbus.Array(whitelisted_packages,
                                               signature="s")
        self.PropertyChanged("HighTrustWhitelistedPackages",
                             self._high_trust_packages)

    high_trust_packages = property(_get_high_trust_packages,
                                   _set_high_trust_packages,
                                   doc="High trust packages in this "
                                       "transaction")

    def _get_depends(self):
        return self._depends

    def _set_depends(self, depends):
        self._depends = dbus.Struct([dbus.Array(deps, signature="s")
                                     for deps in depends],
                                    signature="as")
        self.PropertyChanged("Dependencies", self._depends)

    depends = property(_get_depends, _set_depends,
                       doc="The additional dependencies: installs, removals, "
                           "upgrades and downgrades.")

    def _get_status(self):
        return self._status

    def _set_status(self, enum):
        self._status = dbus.String(enum)
        self.PropertyChanged("Status", self._status)

    status = property(_get_status, _set_status,
                      doc="The status of the transaction.")

    def _get_status_details(self):
        return self._status_details

    def _set_status_details(self, text):
        self._status_details = get_dbus_string(text)
        self.PropertyChanged("StatusDetails", self._status_details)

    status_details = property(_get_status_details, _set_status_details,
                              doc="The status message from apt.")

    def _get_progress(self):
        return self._progress

    def _set_progress(self, percent):
        self._progress = dbus.Int32(percent)
        self.PropertyChanged("Progress", self._progress)

    progress = property(_get_progress, _set_progress,
                        "The progress of the transaction in percent.")

    def _get_progress_package(self):
        return self._progress_package

    def _set_progress_package(self, progress_package):
        self._progress_package = self._convert_struct(progress_package, "ss")

    progress_package = property(_get_progress_package,
                                _set_progress_package,
                                doc="The last progress update of a currently"
                                    "processed package. A tuple of package "
                                    "name and status enum.")

    def _get_progress_download(self):
        return self._progress_download

    def _set_progress_download(self, progress_download):
        self._progress_download = self._convert_struct(progress_download,
                                                       "sssxxs")
        self.PropertyChanged("ProgressDownload", self._progress_download)

    progress_download = property(_get_progress_download,
                                 _set_progress_download,
                                 doc="The last progress update of a currently"
                                     "running download. A tuple of URI, "
                                     "status, short description, full size, "
                                     "partially downloaded size and a status "
                                     "message.")

    def _get_cancellable(self):
        return self._cancellable

    def _set_cancellable(self, cancellable):
        self._cancellable = dbus.Boolean(cancellable)
        self.PropertyChanged("Cancellable", self._cancellable)

    cancellable = property(_get_cancellable, _set_cancellable,
                           doc="If it's currently allowed to cancel the "
                               "transaction.")

    def _get_term_attached(self):
        return self._term_attached

    def _set_term_attached(self, attached):
        self._term_attached = dbus.Boolean(attached)
        self.PropertyChanged("TerminalAttached", self._term_attached)

    term_attached = property(_get_term_attached, _set_term_attached,
                             doc="If the controlling terminal is currently "
                                 "attached to the dpkg call of the "
                                 "transaction.")

    def _get_required_medium(self):
        return self._required_medium

    def _set_required_medium(self, medium):
        self._required_medium = self._convert_struct(medium, "ss")
        self.PropertyChanged("RequiredMedium", self._required_medium)
        self.MediumRequired(*self._required_medium)

    required_medium = property(_get_required_medium, _set_required_medium,
                               doc="Tuple containing the label and the drive "
                                   "of a required CD/DVD to install packages "
                                   "from.")

    def _get_config_file_conflict(self):
        return self._config_file_conflict

    def _set_config_file_conflict(self, prompt):
        if prompt is None:
            self._config_file_conflict = dbus.Struct(("", ""), signature="ss")
            return
        self._config_file_conflict = self._convert_struct(prompt, "ss")
        self.PropertyChanged("ConfigFileConflict", self._config_file_conflict)
        self.ConfigFileConflict(*self._config_file_conflict)

    config_file_conflict = property(_get_config_file_conflict,
                                    _set_config_file_conflict,
                                    doc="Tuple containing the old and the new "
                                        "path of the configuration file")

    # Signals

    # pylint: disable-msg=C0103,C0322
    @dbus.service.signal(dbus_interface=APTDAEMON_TRANSACTION_DBUS_INTERFACE,
                         signature="sv")
    def PropertyChanged(self, property, value):
        """The signal gets emitted if a property of the transaction changed.

        :param property: The name of the property.
        :param value: The new value of the property.

        :type property: s
        :type value: v
        """
        log_trans.debug("Emitting PropertyChanged: %s, %s" % (property, value))

    # pylint: disable-msg=C0103,C0322
    @dbus.service.signal(dbus_interface=APTDAEMON_TRANSACTION_DBUS_INTERFACE,
                         signature="s")
    def Finished(self, exit_state):
        """The signal gets emitted if the transaction has been finished.

        :param exit_state: The exit state of the transaction, e.g.
            ``exit-failed``.
        :type exit_state: s
        """
        log_trans.debug("Emitting Finished: %s" %
                        enums.get_exit_string_from_enum(exit_state))

    # pylint: disable-msg=C0103,C0322
    @dbus.service.signal(dbus_interface=APTDAEMON_TRANSACTION_DBUS_INTERFACE,
                         signature="ss")
    def MediumRequired(self, medium, drive):
        """Set and emit the required medium change.

        This method/signal should be used to inform the user to
        insert the installation CD/DVD:

        Keyword arguments:
        medium -- the CD/DVD label
        drive -- mount point of the drive
        """
        log_trans.debug("Emitting MediumRequired: %s, %s" % (medium, drive))

    # pylint: disable-msg=C0103,C0322
    @dbus.service.signal(dbus_interface=APTDAEMON_TRANSACTION_DBUS_INTERFACE,
                         signature="ss")
    def ConfigFileConflict(self, old, new):
        """Set and emit the ConfigFileConflict signal.

        This method/signal should be used to inform the user to
        answer a config file prompt.

        Keyword arguments:
        old -- current version of the configuration prompt
        new -- new version of the configuration prompt
        """
        log_trans.debug("Emitting ConfigFileConflict: %s, %s" % (old, new))

    # Methods

    def _set_locale(self, locale_str):
        """Set the language and encoding.

        Keyword arguments:
        locale -- specifies language, territory and encoding according
                  to RFC 1766,  e.g. "de_DE.UTF-8"
        """
        if self.status != enums.STATUS_SETTING_UP:
            raise errors.TransactionAlreadyRunning()
        try:
            # ensure locale string is str() and not dbus.String()
            (lang, encoding) = locale._parse_localename(str(locale_str))
        except ValueError:
            raise
        else:
            if lang is None:
                lang = "C"
                self.locale = dbus.String(lang)
            else:
                self.locale = dbus.String("%s.%s" % (lang, encoding))
            self._translation = gettext.translation("aptdaemon",
                                                    fallback=True,
                                                    languages=[lang])
            self.PropertyChanged("locale", self.locale)

    @inline_callbacks
    def _set_http_proxy(self, url, sender):
        """Set an http network proxy.

        Keyword arguments:
        url -- the URL of the proxy server, e.g. http://proxy:8080
        """
        if url != "" and (not url.startswith("http://") or ":" not in url):
            raise errors.InvalidProxyError(url)
        action = policykit1.PK_ACTION_SET_PROXY
        yield policykit1.check_authorization_by_name(sender, action,
                                                     bus=self.bus)
        self.http_proxy = dbus.String(url)
        self.PropertyChanged("HttpProxy", self.http_proxy)

    def _set_remove_obsoleted_depends(self, remove_obsoleted_depends):
        """Set the handling of the removal of automatically installed
        dependencies which are now obsoleted.

        Keyword arguments:
        remove_obsoleted_depends -- If True also remove automatically installed
            dependencies of to removed packages
        """
        self.remove_obsoleted_depends = dbus.Boolean(remove_obsoleted_depends)
        self.PropertyChanged("RemoveObsoletedDepends",
                             self.remove_obsoleted_depends)

    def _set_allow_unauthenticated(self, allow_unauthenticated):
        """Set the handling of unauthenticated packages

        Keyword arguments:
        allow_unauthenticated -- True to allow packages that come from a
            repository without a valid authentication signature
        """
        self.allow_unauthenticated = dbus.Boolean(allow_unauthenticated)
        self.PropertyChanged("AllowUnauthenticated",
                             self.allow_unauthenticated)

    # pylint: disable-msg=C0103,C0322
    @dbus.service.method(APTDAEMON_TRANSACTION_DBUS_INTERFACE,
                         in_signature="s", out_signature="",
                         sender_keyword="sender")
    def RunAfter(self, tid, sender):
        """Queue the transaction for processing after the given transaction.

        The transaction will also fail if the previous one failed. Several
        transactions can be chained up.

        :param tid: The id of the transaction which should be executed
            before.

        :type tid: s
        """
        log_trans.info("Queuing transaction %s", self.tid)
        try:
            trans_before = self.queue.limbo[tid]
        except KeyError:
            raise Exception("The given transaction doesn't exist or is "
                            "already queued!")
        if trans_before.after:
            raise Exception("There is already an after transaction!")
        trans_before.after = self

    # pylint: disable-msg=C0103,C0322
    @dbus_deferred_method(APTDAEMON_TRANSACTION_DBUS_INTERFACE,
                          in_signature="", out_signature="",
                          sender_keyword="sender")
    def Run(self, sender):
        """Check the authentication, simulate and queue the transaction for
        processing."""
        log_trans.info("Queuing transaction %s", self.tid)
        return self._run(sender)

    @inline_callbacks
    def _run(self, sender):
        yield self._check_foreign_user(sender)
        yield self._check_simulated()
        yield self._check_auth()
        self.queue.put(self.tid)
        self.status = enums.STATUS_WAITING
        next_trans = self.after
        while next_trans:
            yield self._check_simulated()
            yield next_trans._check_auth()
            self.queue.put(next_trans.tid)
            next_trans.status = enums.STATUS_WAITING
            next_trans = next_trans.after

    @inline_callbacks
    def _check_simulated(self):
        # Simulate the new transaction if this has not been done before:
        # FIXME: Compare the simulated timestamp with the time stamp of
        #       the status and re-simulate the transaction
        if self.simulated is None:
            # If there isn't any transaction on the queue we send an early
            # progress information. Otherwise it juse seems that aptdaemon
            # hangs since it doesn't send any progress information after the
            # the transaction has been started
            if not self.queue.worker.trans:
                self.progress = 9
            yield self._simulate_real()
        else:
            raise StopIteration

    @inline_callbacks
    def _check_auth(self):
        """Check silently if one of the high level privileges has been granted
        before to reduce clicks to install packages from third party
        epositories: AddRepository -> UpdateCache -> InstallPackages
        """
        self.status = enums.STATUS_AUTHENTICATING
        action = self.ROLE_ACTION_MAP[self.role]
        if action is None:
            raise StopIteration
        # Special case if InstallPackages only touches stuff from the
        # high trust whitelist
        if (self.role in (enums.ROLE_INSTALL_PACKAGES,
                          enums.ROLE_COMMIT_PACKAGES) and
                trans_only_installs_pkgs_from_high_trust_repos(self)):
            action = policykit1.PK_ACTION_INSTALL_PACKAGES_FROM_HIGH_TRUST_REPO
        # Special case if CommitPackages only upgrades
        if (self.role == enums.ROLE_COMMIT_PACKAGES and
                not self.packages[enums.PKGS_INSTALL] and
                not self.packages[enums.PKGS_REINSTALL] and
                not self.packages[enums.PKGS_REMOVE] and
                not self.packages[enums.PKGS_PURGE] and
                not self.packages[enums.PKGS_DOWNGRADE]):
            action = policykit1.PK_ACTION_UPGRADE_PACKAGES
        try:
            authorized = yield self._check_alternative_auth()
            if not authorized:
                yield policykit1.check_authorization_by_name(self.sender,
                                                             action,
                                                             bus=self.bus)
        except errors.NotAuthorizedError as error:
            self.error = errors.TransactionFailed(enums.ERROR_NOT_AUTHORIZED,
                                                  str(error))
            self.exit = enums.EXIT_FAILED
            raise(error)
        except errors.AuthorizationFailed as error:
            self.error = errors.TransactionFailed(enums.ERROR_AUTH_FAILED,
                                                  str(error))
            self.exit = enums.EXIT_FAILED
            raise(error)

    @inline_callbacks
    def _check_alternative_auth(self):
        """Check non-interactively if one of the high level privileges
        has been granted.
        """
        if self.role not in [enums.ROLE_ADD_REPOSITORY,
                             enums.ROLE_ADD_VENDOR_KEY_FROM_KEYSERVER,
                             enums.ROLE_UPDATE_CACHE,
                             enums.ROLE_INSTALL_PACKAGES,
                             enums.ROLE_ADD_LICENSE_KEY]:
            return_value(False)
        flags = policykit1.CHECK_AUTH_NONE
        for action in [policykit1.PK_ACTION_INSTALL_PACKAGES_FROM_NEW_REPO,
                       policykit1.PK_ACTION_INSTALL_PURCHASED_PACKAGES]:
            try:
                yield policykit1.check_authorization_by_name(self.sender,
                                                             action,
                                                             bus=self.bus,
                                                             flags=flags)
            except errors.NotAuthorizedError:
                continue
            else:
                return_value(True)
        return_value(False)

    # pylint: disable-msg=C0103,C0322
    @dbus_deferred_method(APTDAEMON_TRANSACTION_DBUS_INTERFACE,
                          in_signature="", out_signature="",
                          sender_keyword="sender")
    def Cancel(self, sender):
        """Cancel the transaction."""
        log_trans.info("Cancelling transaction %s", self.tid)
        return self._cancel(sender)

    @inline_callbacks
    def _cancel(self, sender):
        try:
            yield self._check_foreign_user(sender)
        except errors.ForeignTransaction:
            action = policykit1.PK_ACTION_CANCEL_FOREIGN
            yield policykit1.check_authorization_by_name(sender, action,
                                                         bus=self.bus)
        try:
            self.queue.remove(self)
            log_trans.debug("Removed transaction from queue")
        except ValueError:
            pass
        else:
            self.status = enums.STATUS_CANCELLING
            self.exit = enums.EXIT_CANCELLED
            raise StopIteration
        if self.tid in self.queue.limbo:
            self.exit = enums.EXIT_CANCELLED
            raise StopIteration
        elif self.cancellable:
            log_trans.debug("Setting cancel event")
            self.cancelled = True
            self.status = enums.STATUS_CANCELLING
            self.paused = False
            raise StopIteration
        raise errors.AptDaemonError("Could not cancel transaction")

    # pylint: disable-msg=C0103,C0322
    @dbus_deferred_method(APTDAEMON_TRANSACTION_DBUS_INTERFACE,
                          in_signature="", out_signature="",
                          sender_keyword="sender")
    def Simulate(self, sender):
        """Simulate a transaction to update its dependencies, download size
        and required disk space.

        Call this method if you want to show changes before queuing the
        transaction.
        """
        log_trans.info("Simulate was called")
        return self._simulate(sender)

    @inline_callbacks
    def _simulate(self, sender):
        if self._simulated_cb:
            raise errors.TransactionAlreadySimulating()
        if self.status != enums.STATUS_SETTING_UP:
            raise errors.TransactionAlreadyRunning()
        yield self._check_foreign_user(sender)
        yield self._simulate_real()

    @inline_callbacks
    def _simulate_real(self):
        if self._simulated_cb:
            raise errors.TransactionAlreadySimulating()
        self.queue.worker.simulate(self)
        deferred = Deferred()
        if self._idle_watch is not None:
            GLib.source_remove(self._idle_watch)
        self._idle_watch = None
        self._simulated_cb = self.queue.worker.connect(
            "transaction-simulated",
            self._on_transaction_simulated,
            deferred)
        yield deferred

    def _on_transaction_simulated(self, worker, trans, deferred):
        if trans is not self:
            return
        self.queue.worker.disconnect(self._simulated_cb)
        self._simualted_cb = None
        if trans.error:
            deferred.errback(trans.error)
        else:
            deferred.callback()

    def _set_terminal(self, ttyname):
        """Set the controlling terminal.

        The worker will be attached to the specified slave end of a pty
        master/slave pair. This allows to interact with the

        Can only be changed before the transaction is started.

        Keyword arguments:
        ttyname -- file path to the slave file descriptor
        """
        if self.status != enums.STATUS_SETTING_UP:
            raise errors.TransactionAlreadyRunning()
        if not os.access(ttyname, os.W_OK):
            raise errors.AptDaemonError("Pty device does not exist: "
                                        "%s" % ttyname)
        if not os.stat(ttyname)[4] == self.uid:
            raise errors.AptDaemonError("Pty device '%s' has to be owned by"
                                        "the owner of the transaction "
                                        "(uid %s) " % (ttyname, self.uid))
        if os.path.dirname(ttyname) != "/dev/pts":
            raise errors.AptDaemonError("%s isn't a tty" % ttyname)
        try:
            slave_fd = os.open(ttyname, os.O_RDWR | os.O_NOCTTY)
            if os.isatty(slave_fd):
                self.terminal = dbus.String(ttyname)
                self.PropertyChanged("Terminal", self.terminal)
            else:
                raise errors.AptDaemonError("%s isn't a tty" % ttyname)
        finally:
            os.close(slave_fd)

    def _set_debconf(self, debconf_socket):
        """Set the socket of the debconf proxy.

        The worker process forwards all debconf commands through this
        socket by using the passthrough frontend. On the client side
        debconf-communicate should be connected to the socket.

        Can only be changed before the transaction is started.

        Keyword arguments:
        debconf_socket: absolute path to the socket
        """
        if self.status != enums.STATUS_SETTING_UP:
            raise errors.TransactionAlreadyRunning()
        if not os.access(debconf_socket, os.W_OK):
            raise errors.AptDaemonError("socket does not exist: "
                                        "%s" % debconf_socket)
        if not os.stat(debconf_socket)[4] == self.uid:
            raise errors.AptDaemonError("socket '%s' has to be owned by the "
                                        "owner of the "
                                        "transaction" % debconf_socket)
        self.debconf = dbus.String(debconf_socket)
        self.PropertyChanged("DebconfSocket", self.debconf)

    # pylint: disable-msg=C0103,C0322
    @dbus_deferred_method(APTDAEMON_TRANSACTION_DBUS_INTERFACE,
                          in_signature="s", out_signature="",
                          sender_keyword="sender")
    def ProvideMedium(self, medium, sender):
        """Continue paused transaction with the inserted medium.

        If a media change is required to install packages from CD/DVD
        the transaction will be paused and could be resumed with this
        method.

        :param medium: The label of the CD/DVD.
        :type medium: s
        """
        log_trans.info("Medium %s was provided", medium)
        return self._provide_medium(medium, sender)

    @inline_callbacks
    def _provide_medium(self, medium, sender):
        yield self._check_foreign_user(sender)
        if not self.required_medium:
            raise errors.AptDaemonError("There isn't any required medium.")
        if not self.required_medium[0] == medium:
            raise errors.AptDaemonError("The medium '%s' isn't "
                                        "requested." % medium)
        self.paused = False

    # pylint: disable-msg=C0103,C0322
    @dbus_deferred_method(APTDAEMON_TRANSACTION_DBUS_INTERFACE,
                          in_signature="ss", out_signature="",
                          sender_keyword="sender")
    def ResolveConfigFileConflict(self, config, answer, sender):
        """Resolve a configuration file conflict and continue the transaction.

        If a config file prompt is detected the transaction will be
        paused and could be resumed with this method.

        :param config: The path to the original config file.
        :param answer: The answer to the configuration file question, can be
            "keep" or "replace"

        :type config: s
        :type answer: s
        """
        log_trans.info("Resolved conflict of %s with %s", config, answer)
        return self._resolve_config_file_conflict(config, answer, sender)

    @inline_callbacks
    def _resolve_config_file_conflict(self, config, answer, sender):
        yield self._check_foreign_user(sender)
        if not self.config_file_conflict:
            raise errors.AptDaemonError("There isn't any config file prompt "
                                        "required")
        if answer not in ["keep", "replace"]:
            # FIXME: should we re-send the config file prompt
            #        message or assume the client is buggy and
            #        just use a safe default (like keep)?
            raise errors.AptDaemonError("Invalid value: %s" % answer)
        if not self.config_file_conflict[0] == config:
            raise errors.AptDaemonError("Invalid config file: %s" % config)
        self.config_file_conflict_resolution = answer
        self.paused = False

    @inline_callbacks
    def _set_property(self, iface, name, value, sender):
        """Helper to set a name on the properties D-Bus interface."""
        yield self._check_foreign_user(sender)
        if iface == APTDAEMON_TRANSACTION_DBUS_INTERFACE:
            if name == "MetaData":
                self._set_meta_data(value)
            elif name == "Terminal":
                self._set_terminal(value)
            elif name == "DebconfSocket":
                self._set_debconf(value)
            elif name == "Locale":
                self._set_locale(value)
            elif name == "RemoveObsoletedDepends":
                self._set_remove_obsoleted_depends(value)
            elif name == "AllowUnauthenticated":
                self._set_allow_unauthenticated(value)
            elif name == "HttpProxy":
                self._set_http_proxy(value, sender)
            else:
                raise dbus.exceptions.DBusException("Unknown or read only "
                                                    "property: %s" % name)
        else:
            raise dbus.exceptions.DBusException("Unknown interface: %s" %
                                                iface)

    def _get_properties(self, iface):
        """Helper to get the properties of a D-Bus interface."""
        if iface == APTDAEMON_TRANSACTION_DBUS_INTERFACE:
            return {"Role": self.role,
                    "Progress": self.progress,
                    "ProgressDetails": self.progress_details,
                    "ProgressDownload": self.progress_download,
                    "Status": self.status,
                    "StatusDetails": self.status_details,
                    "Cancellable": self.cancellable,
                    "TerminalAttached": self.term_attached,
                    "RequiredMedium": self.required_medium,
                    "ConfigFileConflict": self.config_file_conflict,
                    "ExitState": self.exit,
                    "Error": self._error_property,
                    "Locale": self.locale,
                    "Terminal": self.terminal,
                    "DebconfSocket": self.debconf,
                    "Paused": dbus.Boolean(self.paused),
                    "AllowUnauthenticated": self.allow_unauthenticated,
                    "RemoveObsoletedDepends": self.remove_obsoleted_depends,
                    "HttpProxy": self.http_proxy,
                    "Packages": self.packages,
                    "MetaData": self.meta_data,
                    "Dependencies": self.depends,
                    "Download": self.download,
                    "Space": self.space,
                    "Unauthenticated": self.unauthenticated,
                    }
        else:
            return {}

    @inline_callbacks
    def _check_foreign_user(self, dbus_name):
        """Check if the transaction is owned by the given caller."""
        uid = yield policykit1.get_uid_from_dbus_name(dbus_name, self.bus)
        if self.uid != uid:
            raise errors.ForeignTransaction()

    def _set_kwargs(self, kwargs):
        """Set the kwargs which will be send to the AptWorker."""
        self.kwargs = kwargs

    def _get_translations(self):
        """Get a usable translations object, no matter what."""
        if self._translation:
            return self._translation
        else:
            domain = "aptdaemon"
            return gettext.translation(domain, gettext.bindtextdomain(domain),
                                       gettext.bind_textdomain_codeset(domain),
                                       fallback=True)

    def gettext(self, msg):
        """Translate the given message to the language of the transaction.
        Fallback to the system default.
        """
        # Avoid showing the header of the mo file for an empty string
        if not msg:
            return ""
        translation = self._get_translations()
        return getattr(translation, _gettext_method)(msg)

    def ngettext(self, singular, plural, count):
        """Translate the given plural message to the language of the
        transaction. Fallback to the system default.
        """
        translation = self._get_translations()
        return getattr(translation, _ngettext_method)(singular, plural, count)


class TransactionQueue(GObject.GObject):

    """Queue for transactions."""

    __gsignals__ = {"queue-changed": (GObject.SignalFlags.RUN_FIRST,
                                      None,
                                      ())}

    def __init__(self, worker):
        """Intialize a new TransactionQueue instance."""
        GObject.GObject.__init__(self)
        self._queue = collections.deque()
        self._proc_count = 0
        self.worker = worker
        # Used to keep track of not yet queued transactions
        self.limbo = {}
        self.worker.connect("transaction-done", self._on_transaction_done)

    def __len__(self):
        return len(self._queue)

    def _emit_queue_changed(self):
        """Emit the queued-changed signal."""
        log.debug("emitting queue changed")
        self.emit("queue-changed")

    def put(self, tid):
        """Add an item to the queue."""
        trans = self.limbo.pop(tid)
        if trans._idle_watch is not None:
            GLib.source_remove(trans._idle_watch)
        if self.worker.trans:
            trans.status = enums.STATUS_WAITING
            self._queue.append(trans)
        else:
            self.worker.run(trans)
        self._emit_queue_changed()

    def _on_transaction_done(self, worker, trans):
        """Mark the last item as done and request a new item."""
        # FIXME: Check if the transaction failed because of a broken system or
        #       if dpkg journal is dirty. If so allready queued transactions
        #       except the repair transactions should be removed from the queue
        if trans.exit in [enums.EXIT_FAILED, enums.EXIT_CANCELLED]:
            if trans.exit == enums.EXIT_FAILED:
                exit = enums.EXIT_PREVIOUS_FAILED
            else:
                exit = enums.EXIT_CANCELLED
            _trans = trans.after
            while _trans:
                self.remove(_trans)
                _trans.exit = exit
                msg = enums.get_role_error_from_enum(trans.role)
                _trans.status_details = msg
                _trans = _trans.after
        try:
            next_trans = self._queue.popleft()
        except IndexError:
            log.debug("There isn't any queued transaction")
        else:
            self.worker.run(next_trans)
        self._emit_queue_changed()

    def remove(self, transaction):
        """Remove the specified item from the queue."""
        self._queue.remove(transaction)
        self._emit_queue_changed()

    def clear(self):
        """Remove all items from the queue."""
        for transaction in self._queue:
            transaction._remove_from_connection_no_raise()
        self._queue.clear()

    @property
    def items(self):
        """Return a list containing all queued items."""
        return list(self._queue)


class AptDaemon(DBusObject):

    """Provides a system daemon to process package management tasks.

    The daemon is transaction based. Each package management tasks runs
    in a separate transaction. The transactions can be created,
    monitored and managed via the D-Bus interface.
    """

    def __init__(self, options, connect=True, bus=None):
        """Initialize a new AptDaemon instance.

        Keyword arguments:
        options -- command line options of the type optparse.Values
        connect -- if the daemon should connect to the D-Bus (default is True)
        bus -- the D-Bus to connect to (defaults to the system bus)
        """
        log.info("Initializing daemon")
        # glib does not support SIGQUIT
        # GLib.unix_signal_add_full(
        #     GLib.PRIORITY_HIGH, signal.SIGQUIT, self._sigquit, None)
        GLib.unix_signal_add(GLib.PRIORITY_HIGH, signal.SIGTERM,
                             self._sigquit, None)
        # Decrease the priority of the daemon to avoid blocking UI
        os.nice(5)
        self.options = options
        self.packagekit = None
        if connect is True:
            if bus is None:
                bus = dbus.SystemBus()
            self.bus = bus
            bus_path = APTDAEMON_DBUS_PATH
            # Check if another object has already registered the name on
            # the bus. Quit the other daemon if replace would be set
            try:
                bus_name = dbus.service.BusName(APTDAEMON_DBUS_SERVICE,
                                                bus,
                                                do_not_queue=True)
            except dbus.exceptions.NameExistsException:
                if self.options.replace is False:
                    log.critical("Another daemon is already running")
                    sys.exit(1)
                log.warning("Replacing already running daemon")
                the_other_guy = bus.get_object(APTDAEMON_DBUS_SERVICE,
                                               APTDAEMON_DBUS_PATH)
                the_other_guy.Quit(dbus_interface=APTDAEMON_DBUS_INTERFACE,
                                   timeout=300)
                time.sleep(1)
                bus_name = dbus.service.BusName(APTDAEMON_DBUS_SERVICE,
                                                bus,
                                                do_not_queue=True)
        else:
            bus_name = None
            bus_path = None
        DBusObject.__init__(self, bus_name, bus_path)
        if options.dummy:
            self.worker = DummyWorker()
        else:
            load_plugins = not options.disable_plugins
            try:
                from .worker.pkworker import AptPackageKitWorker
                from . import pkcompat
            except ImportError:
                self.worker = AptWorker(options.chroot, load_plugins)
            else:
                self.worker = AptPackageKitWorker(options.chroot,
                                                  load_plugins)
        self.queue = TransactionQueue(self.worker)
        self.queue.connect("queue-changed", self._on_queue_changed)
        # keep state of the last information about reboot required
        self._reboot_required = self.worker.is_reboot_required()
        try:
            self.packagekit = pkcompat.PackageKit(self.queue, connect, bus)
        except dbus.exceptions.NameExistsException:
            log.warning("PackageKit is already running")
        except NameError:
            pass
        log.debug("Daemon was initialized")

    def _on_queue_changed(self, queue):
        """Callback for a changed transaction queue."""
        # check for reboot required
        if self.worker.is_reboot_required() != self._reboot_required:
            self._reboot_required = self.worker.is_reboot_required()
            self.PropertyChanged("RebootRequired", self._reboot_required)
        # check for the queue
        if self.queue.worker.trans:
            current = self.queue.worker.trans.tid
        else:
            current = ""
        queued = [trans.tid for trans in self.queue.items]
        self.ActiveTransactionsChanged(current, queued)

    # pylint: disable-msg=C0103,C0322
    @dbus.service.signal(dbus_interface=APTDAEMON_DBUS_INTERFACE,
                         signature="sv")
    def PropertyChanged(self, property, value):
        """The signal gets emitted if a property of the transaction changed.

        :param property: The name of the property.
        :param value: The new value of the property.

        :type property: s
        :type value: v
        """
        log.debug("Emitting PropertyChanged: %s, %s" % (property, value))

    # pylint: disable-msg=C0103,C0322
    @dbus.service.signal(dbus_interface=APTDAEMON_DBUS_INTERFACE,
                         signature="sas")
    def ActiveTransactionsChanged(self, current, queued):
        """The currently processed or the queued transactions changed.

        :param current: The path of the currently running transaction or
            an empty string.
        :param queued: List of the ids of the queued transactions.

        :type current: s
        :type queued: as
        """
        log.debug("Emitting ActiveTransactionsChanged signal: %s, %s",
                  current, queued)

    def run(self):
        """Start the daemon and listen for calls."""
        if self.options.disable_timeout is False:
            log.debug("Using inactivity check")
            GLib.timeout_add_seconds(APTDAEMON_IDLE_CHECK_INTERVAL,
                                     self._check_for_inactivity)
        log.debug("Waiting for calls")
        try:
            mainloop.run()
        except KeyboardInterrupt:
            self.Quit(None)

    @inline_callbacks
    def _create_trans(self, role, sender, packages=None, kwargs=None):
        """Helper method which returns the tid of a new transaction."""
        pid, uid, gid, cmdline = (
            yield policykit1.get_proc_info_from_dbus_name(sender, self.bus))
        tid = uuid.uuid4().hex
        trans = Transaction(
            tid, role, self.queue, pid, uid, gid, cmdline, sender,
            packages=packages, kwargs=kwargs, bus=self.bus)
        self.queue.limbo[trans.tid] = trans
        return_value(trans.tid)

    # pylint: disable-msg=C0103,C0322
    @dbus_deferred_method(APTDAEMON_DBUS_INTERFACE,
                          in_signature="", out_signature="s",
                          sender_keyword="sender")
    def FixIncompleteInstall(self, sender):
        """Try to complete cancelled installations. This is equivalent to a
        call of ``dpkg --configure -a``.

        Requires the ``org.debian.apt.install-or-remove-packages``
        :ref:`PolicyKit privilege <policykit>`.

        :returns: The D-Bus path of the new transaction object which
            performs this action.
        """
        log.info("FixIncompleteInstall() called")
        return self._create_trans(enums.ROLE_FIX_INCOMPLETE_INSTALL, sender)

    # pylint: disable-msg=C0103,C0322
    @dbus_deferred_method(APTDAEMON_DBUS_INTERFACE,
                          in_signature="", out_signature="s",
                          sender_keyword="sender")
    def FixBrokenDepends(self, sender):
        """Try to resolve unsatisfied dependencies of installed packages.

        Requires the ``org.debian.apt.install-or-remove-packages``
        :ref:`PolicyKit privilege <policykit>`.

        :returns: The D-Bus path of the new transaction object which
            performs this action.
        """
        log.info("FixBrokenDepends() called")
        return self._create_trans(enums.ROLE_FIX_BROKEN_DEPENDS, sender)

    # pylint: disable-msg=C0103,C0322
    @dbus_deferred_method(APTDAEMON_DBUS_INTERFACE,
                          in_signature="", out_signature="s",
                          sender_keyword="sender")
    def UpdateCache(self, sender):
        """Download the latest information about available packages from the
        repositories and rebuild the package cache.

        Requires the ``org.debian.apt.update-cache``
        :ref:`PolicyKit privilege <policykit>`.

        :returns: The D-Bus path of the new transaction object which
            performs this action.
        """
        log.info("UpdateCache() was called")
        kwargs = {"sources_list": None}
        return self._create_trans(enums.ROLE_UPDATE_CACHE, sender,
                                  kwargs=kwargs)

    # pylint: disable-msg=C0103,C0322
    @dbus_deferred_method(APTDAEMON_DBUS_INTERFACE,
                          in_signature="s", out_signature="s",
                          sender_keyword="sender")
    def UpdateCachePartially(self, sources_list, sender):
        """Update the cache from the repositories defined in the given
        sources.list only.

        Requires the ``org.debian.apt.update-cache``
        :ref:`PolicyKit privilege <policykit>`.

        :param sources_list: The absolute path to a sources.list, e.g.
            :file:`/etc/apt/sources.list.d/ppa-aptdaemon.list` or the name
            of the snippet in :file:`/etc/apt/sources.list.d/`, e.g.
            :file:`ppa-aptdaemon.list`.
        :type sources_list: s

        :returns: The D-Bus path of the new transaction object which
            performs this action.
         """
        log.info("UpdateCachePartially() was called")
        kwargs = {"sources_list": sources_list}
        return self._create_trans(enums.ROLE_UPDATE_CACHE, sender,
                                  kwargs=kwargs)

    # pylint: disable-msg=C0103,C0322
    @dbus_deferred_method(APTDAEMON_DBUS_INTERFACE,
                          in_signature="as", out_signature="s",
                          sender_keyword="sender")
    def RemovePackages(self, package_names, sender):
        """Remove the given packages from the system. The configuration files
        will be kept by default. Use :func:`CommitPackages()` to also purge the
        configuration files.

        Requires the ``org.debian.apt.install-or-packages``
        :ref:`PolicyKit privilege <policykit>`.

        :param package_names: packages to be removed
        :type package_names: as

        :returns: The D-Bus path of the new transaction object which
            performs this action.
        """
        log.info("RemovePackages() was called: '%s'", package_names)
        self._check_package_names(package_names)
        return self._create_trans(enums.ROLE_REMOVE_PACKAGES, sender,
                                  packages=([], [], package_names, [], [], []))

    # pylint: disable-msg=C0103,C0322
    @dbus_deferred_method(APTDAEMON_DBUS_INTERFACE,
                          in_signature="b", out_signature="s",
                          sender_keyword="sender")
    def UpgradeSystem(self, safe_mode, sender):
        """Apply all available upgrades and try to resolve conflicts.

        Requires the ``org.debian.apt.upgrade-packages``
        :ref:`PolicyKit privilege <policykit>`.

        :param safe_mode: If True only already installed packages will be
            updated. Updates which require to remove installed packages or to
            install additional packages will be skipped.

        :returns: The D-Bus path of the new transaction object which
            performs this action.
        """
        log.info("UpgradeSystem() was called with safe mode: "
                 "%s" % safe_mode)
        return self._create_trans(enums.ROLE_UPGRADE_SYSTEM, sender,
                                  kwargs={"safe_mode": safe_mode})

    # pylint: disable-msg=C0103,C0322
    @dbus_deferred_method(APTDAEMON_DBUS_INTERFACE,
                          in_signature="asasasasasas", out_signature="s",
                          sender_keyword="sender")
    def CommitPackages(self, install, reinstall, remove, purge, upgrade,
                       downgrade, sender):
        """Perform several package changes at the same time.

        The version number and target release of the packages can be specified
        using the traditional apt-get syntax, e.g. "xterm=281.1" to force
        installing the version 281.1 of xterm or "xterm/experimental" to
        force installing xterm from the experimental release.

        Requires the ``org.debian.apt.install-or-remove-packages``
        :ref:`PolicyKit privilege <policykit>`.

        :param install: Packages to be installed.
        :param reinstall: Packages to be re-installed
        :param remove: Packages to be removed
        :param purge: Package to be removed including theirs configuration
            files.
        :param upgrade: Packages to be upgraded.
        :param downgrade: Packages to be downgraded. You
            have to append the target version to the package name separated
            by "="

        :type install: as
        :type reinstall: as
        :type remove: as
        :type purge: as
        :type upgrade: as
        :type downgrade: as

        :returns: The D-Bus path of the new transaction object which
            performs this action.
        """
        # FIXME: take sha1 or md5 cash into accout to allow selecting a version
        #       or an origin different from the candidate
        log.info("CommitPackages() was called: %s, %s, %s, %s, %s, %s",
                 install, reinstall, remove, purge, upgrade, downgrade)

        def check_empty_list(lst):
            if lst == [""]:
                return []
            else:
                return lst
        packages_lst = [check_empty_list(lst) for lst in [install, reinstall,
                                                          remove, purge,
                                                          upgrade,
                                                          downgrade]]
        for packages in packages_lst:
            self._check_package_names(packages)
        return self._create_trans(enums.ROLE_COMMIT_PACKAGES, sender,
                                  packages=packages_lst)

    # pylint: disable-msg=C0103,C0322
    @dbus_deferred_method(APTDAEMON_DBUS_INTERFACE,
                          in_signature="as", out_signature="s",
                          sender_keyword="sender")
    def InstallPackages(self, package_names, sender):
        """Fetch and install the given packages from the repositories.

        The version number and target release of the packages can be specified
        using the traditional apt-get syntax, e.g. "xterm=281.1" to force
        installing the version 281.1 of xterm or "xterm/experimental" to
        force installing xterm from the experimental release.

        Requires the ``org.debian.apt.install-or-remove-packages``
        :ref:`PolicyKit privilege <policykit>`.

        :param package_names: Packages to be upgraded
        :type package_names: as

        :returns: The D-Bus path of the new transaction object which
            performs this action.
        """
        log.info("InstallPackages() was called: %s" % package_names)
        self._check_package_names(package_names)
        return self._create_trans(enums.ROLE_INSTALL_PACKAGES, sender,
                                  packages=(package_names, [], [], [], [], []))

    # pylint: disable-msg=C0103,C0322
    @dbus_deferred_method(APTDAEMON_DBUS_INTERFACE,
                          in_signature="as", out_signature="s",
                          sender_keyword="sender")
    def UpgradePackages(self, package_names, sender):
        """Upgrade the given packages to their latest version.

        The version number and target release of the packages can be specified
        using the traditional apt-get syntax, e.g. "xterm=281.1" to force
        installing the version 281.1 of xterm or "xterm/experimental" to
        force installing xterm from the experimental release.

        Requires the ``org.debian.apt.upgrade-packages``
        :ref:`PolicyKit privilege <policykit>`.

        :param package_names: Packages to be upgraded
        :type package_names: as

        :returns: The D-Bus path of the new transaction object which
            performs this action.
        """
        log.info("UpgradePackages() was called: %s" % package_names)
        self._check_package_names(package_names)
        return self._create_trans(enums.ROLE_UPGRADE_PACKAGES, sender,
                                  packages=([], [], [], [], package_names, []))

    # pylint: disable-msg=C0103,C0322
    @dbus_deferred_method(APTDAEMON_DBUS_INTERFACE,
                          in_signature="ss", out_signature="s",
                          sender_keyword="sender")
    def AddVendorKeyFromKeyserver(self, keyid, keyserver, sender):
        """Download and install the key of a software vendor. The key is
        used to authenticate packages of the vendor.

        Requires the ``org.debian.apt.change-repositories``
        :ref:`PolicyKit privilege <policykit>`.

        :param keyid: The id of the GnuPG key (e.g. 0x0EB12F05)
        :param keyserver: The server to get the key from (e.g.
            keyserver.ubuntu.com)

        :type keyid: s
        :type keyserver: s

        :returns: The D-Bus path of the new transaction object which
            performs this action.
        """
        log.info("InstallVendorKeyFromKeyserver() was called: %s %s",
                 keyid, keyserver)
        return self._create_trans(enums.ROLE_ADD_VENDOR_KEY_FROM_KEYSERVER,
                                  sender, kwargs={"keyid": keyid,
                                                  "keyserver": keyserver})

    # pylint: disable-msg=C0103,C0322
    @dbus_deferred_method(APTDAEMON_DBUS_INTERFACE,
                          in_signature="s", out_signature="s",
                          sender_keyword="sender")
    def AddVendorKeyFromFile(self, path, sender):
        """Install the key file of a software vendor. The key is
        used to authenticate packages of the vendor.

        Requires the ``org.debian.apt.change-repositories``
        :ref:`PolicyKit privilege <policykit>`.

        :param path: The absolute path to the key file.
        :type path: s

        :returns: The D-Bus path of the new transaction object which
            performs this action.
        """
        log.info("InstallVendorKeyFile() was called: %s" % path)
        return self._create_trans(enums.ROLE_ADD_VENDOR_KEY_FILE,
                                  sender, kwargs={"path": path})

    # pylint: disable-msg=C0103,C0322
    @dbus_deferred_method(APTDAEMON_DBUS_INTERFACE,
                          in_signature="s", out_signature="s",
                          sender_keyword="sender")
    def RemoveVendorKey(self, fingerprint, sender):
        """Remove the given key of a software vendor. The key is used to
        authenticate packages of the vendor.

        Requires the ``org.debian.apt.change-repositories``
        :ref:`PolicyKit privilege <policykit>`.

        :param fingerprint: The fingerprint of the key.
        :type fingerprint: s

        :returns: The D-Bus path of the new transaction object which
            performs this action.
        """
        log.info("RemoveVendorKey() was called: %s" % fingerprint)
        return self._create_trans(enums.ROLE_REMOVE_VENDOR_KEY,
                                  sender, kwargs={"fingerprint": fingerprint})

    # pylint: disable-msg=C0103,C0322
    @dbus_deferred_method(APTDAEMON_DBUS_INTERFACE,
                          in_signature="sb", out_signature="s",
                          sender_keyword="sender")
    def InstallFile(self, path, force, sender):
        """Install the given local package file.

        Requires the ``org.debian.apt.install-file``
        :ref:`PolicyKit privilege <policykit>`.

        :param path: The absolute path to the package file.
        :param force: If the installation of a package which violates the
            Debian/Ubuntu policy should be forced.

        :type path: s
        :type force: b

        :returns: The D-Bus path of the new transaction object which
            performs this action.
        """
        log.info("InstallFile() was called: %s" % path)
        # FIXME: Perform some checks
        # FIXME: Should we already extract the package name here?
        return self._create_trans(enums.ROLE_INSTALL_FILE,
                                  sender, kwargs={"path": path,
                                                  "force": force})

    # pylint: disable-msg=C0103,C0322
    @dbus_deferred_method(APTDAEMON_DBUS_INTERFACE,
                          in_signature="", out_signature="s",
                          sender_keyword="sender")
    def Clean(self, sender):
        """Remove downloaded package files.

        Requires the ``org.debian.apt.clean``
        :ref:`PolicyKit privilege <policykit>`.

        :returns: The D-Bus path of the new transaction object which
            performs this action.
        """
        log.info("Clean() was called")
        return self._create_trans(enums.ROLE_CLEAN, sender)

    # pylint: disable-msg=C0103,C0322
    @dbus_deferred_method(APTDAEMON_DBUS_INTERFACE,
                          in_signature="ass", out_signature="s",
                          sender_keyword="sender")
    def Reconfigure(self, packages, priority, sender):
        """Reconfigure already installed packages.

        Requires the ``org.debian.apt.install-or-remove-packages``
        :ref:`PolicyKit privilege <policykit>`.

        :param packages: List of package names which should be reconfigure.
        :param priority: The minimum debconf priority of question to be
            displayed. Can be of value "low", "medium", "high", "critical",
            "default".

        :type packages: as
        :type priority: s

        :returns: The D-Bus path of the new transaction object which
            performs this action.
        """
        log.info("Reconfigure() was called: %s" % " ".join(packages))
        return self._create_trans(enums.ROLE_RECONFIGURE, sender,
                                  packages=[[], packages, [], [], [], []],
                                  kwargs={"priority": priority})

    # pylint: disable-msg=C0103,C0322
    @dbus_deferred_method(APTDAEMON_DBUS_INTERFACE,
                          in_signature="sssasss", out_signature="s",
                          sender_keyword="sender")
    def AddRepository(self, src_type, uri, dist, comps, comment, sourcesfile,
                      sender):
        """Add given repository to the sources list.

        Requires the ``org.debian.apt.change-repositories``
        :ref:`PolicyKit privilege <policykit>`.

        :param src_type: The type of the repository (deb, deb-src).
        :param uri: The main repository URI
            (e.g. http://archive.ubuntu.com/ubuntu)
        :param dist: The distribution to use (e.g. stable or lenny-backports).
        :param comps: List of components (e.g. main, restricted).
        :param comment: A comment which should be added to the sources.list.
        :param sourcesfile: (Optoinal) filename in sources.list.d.

        :type src_type: s
        :type uri: s
        :type dist: s
        :type comps: as
        :type comment: s
        :type sourcesfile: s

        :returns: The D-Bus path of the new transaction object which
            performs this action.
        """
        log.info("AddRepository() was called: type='%s' uri='%s' "
                 "dist='%s' comps='%s' comment='%s' sourcesfile='%s'",
                 src_type, uri, dist, comps, comment, sourcesfile)
        return self._create_trans(enums.ROLE_ADD_REPOSITORY, sender,
                                  kwargs={"src_type": src_type, "uri": uri,
                                          "dist": dist, "comps": comps,
                                          "comment": comment,
                                          "sourcesfile": sourcesfile})

    # pylint: disable-msg=C0103,C0322
    @dbus_deferred_method(APTDAEMON_DBUS_INTERFACE,
                          in_signature="s", out_signature="s",
                          sender_keyword="sender")
    def EnableDistroComponent(self, component, sender):
        """Enable the component in the distribution repositories. This will
        not affect third-party repositories.

        The repositories of a distribution are often separated into
        different components because of policy reasons. E.g. Debian uses main
        for DFSG-free software and non-free for re-distributable but not free
        in the sense of the Debian Free Software Guidelines.

        Requires the ``org.debian.apt.change-repositories``
        :ref:`PolicyKit privilege <policykit>`.

        :param component: The component, e,g, main or non-free.
        :type component: s
        :returns: The D-Bus path of the new transaction object which
            performs this action.
        """
        log.info("EnableComponent() was called: component='%s' ", component)
        return self._create_trans(enums.ROLE_ENABLE_DISTRO_COMP, sender,
                                  kwargs={"component": component})

    # pylint: disable-msg=C0103,C0322
    @dbus_deferred_method(APTDAEMON_DBUS_INTERFACE,
                          in_signature="", out_signature="as",
                          sender_keyword="sender")
    def GetTrustedVendorKeys(self, sender):
        """Get the list of the installed vendor keys which are used to
        authenticate packages.

        Requires the ``org.debian.apt.get-trusted-vendor-keys``
        :ref:`PolicyKit privilege <policykit>`.

        :returns: Fingerprints of all installed keys.
        """
        log.info("GetTrustedVendorKeys() was called")
        return self._get_trusted_vendor_keys(sender)

    @inline_callbacks
    def _get_trusted_vendor_keys(self, sender):
        action = policykit1.PK_ACTION_GET_TRUSTED_VENDOR_KEYS
        yield policykit1.check_authorization_by_name(sender, action,
                                                     bus=self.bus)
        fingerprints = self.worker.get_trusted_vendor_keys()
        return_value(fingerprints)

    # pylint: disable-msg=C0103,C0322
    @dbus.service.method(APTDAEMON_DBUS_INTERFACE,
                         in_signature="", out_signature="sas")
    def GetActiveTransactions(self):
        """Return the currently running transaction and the list of queued
        transactions.
        """
        log.debug("GetActiveTransactions() was called")
        queued = [trans.tid for trans in self.queue.items]
        if self.queue.worker.trans:
            current = self.queue.worker.trans.tid
        else:
            current = ""
        return current, queued

    # pylint: disable-msg=C0103,C0322
    @dbus.service.method(APTDAEMON_DBUS_INTERFACE,
                         in_signature="", out_signature="",
                         sender_keyword="caller_name")
    def Quit(self, caller_name):
        """Request a shutdown of the daemon."""
        log.info("Quitting was requested")
        log.debug("Quitting main loop...")
        mainloop.quit()
        log.debug("Exit")

    # pylint: disable-msg=C0103,C0322
    @dbus_deferred_method(APTDAEMON_DBUS_INTERFACE,
                          in_signature="sss", out_signature="s",
                          sender_keyword="sender")
    def AddLicenseKey(self, pkg_name, json_token, server_name, sender):
        """Install a license key to use a piece of proprietary software.

        Requires the ``org.debian.apt.install-or-remove-packages``
        :ref:`PolicyKit privilege <policykit>`.

        :param pkg_name: The name of the package which requires the license
        :type pkg_name: s
        :param json_token: The oauth token to use with the server in
            json format
        :type pkg_name: s
        :param server_name: The name of the server to use (ubuntu-production,
            ubuntu-staging)
        :type pkg_name: s

        :returns: The D-Bus path of the new transaction object which
            performs this action.
        """
        log.info("AddLicenseKey() was called")
        return self._create_trans(enums.ROLE_ADD_LICENSE_KEY, sender,
                                  kwargs={'pkg_name': pkg_name,
                                          'json_token': json_token,
                                          'server_name': server_name})

    @inline_callbacks
    def _set_property(self, iface, name, value, sender):
        """Helper to set a property on the properties D-Bus interface."""
        action = policykit1.PK_ACTION_CHANGE_CONFIG
        yield policykit1.check_authorization_by_name(sender, action,
                                                     bus=self.bus)
        if iface == APTDAEMON_DBUS_INTERFACE:
            if name == "PopConParticipation":
                self.worker.set_config(name, dbus.Boolean(value))
            elif name == "AutoUpdateInterval":
                self.worker.set_config(name, dbus.Int32(value), "10periodic")
            elif name == "AutoDownload":
                self.worker.set_config(name, dbus.Boolean(value), "10periodic")
            elif name == "AutoCleanInterval":
                self.worker.set_config(name, dbus.Int32(value), "10periodic")
            elif name == "UnattendedUpgrade":
                self.worker.set_config(name, dbus.Boolean(value), "10periodic")
            else:
                raise dbus.exceptions.DBusException("Unknown or read only "
                                                    "property: %s" % name)
        else:
            raise dbus.exceptions.DBusException("Unknown interface: %s" %
                                                iface)

    def _check_package_names(self, pkg_names):
        """Check if the package names are valid. Otherwise raise an
        exception.
        """
        for fullname in pkg_names:
            name, version, release = split_package_id(fullname)
            name, sep, auto_flag = name.partition("#")
            if not auto_flag in ("", "auto"):
                raise errors.AptDaemonError("%s isn't a valid flag" %
                                            auto_flag)
            if not re.match(REGEX_VALID_PACKAGENAME, name):
                raise errors.AptDaemonError("%s isn't a valid package name" %
                                            name)
            if (version is not None and
                    not re.match(REGEX_VALID_VERSION, version)):
                raise errors.AptDaemonError("%s isn't a valid version" %
                                            version)
            if (release is not None and
                    not re.match(REGEX_VALID_RELEASE, release)):
                raise errors.AptDaemonError("%s isn't a valid release" %
                                            release)

    def _get_properties(self, iface):
        """Helper get the properties of a D-Bus interface."""
        if iface == APTDAEMON_DBUS_INTERFACE:
            return {
                "AutoUpdateInterval": dbus.Int32(
                    self.worker.get_config("AutoUpdateInterval")),
                "AutoDownload": dbus.Boolean(
                    self.worker.get_config("AutoDownload")),
                "AutoCleanInterval": dbus.Int32(
                    self.worker.get_config("AutoCleanInterval")),
                "UnattendedUpgrade": dbus.Int32(
                    self.worker.get_config("UnattendedUpgrade")),
                "PopConParticipation": dbus.Boolean(
                    self.worker.get_config("PopConParticipation")),
                "RebootRequired": dbus.Boolean(
                    self.worker.is_reboot_required())}
        else:
            return {}

    def _sigquit(self, data):
        """Internal callback for the quit signal."""
        self.Quit(None)

    def _check_for_inactivity(self):
        """Shutdown the daemon if it has been inactive for time specified
        in APTDAEMON_IDLE_TIMEOUT.
        """
        log.debug("Checking for inactivity")
        timestamp = self.queue.worker.last_action_timestamp
        if (not self.queue.worker.trans and
                not GLib.main_context_default().pending() and
                time.time() - timestamp > APTDAEMON_IDLE_TIMEOUT and
                not self.queue):
            log.info("Quitting due to inactivity")
            self.Quit(None)
            return False
        return True


def get_dbus_string(text, encoding="UTF-8"):
    """Convert the given string or unicode object to a dbus.String."""
    try:
        return dbus.String(text)
    except UnicodeDecodeError:
        return dbus.String(text.decode(encoding, "ignore"))


def main():
    """Allow to run the daemon from the command line."""
    parser = OptionParser()
    parser.add_option("-t", "--disable-timeout",
                      default=False,
                      action="store_true", dest="disable_timeout",
                      help=_("Do not shutdown the daemon because of "
                             "inactivity"))
    parser.add_option("", "--disable-plugins",
                      default=False,
                      action="store_true", dest="disable_plugins",
                      help=_("Do not load any plugins"))
    parser.add_option("-d", "--debug",
                      default=False,
                      action="store_true", dest="debug",
                      help=_("Show internal processing "
                             "information"))
    parser.add_option("-r", "--replace",
                      default=False,
                      action="store_true", dest="replace",
                      help=_("Quit and replace an already running "
                             "daemon"))
    parser.add_option("", "--session-bus",
                      default=False,
                      action="store_true", dest="session_bus",
                      help=_("Listen on the DBus session bus (Only required "
                             "for testing"))
    parser.add_option("", "--chroot", default=None,
                      action="store", type="string", dest="chroot",
                      help=_("Perform operations in the given "
                             "chroot"))
    parser.add_option("-p", "--profile",
                      default=False,
                      action="store", type="string", dest="profile",
                      help=_("Store profile stats in the specified "
                             "file"))
    parser.add_option("--dummy",
                      default=False,
                      action="store_true", dest="dummy",
                      help=_("Do not make any changes to the system (Only "
                             "of use to developers)"))
    options, args = parser.parse_args()
    if options.debug is True:
        log.setLevel(logging.DEBUG)
    else:
        log.setLevel(logging.INFO)
        _console_handler.setLevel(logging.INFO)
    if options.session_bus:
        bus = dbus.SessionBus()
    else:
        bus = None
    daemon = AptDaemon(options, bus=bus)
    if options.profile:
        import profile
        profiler = profile.Profile()
        profiler.runcall(daemon.run)
        profiler.dump_stats(options.profile)
        profiler.print_stats()
    else:
        daemon.run()

# vim:ts=4:sw=4:et
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              """Apport integration to provide better problem reports."""
# Copyright (C) 2010 Sebastian Heinlein <devel@glatzor.de>
#
# Licensed under the GNU General Public License Version 2
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

__author__ = "Sebastian Heinlein <devel@glatzor.de>"

__all__ = ("create_report")

import os

import apport
import apport.fileutils
import apt_pkg

from . import enums


def create_report(error, traceback, trans=None):
    """Create an apport problem report for a given crash.

    :param error: The summary of the error.
    :param traceback: The traceback of the exception.
    :param trans: The optional transaction in which the crash occured.
    """
    if not apport.packaging.enabled() or os.getcwd() != "/":
        return

    uid = 0
    report = apport.Report("Crash")
    report["Title"] = error
    package = "aptdaemon"
    try:
        package_version = apport.packaging.get_version(package)
    except ValueError as e:
        if 'does not exist' in e.message:
            package_version = 'unknown'
    report['Package'] = '%s %s' % (package, package_version)
    report["SourcePackage"] = "aptdaemon"
    report["Traceback"] = traceback
    report["ExecutablePath"] = "/usr/sbin/aptd"
    report.add_os_info()

    # Attach information about the transaction
    if trans:
        report["Annotation"] = enums.get_role_error_from_enum(trans.role)
        report["TransactionRole"] = trans.role
        report["TransactionPackages"] = str([list(l) for l in trans.packages])
        report["TransactionDepends"] = str([list(l) for l in trans.depends])
        report["TransactionKwargs"] = str(trans.kwargs)
        report["TransactionLocale"] = trans.locale
        report["TransactionOutput"] = trans.output
        report["TransactionErrorCode"] = trans._error_property[0]
        report["TransactionErrorDetails"] = trans._error_property[1]
        uid = os.path.basename(trans.tid)

    # Write report
    report_path = apport.fileutils.make_report_path(report, uid)
    if not os.path.exists(report_path):
        report.write(open(report_path, 'wb'))

if __name__ == "__main__":
    apt_pkg.init_config()
    create_report('test', 'testtrace')

# vim:ts=4:sw=4:et
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          #!/usr/bin/env python
# -*- coding: utf-8 -*-
"""enums - Enumerates for apt daemon dbus messages"""
# Copyright (C) 2008-2009 Sebastian Heinlein <devel@glatzor.de>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

__author__ = "Sebastian Heinlein <devel@glatzor.de>"

__all__ = ("PKGS_INSTALL", "PKGS_REINSTALL", "PKGS_REMOVE", "PKGS_PURGE",
           "PKGS_UPGRADE", "PKGS_DOWNGRADE", "PKGS_KEEP",
           "EXIT_SUCCESS", "EXIT_CANCELLED", "EXIT_FAILED", "EXIT_UNFINISHED",
           "ERROR_PACKAGE_DOWNLOAD_FAILED", "ERROR_REPO_DOWNLOAD_FAILED",
           "ERROR_DEP_RESOLUTION_FAILED",
           "ERROR_KEY_NOT_INSTALLED", "ERROR_KEY_NOT_REMOVED", "ERROR_NO_LOCK",
           "ERROR_NO_CACHE", "ERROR_NO_PACKAGE", "ERROR_PACKAGE_UPTODATE",
           "ERROR_PACKAGE_NOT_INSTALLED", "ERROR_PACKAGE_ALREADY_INSTALLED",
           "ERROR_NOT_REMOVE_ESSENTIAL_PACKAGE", "ERROR_DAEMON_DIED",
           "ERROR_PACKAGE_MANAGER_FAILED", "ERROR_CACHE_BROKEN",
           "ERROR_PACKAGE_UNAUTHENTICATED", "ERROR_INCOMPLETE_INSTALL",
           "ERROR_UNREADABLE_PACKAGE_FILE", "ERROR_INVALID_PACKAGE_FILE",
           "ERROR_SYSTEM_ALREADY_UPTODATE", "ERROR_NOT_SUPPORTED",
           "ERROR_LICENSE_KEY_INSTALL_FAILED",
           "ERROR_LICENSE_KEY_DOWNLOAD_FAILED",
           "ERROR_AUTH_FAILED", "ERROR_NOT_AUTHORIZED",
           "ERROR_UNKNOWN",
           "STATUS_SETTING_UP", "STATUS_WAITING", "STATUS_WAITING_MEDIUM",
           "STATUS_WAITING_CONFIG_FILE_PROMPT", "STATUS_WAITING_LOCK",
           "STATUS_RUNNING", "STATUS_LOADING_CACHE", "STATUS_DOWNLOADING",
           "STATUS_COMMITTING", "STATUS_CLEANING_UP", "STATUS_RESOLVING_DEP",
           "STATUS_FINISHED", "STATUS_CANCELLING", "STATUS_QUERY",
           "STATUS_DOWNLOADING_REPO", "STATUS_AUTHENTICATING",
           "ROLE_UNSET", "ROLE_INSTALL_PACKAGES", "ROLE_INSTALL_FILE",
           "ROLE_UPGRADE_PACKAGES", "ROLE_UPGRADE_SYSTEM", "ROLE_UPDATE_CACHE",
           "ROLE_REMOVE_PACKAGES", "ROLE_COMMIT_PACKAGES",
           "ROLE_ADD_VENDOR_KEY_FILE", "ROLE_ADD_VENDOR_KEY_FROM_KEYSERVER",
           "ROLE_REMOVE_VENDOR_KEY", "ROLE_FIX_INCOMPLETE_INSTALL",
           "ROLE_FIX_BROKEN_DEPENDS", "ROLE_ADD_REPOSITORY",
           "ROLE_ENABLE_DISTRO_COMP", "ROLE_CLEAN", "ROLE_RECONFIGURE",
           "ROLE_PK_QUERY", "ROLE_ADD_LICENSE_KEY",
           "DOWNLOAD_DONE", "DOWNLOAD_AUTH_ERROR", "DOWNLOAD_ERROR",
           "DOWNLOAD_FETCHING", "DOWNLOAD_IDLE", "DOWNLOAD_NETWORK_ERROR",
           "PKG_INSTALLING", "PKG_CONFIGURING", "PKG_REMOVING",
           "PKG_PURGING", "PKG_UPGRADING", "PKG_RUNNING_TRIGGER",
           "PKG_DISAPPEARING", "PKG_PREPARING_REMOVE", "PKG_PREPARING_INSTALL",
           "PKG_PREPARING_PURGE", "PKG_PREPARING_PURGE", "PKG_INSTALLED",
           "PKG_REMOVED", "PKG_PURGED", "PKG_UNPACKING", "PKG_UNKNOWN",
           "get_status_icon_name_from_enum", "get_role_icon_name_from_enum",
           "get_status_animation_name_from_enum",
           "get_package_status_from_enum",
           "get_role_localised_past_from_enum", "get_exit_string_from_enum",
           "get_role_localised_present_from_enum", "get_role_error_from_enum",
           "get_error_description_from_enum", "get_error_string_from_enum",
           "get_status_string_from_enum", "get_download_status_from_enum")

import gettext


def _(msg):
    return gettext.dgettext("aptdaemon", msg)

# PACKAGE GROUP INDEXES
#: Index of the list of to be installed packages in the :attr:`dependencies`
#: and :attr:`packages` property of :class:`~aptdaemon.client.AptTransaction`.
PKGS_INSTALL = 0
#: Index of the list of to be re-installed packages in the :attr:`dependencies`
#: and :attr:`packages` property of :class:`~aptdaemon.client.AptTransaction`.
PKGS_REINSTALL = 1
#: Index of the list of to be removed packages in the :attr:`dependencies`
#: and :attr:`packages` property of :class:`~aptdaemon.client.AptTransaction`.
PKGS_REMOVE = 2
#: Index of the list of to be purged packages in the :attr:`dependencies`
#: and :attr:`packages` property of :class:`~aptdaemon.client.AptTransaction`.
PKGS_PURGE = 3
#: Index of the list of to be upgraded packages in the :attr:`dependencies`
#: and :attr:`packages` property of :class:`~aptdaemon.client.AptTransaction`.
PKGS_UPGRADE = 4
#: Index of the list of to be downgraded packages in the :attr:`dependencies`
#: and :attr:`packages` property of :class:`~aptdaemon.client.AptTransaction`.
PKGS_DOWNGRADE = 5
#: Index of the list of to be keept packages in the :attr:`dependencies`
#: property of :class:`~aptdaemon.client.AptTransaction`.
PKGS_KEEP = 6

# FINISH STATES
#: The transaction was successful.
EXIT_SUCCESS = "exit-success"
#: The transaction has been cancelled by the user.
EXIT_CANCELLED = "exit-cancelled"
#: The transaction has failed.
EXIT_FAILED = "exit-failed"
#: The transaction failed since a previous one in a chain failed.
EXIT_PREVIOUS_FAILED = "exit-previous-failed"
#: The transaction is still being queued or processed.
EXIT_UNFINISHED = "exit-unfinished"

# ERROR CODES
#: Failed to download package files which should be installed.
ERROR_PACKAGE_DOWNLOAD_FAILED = "error-package-download-failed"
#: Failed to download package information (index files) from the repositories
ERROR_REPO_DOWNLOAD_FAILED = "error-repo-download-failed"
#: Failed to satisfy the dependencies or conflicts of packages.
ERROR_DEP_RESOLUTION_FAILED = "error-dep-resolution-failed"
#: The requested vendor key is not installed.
ERROR_KEY_NOT_INSTALLED = "error-key-not-installed"
#: The requested vendor could not be removed.
ERROR_KEY_NOT_REMOVED = "error-key-not-removed"
#: The package management system could not be locked. Eventually another
#: package manager is running.
ERROR_NO_LOCK = "error-no-lock"
#: The package cache could not be opened. This indicates a serious problem
#: on the system.
ERROR_NO_CACHE = "error-no-cache"
#: The requested package is not available.
ERROR_NO_PACKAGE = "error-no-package"
#: The package could not be upgraded since it is already up-to-date.
ERROR_PACKAGE_UPTODATE = "error-package-uptodate"
#: The package which was requested to install is already installed.
ERROR_PACKAGE_ALREADY_INSTALLED = "error-package-already-installed"
#: The package could not be removed since it is not installed.
ERROR_PACKAGE_NOT_INSTALLED = "error-package-not-installed"
#: It is not allowed to remove an essential system package.
ERROR_NOT_REMOVE_ESSENTIAL_PACKAGE = "error-not-remove-essential"
#: The aptdaemon crashed or could not be connected to on the D-Bus.
ERROR_DAEMON_DIED = "error-daemon-died"
#: On of the maintainer scripts during the dpkg call failed.
ERROR_PACKAGE_MANAGER_FAILED = "error-package-manager-failed"
#: There are packages with broken dependencies installed on the system.
#: This has to fixed before performing another transaction.
ERROR_CACHE_BROKEN = "error-cache-broken"
#: It is not allowed to install an unauthenticated packages. Packages are
#: authenticated by installing the vendor key.
ERROR_PACKAGE_UNAUTHENTICATED = "error-package-unauthenticated"
#: A previous installation has been aborted and is now incomplete.
#: Should be fixed by `dpkg --configure -a` or the :func:`FixIncomplete()`
#: transaction.
ERROR_INCOMPLETE_INSTALL = "error-incomplete-install"
#: Failed to open and read the package file
ERROR_UNREADABLE_PACKAGE_FILE = "error-unreadable-package-file"
#: The package file violates the Debian/Ubuntu policy
ERROR_INVALID_PACKAGE_FILE = "error-invalid-package-file"
#: The requested feature is not supported yet (mainly used by PackageKit
ERROR_NOT_SUPPORTED = "error-not-supported"
#: The license key download failed
ERROR_LICENSE_KEY_DOWNLOAD_FAILED = "error-license-key-download-failed"
#: The license key is invalid
ERROR_LICENSE_KEY_INSTALL_FAILED = "error-license-key-install-failed"
#: The system is already up-to-date and don't needs any upgrades
ERROR_SYSTEM_ALREADY_UPTODATE = "error-system-already-uptodate"
#: The user isn't allowed to perform the action at all
ERROR_NOT_AUTHORIZED = "error-not-authorized"
#: The user could not be authorized (e.g. wrong password)
ERROR_AUTH_FAILED = "error-auth-failed"
#: An unknown error occured. In most cases these are programming ones.
ERROR_UNKNOWN = "error-unknown"

# TRANSACTION STATES
#: The transaction was created, but hasn't been queued.
STATUS_SETTING_UP = "status-setting-up"
#: The transaction performs a query
STATUS_QUERY = "status-query"
#: The transaction is waiting in the queue.
STATUS_WAITING = "status-waiting"
#: The transaction is paused and waits until a required medium is inserted.
#: See :func:`ProvideMedium()`.
STATUS_WAITING_MEDIUM = "status-waiting-medium"
#: The transaction is paused and waits for the user to resolve a configuration
#: file conflict. See :func:`ResolveConfigFileConflict()`.
STATUS_WAITING_CONFIG_FILE_PROMPT = "status-waiting-config-file-prompt"
#: Wait until the package management system can be locked. Most likely
#: another package manager is running currently.
STATUS_WAITING_LOCK = "status-waiting-lock"
#: The processing of the transaction has started.
STATUS_RUNNING = "status-running"
#: The package cache is opened.
STATUS_LOADING_CACHE = "status-loading-cache"
#: The information about available packages is downloaded
STATUS_DOWNLOADING_REPO = "status-downloading-repo"
#: The required package files to install are getting downloaded.
STATUS_DOWNLOADING = "status-downloading"
#: The actual installation/removal takes place.
STATUS_COMMITTING = "status-committing"
#: The package management system is cleaned up.
STATUS_CLEANING_UP = "status-cleaning-up"
#: The dependecies and conflicts are now getting resolved.
STATUS_RESOLVING_DEP = "status-resolving-dep"
#: The transaction has been completed.
STATUS_FINISHED = "status-finished"
#: The transaction has been cancelled.
STATUS_CANCELLING = "status-cancelling"
#: The transaction waits for authentication
STATUS_AUTHENTICATING = "status-authenticating"

# PACKAGE STATES
#: The package gets unpacked
PKG_UNPACKING = "pkg-unpacking"
#: The installation of the package gets prepared
PKG_PREPARING_INSTALL = "pkg-preparing-install"
#: The package is installed
PKG_INSTALLED = "pkg-installed"
#: The package gets installed
PKG_INSTALLING = "pkg-installing"
#: The configuration of the package gets prepared
PKG_PREPARING_CONFIGURE = "pkg-preparing-configure"
#: The package gets configured
PKG_CONFIGURING = "pkg-configuring"
#: The removal of the package gets prepared
PKG_PREPARING_REMOVE = "pkg-preparing-removal"
#: The package gets removed
PKG_REMOVING = "pkg-removing"
#: The package is removed
PKG_REMOVED = "pkg-removed"
#: The purging of the package gets prepared
PKG_PREPARING_PURGE = "pkg-preparing-purge"
#: The package gets purged
PKG_PURGING = "pkg-purging"
#: The package was completely removed
PKG_PURGED = "pkg-purged"
#: The post installation trigger of the package is processed
PKG_RUNNING_TRIGGER = "pkg-running-trigger"
#: The package disappered - very rare
PKG_DISAPPEARING = "pkg-disappearing"
#: The package gets upgraded
PKG_UPGRADING = "pkg-upgrading"
#: Failed to get a current status of the package
PKG_UNKNOWN = "pkg-unknown"

# TRANSACTION ROLES
#: The role of the transaction has not been specified yet.
ROLE_UNSET = "role-unset"
#: The transaction performs a query compatible to the PackageKit interface
ROLE_PK_QUERY = "role-pk-query"
#: The transaction will install one or more packages.
ROLE_INSTALL_PACKAGES = "role-install-packages"
#: The transaction will install a local package file.
ROLE_INSTALL_FILE = "role-install-file"
#: The transaction will upgrade one or more packages.
ROLE_UPGRADE_PACKAGES = "role-upgrade-packages"
#: The transaction will perform a system upgrade.
ROLE_UPGRADE_SYSTEM = "role-upgrade-system"
#: The transaction will update the package cache.
ROLE_UPDATE_CACHE = "role-update-cache"
#: The transaction will remove one or more packages.
ROLE_REMOVE_PACKAGES = "role-remove-packages"
#: The transaction will perform a combined install, remove, upgrade or
#: downgrade action.
ROLE_COMMIT_PACKAGES = "role-commit-packages"
#: The transaction will add a local vendor key file to authenticate packages.
ROLE_ADD_VENDOR_KEY_FILE = "role-add-vendor-key-file"
#: The transaction will download vendor key to authenticate packages from
#: a keyserver.
ROLE_ADD_VENDOR_KEY_FROM_KEYSERVER = "role-add-vendor-key-from-keyserver"
#: The transaction will remove a vendor key which was used to authenticate
#: packages.
ROLE_REMOVE_VENDOR_KEY = "role-remove-vendor-key"
#: The transaction will try to finish a previous aborted installation.
ROLE_FIX_INCOMPLETE_INSTALL = "role-fix-incomplete-install"
#: The transaction will to resolve broken dependencies of already installed
#: packages.
ROLE_FIX_BROKEN_DEPENDS = "role-fix-broken-depends"
#: The transaction will enable a repository to download software from.
ROLE_ADD_REPOSITORY = "role-add-repository"
#: The transaction will enable a component in the distro repositories,
#: e.g main or universe
ROLE_ENABLE_DISTRO_COMP = "role-enable-distro-comp"
#: The transaction will reconfigure the given already installed packages
ROLE_RECONFIGURE = "role-reconfigure"
#: The transaction will remove all downloaded package files.
ROLE_CLEAN = "role-clean"
#: The transaction will add a license key to the system
ROLE_ADD_LICENSE_KEY = "role-add-license-key"

# DOWNLOAD STATES
#: The download has been completed.
DOWNLOAD_DONE = "download-done"
#: The file could not be downloaded since the authentication for the repository
#: failed.
DOWNLOAD_AUTH_ERROR = "download-auth-error"
#: There file could not be downloaded, e.g. because it is not available (404).
DOWNLOAD_ERROR = "download-error"
#: The file is currently being downloaded.
DOWNLOAD_FETCHING = "download-fetching"
#: The download is currently idling.
DOWNLOAD_IDLE = "download-idle"
#: The download failed since there seem to be a networking problem.
DOWNLOAD_NETWORK_ERROR = "download-network-error"

_ICONS_STATUS = {
    STATUS_CANCELLING: 'aptdaemon-cleanup',
    STATUS_CLEANING_UP: 'aptdaemon-cleanup',
    STATUS_RESOLVING_DEP: 'aptdaemon-resolve',
    STATUS_COMMITTING: 'aptdaemon-working',
    STATUS_DOWNLOADING: 'aptdaemon-download',
    STATUS_DOWNLOADING_REPO: 'aptdaemon-download',
    STATUS_FINISHED: 'aptdaemon-cleanup',
    STATUS_LOADING_CACHE: 'aptdaemon-update-cache',
    STATUS_RUNNING: 'aptdaemon-working',
    STATUS_SETTING_UP: 'aptdaemon-working',
    STATUS_WAITING: 'aptdaemon-wait',
    STATUS_WAITING_LOCK: 'aptdaemon-wait',
    STATUS_WAITING_MEDIUM: 'aptdaemon-wait',
    STATUS_WAITING_CONFIG_FILE_PROMPT:  'aptdaemon-wait'}

_ICONS_ROLE = {
    ROLE_INSTALL_FILE: 'aptdaemon-add',
    ROLE_INSTALL_PACKAGES: 'aptdaemon-add',
    ROLE_UPDATE_CACHE: 'aptdaemon-update-cache',
    ROLE_REMOVE_PACKAGES: 'aptdaemon-delete',
    ROLE_UPGRADE_PACKAGES: 'aptdaemon-upgrade',
    ROLE_UPGRADE_SYSTEM: 'system-software-update'}

_ANIMATIONS_STATUS = {
    STATUS_CANCELLING: 'aptdaemon-action-cleaning-up',
    STATUS_CLEANING_UP: 'aptdaemon-action-cleaning-up',
    STATUS_RESOLVING_DEP: 'aptdaemon-action-resolving',
    STATUS_DOWNLOADING: 'aptdaemon-action-downloading',
    STATUS_DOWNLOADING_REPO: 'aptdaemon-action-downloading',
    STATUS_LOADING_CACHE: 'aptdaemon-action-updating-cache',
    STATUS_WAITING: 'aptdaemon-action-waiting',
    STATUS_WAITING_LOCK: 'aptdaemon-action-waiting',
    STATUS_WAITING_MEDIUM: 'aptdaemon-action-waiting',
    STATUS_WAITING_CONFIG_FILE_PROMPT: 'aptdaemon-action-waiting'}

_PAST_ROLE = {
    ROLE_INSTALL_FILE: _("Installed file"),
    ROLE_INSTALL_PACKAGES: _("Installed packages"),
    ROLE_ADD_VENDOR_KEY_FILE: _("Added key from file"),
    ROLE_UPDATE_CACHE: _("Updated cache"),
    ROLE_PK_QUERY: _("Search done"),
    ROLE_REMOVE_VENDOR_KEY: _("Removed trusted key"),
    ROLE_REMOVE_PACKAGES: _("Removed packages"),
    ROLE_UPGRADE_PACKAGES: _("Updated packages"),
    ROLE_UPGRADE_SYSTEM: _("Upgraded system"),
    ROLE_COMMIT_PACKAGES: _("Applied changes"),
    ROLE_FIX_INCOMPLETE_INSTALL: _("Repaired incomplete installation"),
    ROLE_FIX_BROKEN_DEPENDS: _("Repaired broken dependencies"),
    ROLE_ADD_REPOSITORY: _("Added software source"),
    ROLE_ENABLE_DISTRO_COMP: _("Enabled component of the distribution"),
    ROLE_CLEAN: _("Removed downloaded package files"),
    ROLE_RECONFIGURE: _("Reconfigured installed packages"),
    ROLE_UNSET: ""}

_STRING_EXIT = {
    EXIT_SUCCESS: _("Successful"),
    EXIT_CANCELLED: _("Canceled"),
    EXIT_FAILED: _("Failed")}

_PRESENT_ROLE = {
    ROLE_INSTALL_FILE: _("Installing file"),
    ROLE_INSTALL_PACKAGES: _("Installing packages"),
    ROLE_ADD_VENDOR_KEY_FILE: _("Adding key from file"),
    ROLE_UPDATE_CACHE: _("Updating cache"),
    ROLE_REMOVE_VENDOR_KEY: _("Removing trusted key"),
    ROLE_REMOVE_PACKAGES: _("Removing packages"),
    ROLE_UPGRADE_PACKAGES: _("Updating packages"),
    ROLE_UPGRADE_SYSTEM: _("Upgrading system"),
    ROLE_COMMIT_PACKAGES: _("Applying changes"),
    ROLE_FIX_INCOMPLETE_INSTALL: _("Repairing incomplete installation"),
    ROLE_FIX_BROKEN_DEPENDS: _("Repairing installed software"),
    ROLE_ADD_REPOSITORY: _("Adding software source"),
    ROLE_ENABLE_DISTRO_COMP: _("Enabling component of the distribution"),
    ROLE_CLEAN: _("Removing downloaded package files"),
    ROLE_RECONFIGURE: _("Reconfiguring installed packages"),
    ROLE_PK_QUERY: _("Searching"),
    ROLE_UNSET: ""}

_ERROR_ROLE = {
    ROLE_INSTALL_FILE: _("Installation of the package file failed"),
    ROLE_INSTALL_PACKAGES: _("Installation of software failed"),
    ROLE_ADD_VENDOR_KEY_FILE: _("Adding the key to the list of trusted "
                                "software vendors failed"),
    ROLE_UPDATE_CACHE: _("Refreshing the software list failed"),
    ROLE_REMOVE_VENDOR_KEY: _("Removing the vendor from the list of trusted "
                              "ones failed"),
    ROLE_REMOVE_PACKAGES: _("Removing software failed"),
    ROLE_UPGRADE_PACKAGES: _("Updating software failed"),
    ROLE_UPGRADE_SYSTEM: _("Upgrading the system failed"),
    ROLE_COMMIT_PACKAGES: _("Applying software changes failed"),
    ROLE_FIX_INCOMPLETE_INSTALL: _("Repairing incomplete installation "
                                   "failed"),
    ROLE_FIX_BROKEN_DEPENDS: _("Repairing broken dependencies failed"),
    ROLE_ADD_REPOSITORY: _("Adding software source failed"),
    ROLE_ENABLE_DISTRO_COMP: _("Enabling component of the distribution "
                               "failed"),
    ROLE_CLEAN: _("Removing downloaded package files failed"),
    ROLE_RECONFIGURE: _("Removing downloaded package files failed"),
    ROLE_PK_QUERY: _("Search failed"),
    ROLE_ADD_LICENSE_KEY: _("Adding license key"),
    ROLE_UNSET: ""}

_DESCS_ERROR = {
    ERROR_PACKAGE_DOWNLOAD_FAILED: _("Check your Internet connection."),
    ERROR_REPO_DOWNLOAD_FAILED: _("Check your Internet connection."),
    ERROR_CACHE_BROKEN: _("Check if you are using third party "
                          "repositories. If so disable them, since "
                          "they are a common source of problems.\n"
                          "Furthermore run the following command in a "
                          "Terminal: apt-get install -f"),
    ERROR_KEY_NOT_INSTALLED: _("The selected file may not be a GPG key file "
                               "or it might be corrupt."),
    ERROR_KEY_NOT_REMOVED: _("The selected key couldn't be removed. "
                             "Check that you provided a valid fingerprint."),
    ERROR_NO_LOCK: _("Check if you are currently running another "
                     "software management tool, e.g. Synaptic or aptitude. "
                     "Only one tool is allowed to make changes at a time."),
    ERROR_NO_CACHE: _("This is a serious problem. Try again later. If this "
                      "problem appears again, please report an error to the "
                      "developers."),
    ERROR_NO_PACKAGE: _("Check the spelling of the package name, and "
                        "that the appropriate repository is enabled."),
    ERROR_PACKAGE_UPTODATE: _("There isn't any need for an update."),
    ERROR_PACKAGE_ALREADY_INSTALLED: _("There isn't any need for an "
                                       "installation"),
    ERROR_PACKAGE_NOT_INSTALLED: _("There isn't any need for a removal."),
    ERROR_NOT_REMOVE_ESSENTIAL_PACKAGE: _("You requested to remove a "
                                          "package which is an essential "
                                          "part of your system."),
    ERROR_DAEMON_DIED: _("The connection to the daemon was lost. Most likely "
                         "the background daemon crashed."),
    ERROR_PACKAGE_MANAGER_FAILED: _("The installation or removal of a "
                                    "software package failed."),
    ERROR_NOT_SUPPORTED: _("The requested feature is not supported."),
    ERROR_UNKNOWN: _("There seems to be a programming error in aptdaemon, "
                     "the software that allows you to install/remove "
                     "software and to perform other package management "
                     "related tasks."),
    ERROR_DEP_RESOLUTION_FAILED: _("This error could be caused by required "
                                   "additional software packages which are "
                                   "missing or not installable. Furthermore "
                                   "there could be a conflict between "
                                   "software packages which are not allowed "
                                   "to be installed at the same time."),
    ERROR_PACKAGE_UNAUTHENTICATED: _("This requires installing packages "
                                     "from unauthenticated sources."),
    ERROR_INCOMPLETE_INSTALL: _("The installation could have failed because "
                                "of an error in the corresponding software "
                                "package or it was cancelled in an unfriendly "
                                "way. "
                                "You have to repair this before you can "
                                "install or remove any further software."),
    ERROR_UNREADABLE_PACKAGE_FILE: _("Please copy the file to your local "
                                     "computer and check the file "
                                     "permissions."),
    ERROR_INVALID_PACKAGE_FILE: _("The installation of a package which "
                                  "violates the quality standards isn't "
                                  "allowed. This could cause serious "
                                  "problems on your computer. Please contact "
                                  "the person or organisation who provided "
                                  "this package file and include the details "
                                  "beneath."),
    ERROR_LICENSE_KEY_INSTALL_FAILED: _("The downloaded license key which is "
                                        "required to run this piece of "
                                        "software is not valid or could not "
                                        "be installed correctly.\n"
                                        "See the details for more "
                                        "information."),
    ERROR_SYSTEM_ALREADY_UPTODATE: _("All available upgrades have already "
                                     "been installed."),
    ERROR_LICENSE_KEY_DOWNLOAD_FAILED: _("The license key which allows you to "
                                         "use this piece of software could "
                                         "not be downloaded. Please check "
                                         "your network connection."),
    ERROR_NOT_AUTHORIZED: _("You don't have the required privileges to "
                          