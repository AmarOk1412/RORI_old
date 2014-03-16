#!/usr/bin/env python2
import random 
import sys
import subprocess
import os
import time
import re
sys.path.append('function/utils')
import randUtils
import endFileUtils

endFileUtils.writeEndFile(randUtils.getRandomSentence('function/sentences/recordDesktop.sen'), -10, -10, 0, 0, 0, -10, -10, -10, 0, 0, -10, 0, 0, 1)
sub1 = subprocess.Popen(args="recordmydesktop --on-the-fly-encoding", stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
stop = False
while not stop:
    try :
        open('stopReco')
        stop = True
    except:
        time.sleep(2)

os.remove('stopReco')	
sub1.kill()
