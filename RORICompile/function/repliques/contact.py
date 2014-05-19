#!/usr/bin/python
# -*- coding: latin-1 -*-
import random 
import sys, os
import subprocess

File = open("AndroidFile", "w")
File.write("Say : This is your contact list!\nam start -n com.google.android.contacts/.ContactsActivity")
File.close()

subprocess.call('python AndroidConnect/sendToAndroid.py', shell=True)
