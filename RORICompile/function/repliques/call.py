#!/usr/bin/python
# -*- coding: latin-1 -*-
import random 
import sys, os, re
import subprocess

params = ""
i = 1
while i < len(sys.argv):
    params += sys.argv[i] + " "
    i += 1

#regex for phone number
r = re.compile(r'(\d{3}[-\.\s]??\d{3}[-\.\s]??\d{4}|\(\d{3}\)\s*\d{3}[-\.\s]??\d{4}|\d{3}[-\.\s]??\d{4})')
results = r.findall(params)

File = open("AndroidFile", "w")
File.write("Say : Appelons quelqu'un!\nam start -a android.intent.action.DIAL -d tel:" + results[0])
File.close()

subprocess.call('python AndroidConnect/sendToAndroid.py', shell=True)
