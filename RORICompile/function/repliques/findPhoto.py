#!/usr/bin/env python2
import sys
import time
import random
import subprocess
sys.path.append('function/utils')
import randUtils
import endFileUtils
import math, os, re

def listdirectory(path): 
    fichier=[] 
    for root, dirs, files in os.walk(path): 
        for i in files: 
            fichier.append(os.path.join(root, i)) 
    return fichier

fichiers = listdirectory('/home')
for f in fichiers:
    m = re.search(sys.argv[len(sys.argv) - 1] + '.{0,10}(pn|jp)g', f)
    if m is not None:
		subprocess.call('shotwell ' + f, shell=True)

endFileUtils.writeEndFile(randUtils.getRandomSentence('function/sentences/findPhoto.sen'), -10, -10, 0, 0, 0, -10, -10, -10, 0, 0, -10, 0, 0, 1)
