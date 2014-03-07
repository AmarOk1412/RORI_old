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

toWrite = ""
if sys.argv[1] != 'steam':
	mon_fichier = open("end", "w")
	if sys.argv[1] == 'gimp' :
		toWrite = "Say : My creator is an artist too :)"
	elif sys.argv[1] == 'eclipse' :
		toWrite = "Say : So good for JAVA & Scala"
	elif sys.argv[1] == 'nautilus' :
		toWrite = "Say : Nautilus ready to explore your system"
	elif sys.argv[1] == 'gedit' :
		toWrite = "Say : Good Job"
	else:
            endFileUtils.writeEndFile(randUtils.getRandomSentence('function/sentences/execSoft.sen'), -10, -10, 0, 0, 0, -10, -10, -10, 0, 0, -10, 0, 0, 1)

	toWrite += "\n-R_M- : -10"
	toWrite += "\n-U_C- : -10"
	toWrite += "\n-U_BU- : -10"

	mon_fichier.write(toWrite)

	mon_fichier.close()

	subprocess.call(sys.argv[1], shell = True)
else:
	log = open('logsteam', 'w')
	log.close()
	mon_fichier = open('end', 'w')
	os.remove('logsteam')
	subprocess.Popen('steam > logsteam', shell = True)
	time.sleep(3)
	toWrite = "Say : Good game !!!"

	toWrite += "\n-R_M- : -10"
	toWrite += "\n-U_C- : -10"
	toWrite += "\n-U_BU- : -10"
	mon_fichier.write(toWrite)
	mon_fichier.close()
	
	log = open('logsteam', 'w')
	log.close()
	log = open('logsteam', 'r')
	i = 0
	stop = False
	while not stop:
		j = 0
		log = open('logsteam', 'r')
		for line in log:
			if j >= i:
				mon_fichier = open("end", "w")
				j += 1
				m = re.search('killed', line)
				if m and m.start() == 0 :
					r = random.randint(1,4)
					if r == 1:
						toWrite = 'Say : Oh.... nice headshot !!\n'
					if r == 2:
						toWrite = 'Say : Boum. one more dead\n'
					if r == 3:
						toWrite = 'Say : I call that... popopower !!\n'
					if r == 4:
						toWrite = 'Say : Headshot Bitch !!\n'
				m = re.search('killed', line)
				if m and m.start() != -1:
					r = random.randint(1,3)
					if r == 1:
						toWrite = 'Say : Try Again...\n'
					if r == 2:
						toWrite = 'Say : He must pay\n'
					if r == 3:
						toWrite = 'Say : it Hurts ...\n'
				m = re.search('AmarOk1412 s\'est connecte', line)
				if m and m.start() != -1:
					toWrite = 'Say : Go !!\n'
				m = re.search('Shutdown', line)
				if m and m.start() != -1:
					stop = True

				toWrite += "\n-R_M- : -10"
				toWrite += "\n-U_C- : -10"
				toWrite += "\n-U_BU- : -10"
				mon_fichier.write(toWrite)
				mon_fichier.close()
			else:
				j += 1
		i = j
		log.close()
		time.sleep(2)
