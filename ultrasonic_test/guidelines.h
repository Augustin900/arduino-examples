/*
Make sure to disconnect the Ultrasonic sensor before uploading.
Otherwise the upload will just fail. Example: 

avrdude: Version 6.3-20190619
         Copyright (c) 2000-2005 Brian Dean, http://www.bdmicro.com/
         Copyright (c) 2007-2014 Joerg Wunsch

         System wide configuration file is "C:\Users\<your_name>\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17/etc/avrdude.conf"

         Using Port                    : COM4
         Using Programmer              : arduino
         Overriding Baud Rate          : 115200
avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00 // Check 1 of 10 for getsync()
avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x00 // Check 2 of 10 for getsync()
avrdude: stk500_getsync() attempt 3 of 10: not in sync: resp=0x00 // Check 3 of 10 for getsync()
avrdude: stk500_getsync() attempt 4 of 10: not in sync: resp=0x00 // Check 4 of 10 for getsync()
avrdude: stk500_getsync() attempt 5 of 10: not in sync: resp=0x00 // Check 5 of 10 for getsync()
avrdude: stk500_getsync() attempt 6 of 10: not in sync: resp=0x00 // Check 6 of 10 for getsync()
avrdude: stk500_getsync() attempt 7 of 10: not in sync: resp=0x00 // Check 7 of 10 for getsync()
avrdude: stk500_getsync() attempt 8 of 10: not in sync: resp=0x00 // Check 8 of 10 for getsync()
avrdude: stk500_getsync() attempt 9 of 10: not in sync: resp=0x00 // Check 9 of 10 for getsync()
avrdude: stk500_getsync() attempt 10 of 10: not in sync: resp=0x00 // Check 10 of 10 for getsync()
avrdude: ser_drain(): read error: Access is denied. // Read error for serial port



avrdude done.  Thank you.

Failed uploading: uploading error: exit status 1