#!/usr/bin/env python2
import sys
import time
import random
import subprocess
sys.path.append('function/utils')
import randUtils
import endFileUtils

minOk = False
TODO = False
print(str(time.localtime().tm_hour) + '::' + str(time.localtime().tm_min))
while True:
    try:
        f = open('files/programmFunction')
        for line in f:
            if TODO is True:
                subprocess.call(line, shell=True)
                TODO = False
                minOk = True
            if line[:len(line)-1] == str(time.localtime().tm_hour) + ':' + str(time.localtime().tm_min):
                TODO = True
        f.close()
    except:
        print('')
    if minOk:
        time.sleep(60)
    else:
        time.sleep(1)
