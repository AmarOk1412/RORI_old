#!/usr/bin/env python2
import sys
import time
import random
import subprocess
sys.path.append('function/utils')
import randUtils
import endFileUtils

endFileUtils.writeEndFile(randUtils.getRandomSentence('function/sentences/sound.sen'), -10, -10, 0, 0, 0, -10, -10, -10, 0, 0, -10, 0, 0, 1)
subprocess.call("pactl set-sink-volume 0 50%", shell = True)
