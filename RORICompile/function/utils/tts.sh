#!/bin/bash
#Code find on Internet

if [ $# -ne 0 ]; then
	for var in "$@"; do
		echo $var
	done
	
	for var in "$@"; do
		for a in $var; do
			V=$(((($RANDOM) % 40) - 20))
			echo -n "<prosody pitch=\"+$V\">$a</prosody> " |
			sed 's/+-/-/'
		done
	done |
	espeak -m -k20 -p60 -s150 -v fr+f4 --stdout | aplay > /dev/null 2>&1
else	
	while read data; do
		for var in "$data"; do
			echo $var
		done
	
		for var in "$data"; do
			for a in $var; do
				V=$(((($RANDOM) % 40) - 20))
				echo -n "<prosody pitch=\"+$V\">$a</prosody> " |
				sed 's/+-/-/' |
				sed 's/*/star/g'
			done
		done |
		espeak -m -k20 -p60 -s150 -v fr+f4 --stdout | aplay > /dev/null 2>&1
	done
fi

