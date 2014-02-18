import sys
import time
import random
import subprocess

mon_fichier = open("end", "w")

r = random.randint(1,4) 
r2 = random.randint(1,4)
toWrite = ""
fichier = open('function/sentences/saluer.sen')
i = 0
for line in fichier:
    i += 1
randLine = random.randint(0,i)
fichier.close()
fichier = open('function/sentences/saluer.sen')
for j in range(0,randLine):
    fichier.readline()

toWrite = "Say : " + fichier.readline()
toWrite += "\nSetst"
if random.randint(0,100)%3 >= 0:
    fichier = open('function/sentences/saluer.sound')
    i = 0
    for line in fichier:
        i += 1
    randLine = random.randint(0,i)
    fichier.close()
    fichier = open('function/sentences/saluer.sound')
    for j in range(0,randLine):
        fichier.readline()
    sound = fichier.readline()
    subprocess.call('mplayer -really-quiet -msglevel all=-1 function/'+ sound[0:len(sound)-1] +' -af extrastereo=0 &', shell=True)

toWrite += "\n-R_M- : -10"
toWrite += "\n-R_P- : -10"
toWrite += "\n-U_BU- : -10"

mon_fichier.write(toWrite)

mon_fichier.close()
	

#sys.argv[1] : RoriPolie ?
