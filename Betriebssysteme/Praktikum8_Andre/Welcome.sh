#!/bin/bash
username=$(whoami)

time=$(date '+%H')

if [ $time -ge 17 ]; then
	echo "Guten Abend $username"
elif [ $time -ge 12 ]; then
	echo "Guten Tag $username"
else
	echo "Guten Morgen $username"
fi

