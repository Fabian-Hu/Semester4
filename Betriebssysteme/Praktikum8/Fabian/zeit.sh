#!/bin/bash

dateHour=$(date +%H)

if [ $dateHour -ge 00 ] && [ $dateHour -le 11 ]
then
	echo "Guten Morgen $USER"
elif [ $dateHour -ge 12 ] && [ $dateHour -le 16 ] 
then
	echo "Guten Mittag $USER"
elif [ $dateHour -ge 17 ] && [ $dateHour -le 24 ]
then
	echo "Guten Abend $USER"
fi
 
