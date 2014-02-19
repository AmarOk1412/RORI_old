#!/usr/bin/env python2

def writeEndFile(toSay, roriHumor = 0, roriPolite = 0, roriJokes = 0, roriBadIA = 0, roriScared = 0, roriMoral = 0, userHumor = 0, userPolite = 0, userJokes = 0, userBad = 0, userMoral = 0, userCurious = 0, userTired = 0, saluer = 0):
    fichier = open("end", "w")
    toWrite = "Say : " + toSay + '\n'

    toWrite += "\n-R_H- : " + str(roriHumor)
    toWrite += "\n-R_P- : " + str(roriPolite)
    toWrite += "\n-R_J- : " + str(roriJokes)
    toWrite += "\n-R_BIA- : " + str(roriBadIA)
    toWrite += "\n-R_S- : " + str(roriScared)
    toWrite += "\n-U_M- : " + str(roriMoral)
    toWrite += "\n-U_H- : " + str(userHumor)
    toWrite += "\n-U_P- : " + str(userPolite)
    toWrite += "\n-U_J- : " + str(userJokes)
    toWrite += "\n-U_BU- : " + str(userBad)
    toWrite += "\n-U_M- : " + str(userMoral)
    toWrite += "\n-U_C- : " + str(userCurious)
    toWrite += "\n-U_T- : " + str(userTired)
    if saluer == 1:
        toWrite += "\nSetst"
    if saluer == 2:
        toWrite += "\nSetsf"

    fichier.write(toWrite)

    fichier.close()

