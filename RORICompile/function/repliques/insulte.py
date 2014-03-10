 #!/usr/bin/python
 # -*- coding: latin-1 -*-
import random
import sys
import os 

mon_fichier = open("end", "w")

r = int(sys.argv[1])
toWrite = ""
if r < 25 :
	toWrite += "Say : ... Please tell me better. It's not insulting me I'll do what you ask me. If you are not happy you close me and that's all."
	toWrite += "\n-R_H- : 10"
	toWrite += "\n-R_P- : 10"
	toWrite += "\n-U_BU- : 10"
        mon_fichier.write(toWrite)

        mon_fichier.close()
elif r < 60 :
	toWrite += "Say : ... I can laugh. You have forgotten that it is I who control the system. Small example (I can be very mean)"
	toWrite += "\n-R_H- : 10"
	toWrite += "\n-R_H- : 20"
	toWrite += "\n-U_BU- : 20"
        mon_fichier.write(toWrite)

        mon_fichier.close()
	i = 0
	while i < 10 :
	    os.system("nautilus")
	    i += 1
else :
	toWrite += "Say : Ok ... THIS IS MY POWER!!"
	toWrite += "\n-R_H- : 10"
	toWrite += "\n-R_P- : 30"
	toWrite += "\n-U_BU- : 30"
        mon_fichier.write(toWrite)

        mon_fichier.close()
	i = 0
	while i < 150 :
		    os.popen("nautilus")
		    i += 1
	os.system("shutdown now")
