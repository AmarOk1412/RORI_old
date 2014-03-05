#!/usr/bin/env python2
import sys
import os
import time
import random
import subprocess
sys.path.append('function/utils')
import randUtils
import endFileUtils

stop = False
for arg in sys.argv:
    if arg is '-s':
        stop = True

if not stop :
    subprocess.call("cat ~/Musique/RORIList > musiclist", shell = True)

    endFileUtils.writeEndFile(randUtils.getRandomSentence('function/sentences/music.sen'), -10, -10, 0, 0, 0, -10, -10, -10, 0, 0, -10, 0, 0, 1)

    musicFile = open('musiclist', 'r')
    nbLines = 0
    for line in musicFile:
        nbLines += 1

    musicFile.close()
    musicFile = open('musiclist', 'r')
    for n in range(0, random.randint(0, nbLines)):
        musicFile.readline()

    music = ""
    music = musicFile.readline()[:len(music)-1]
    musicFile.close()
    os.remove('musiclist')
    subprocess.call("cvlc " + music, shell = True)
else:
    subprocess.call("pkill vlc", shell = True)
    endFileUtils.writeEndFile(randUtils.getRandomSentence('function/sentences/stopMusic.sen'), -10, -10, 0, 0, 0, -10, -10, -10, 0, 0, -10, 0, 0, 1)

