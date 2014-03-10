 #!/usr/bin/python
 # -*- coding: latin-1 -*-
import sys
myFile = open("config/userProfil.inf", "r")


liste = ["m'appelle", "m'apelle", "m'appele", "m'apele", "appelle", "apelle", "appele", "apele", "nomme", "prenomme", "prénomme", "suis", "am", "is"]
i = 0
while not sys.argv[i] in liste:
    i+=1

j=0
toWrite = ''
while j < 8:
    toWrite += myFile.readline()
    j += 1
toWrite += sys.argv[i + 1] + '\n' + sys.argv[i + 2]
myFile.close()

myFile = open("config/userProfil.inf", "w")
myFile.write(toWrite)
myFile.close()

myFile = open("end", "w")

toWrite = "Say : Nice to meet you " + sys.argv[i + 1] + ' ' + sys.argv[i + 2]
toWrite += "\nADF"
toWrite += "\n-R_M- : -10"
toWrite += "\n-U_C- : -10"
toWrite += "\n-U_BU- : -10"

myFile.write(toWrite)

myFile.close()
