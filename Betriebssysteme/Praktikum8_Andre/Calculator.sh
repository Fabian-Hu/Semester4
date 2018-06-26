#!/bin/bash
scriptname=${0##*/}
if [ $# -ge 2 ]; then
	denominator=$1
	numerator=1

	echo "$scriptname berechnet folgendes Ergebnis aus den angegebenen Parametern:"

	shift
	while [ $# -ne 0 ]
	do
		#soll hier auf- und abgerundet werden?
		numerator=$(expr $numerator \* $1)
		shift
	done

	echo $(expr $numerator \/ $denominator)
else
	echo "Die Parameterangaben für $scriptname sind ungültig"
fi
