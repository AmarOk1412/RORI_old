#!/usr/bin/env python2
import sys
import os
import re
import time
import random
import subprocess
sys.path.append('function/utils')
import randUtils
import endFileUtils

sortie = os.popen('uptime','r').read()
m = re.findall(r"[0-9A-z:]+ up  ([0-9\:]+)", sortie)
f = open('end', 'w')
f.write('Say : I am up since ' + m[0])
f.close()
