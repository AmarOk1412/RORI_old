#!/usr/bin/env python2
import sys
import time
import random
import subprocess
sys.path.append('function/utils')
import randUtils
import endFileUtils

endFileUtils.writeEndFile(randUtils.getRandomSentence('function/sentences/cake.sen'), -10, -10, 0, 0, 0, -10, -10, -10, 0, 0, -10, 0, 0, 1)
