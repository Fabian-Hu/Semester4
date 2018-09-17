#!/bin/bash
# Demonstriert das Kommando shift
# Name: shifty
erster=$1
produkt=1
shift

while [ -n "$1" ]; do
	echo $1
	produkt=$((produkt*$1))
	shift
done
	produkt=$((produkt/erster))
echo "Produkt = $produkt"
echo "Dateiname = $(basename $0)"
