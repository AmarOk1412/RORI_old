 #!/usr/bin/python
 # -*- coding: latin-1 -*-
import serial
import time

port = "/dev/ttyACM0"
ser = serial.Serial(port, 9600)
toWrite = "Say : I try to recognize the card, if you want say an order to test the control of the card."
time.sleep(3)

line = ser.readline()
print(line[0:4])
if line[0:4] == 'led0':
	toWrite += "\nSetnf : BDDS/Arduino/"
else :
	print(line)


ser.close()
mon_fichier = open("end", "w")

mon_fichier.write(toWrite)

mon_fichier.close()
