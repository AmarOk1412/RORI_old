import subprocess
import os
import sys

toSay = ""
i = 1

while i < len(sys.argv) :
	toSay = toSay + ' ' + str(sys.argv[i])
	i = i + 1

subprocess.call('espeak -ven+f4 -p 60 -s 180 -m  "' + toSay + '"', shell=True)
