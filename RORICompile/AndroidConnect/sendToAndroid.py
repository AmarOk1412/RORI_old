#!/usr/bin/python
# -*- coding: latin-1 -*-
import random 
import sys, os
import ftplib

def send_File(file, user, pwd):
    ftp = ftplib.FTP("url")
    ftp.login(user, pwd)
    ftp.storlines("STOR RORI/" + file, open(file))

ftpFile = open("RORIAndroid.txt", "w")

ftpFile.write('NUM : ' + str(random.randint(0, 1000)) + "\n")
tempFile = open("temp", "r")
for line in tempFile.readlines():
    ftpFile.write('Say : ' + line[8:])

ftpFile.close()
tempFile.close()

send_File('RORIAndroid.txt', 'user', 'passwd')
os.remove('RORIAndroid.txt')
os.remove('temp')

