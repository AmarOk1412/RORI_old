 #!/usr/bin/python
 # -*- coding: latin-1 -*-
import random 
import sys
import subprocess
import os
import time
import re
sys.path.append('function/utils')
import randUtils
import endFileUtils

endFileUtils.writeEndFile(randUtils.getRandomSentence('function/sentences/webcam.sen'), -10, -10, 0, 0, 0, -10, -10, -10, 0, 0, -10, 0, 0, 1)

import cv2, cv, time

cv2.namedWindow("WebCam")
vc = cv2.VideoCapture(0)

if vc.isOpened(): # try to get the first frame
    rval, frame = vc.read()
else:
    rval = False

i=0

while rval:
    cv2.flip(frame, 1, frame) # frame src, 1-> Horizontal mirror, frame dest (-1 vertical), 0 vertical & horizontal
    cv2.imshow("WebCam", frame)
    rval, frame = vc.read()
    i+=1
    key = cv2.waitKey(20)
    if key == 27: # exit on ESC
        break
