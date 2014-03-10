 #!/usr/bin/python
 # -*- coding: latin-1 -*-
import random 
import sys

mon_fichier = open("end", "w")

r = random.randint(1,3) 
toWrite = ""
if r == 1 :
	toWrite += "Say : You are " + sys.argv[1] + " years old"
elif r == 2 :
	toWrite += "Say : You are " + sys.argv[1] + " spring"
elif r == 3 :
	toWrite += "Say : You don't know your age ??? I think it is a problem ..."

toWrite += "\n-R_M- : -10"
toWrite += "\n-U_C- : -10"

mon_fichier.write(toWrite)

mon_fichier.close()
