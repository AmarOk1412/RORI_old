#!/usr/bin/env python2
import random

def getRandomSentence(nameFile):
    fichier = open(nameFile)
    i = 0
    for line in fichier:
        i += 1
    randLine = random.randint(0,i)
    fichier.close()
    fichier = open(nameFile)
    for j in range(1,randLine):
        fichier.readline()
    sentence = fichier.readline()

    return sentence[:len(sentence)-1]

def getRandomSound(nameFile):
    fichier = open(nameFile)
    i = 0
    for line in fichier:
        i += 1
    randLine = random.randint(0,i)
    fichier.close()
    fichier = open(nameFile)
    for j in range(0,randLine):
        fichier.readline()
    sound = fichier.readline()
    
    return sound[:len(sound)-1]
