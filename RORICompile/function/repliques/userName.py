 #!/usr/bin/python
 # -*- coding: latin-1 -*-
import random 
import sys

mon_fichier = open("end", "w")

r = random.randint(1,3) 
toWrite = ""
if r == 1 :
	toWrite += "Say : Your name is : " + sys.argv[1] + " " + sys.argv[2]
elif r == 2 :
	toWrite += "Say : Uh you are amnesic ?"
elif r == 3 :
	toWrite += "Say : You don't know your name ? I think it is a problem..."

toWrite += "\n-R_M- : -10"
toWrite += "\n-R_J- : -10"
toWrite += "\n-U_J- : -10"
toWrite += "\n-U_C- : -10"
toWrite += "\n-U_BU- : -10"

mon_fichier.write(toWrite)

mon_fichier.close()
