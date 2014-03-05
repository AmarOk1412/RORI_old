#!/usr/bin/env python2
import sys
import time
import random
import subprocess
sys.path.append('function/utils')
import randUtils
import endFileUtils

endFileUtils.writeEndFile(randUtils.getRandomSentence('function/sentences/lock.sen'), -10, -10, 0, 0, 0, -10, -10, -10, 0, 0, -10, 0, 0, 1)
if random.randint(0,100)%3 == 0:
    subprocess.call('mplayer -really-quiet -msglevel all=-1 function/'+ randUtils.getRandomSound('function/sentences/lock.sound') +' -af extrastereo=0 &', shell=True)

subprocess.call("gnome-screensaver-command -l", shell = True)
subprocess.call("cinnamon-screensaver-command -l", shell = True)
