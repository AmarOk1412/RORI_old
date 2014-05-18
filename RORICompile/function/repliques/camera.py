#!/usr/bin/python
# -*- coding: latin-1 -*-
import random 
import sys, os
import subprocess

File = open("AndroidFile", "w")
File.write("Say : Open the camera!\nam start -a android.media.action.VIDEO_CAPTURE")
File.close()

subprocess.call('python AndroidConnect/sendToAndroid.py', shell=True)
