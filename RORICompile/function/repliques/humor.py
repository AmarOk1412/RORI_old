 #!/usr/bin/python
 # -*- coding: latin-1 -*-
import sys
import time
import random 
from datetime import datetime

mon_fichier = open("end", "w")

r = random.randint(1,2) 
toWrite = ""
print('salut')
if sys.argv[2] == 'BLIN' and sys.argv[3] == 'Sebastien' :
	if r == 2:
		toWrite = "Say : I am always happy with you !"
	else:
		toWrite = "Say : Thanks, I'm fine, but take care of yourself."
else: 
	if int(sys.argv[1]) <= 33 :
		if r == 2:
			toWrite = "Say : I am very happy today !"
		else:
			toWrite = "Say : I am good, thank you for your interest in me."
	elif int(sys.argv[1]) <= 66 :
		if r == 2:
			toWrite = "Say : So so"
		else:
			toWrite = "Say : Thanks for your interest, i am fine."
	else :
		if r == 2:
			toWrite = "Say : I am bad mood, so I'll make fewer actions today."
		else:
			toWrite = "Say : I'm sad."

toWrite += "\n-R_M- : -1"
toWrite += "\n-U_C- : -10"
toWrite += "\n-U_BU- : -10"

mon_fichier.write(toWrite)

mon_fichier.close()
	

#sys.argv[2] : Nom
#sys.argv[3] : Prénom
#sys.argv[1] : humeur
