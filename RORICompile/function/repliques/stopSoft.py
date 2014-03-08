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

subprocess.call('pkill ' + sys.argv[1], shell=True)
endFileUtils.writeEndFile(randUtils.getRandomSentence('function/sentences/stopSoft.sen'), -10, -10, 0, 0, 0, -10, -10, -10, 0, 0, -10, 0, 0, 1)
