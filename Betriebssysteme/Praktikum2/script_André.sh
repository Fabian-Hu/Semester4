#!/bin/bash
function exists {
	if [ -a $1 ]; then
		return 1
	else
		return 0	
	fi
}

function isDirectory {
	if [ -d $1 ]; then
		return 1
	elif [ -f $1 ]; then
		return 2
	else
		return 0
	fi
}

function isSymbolicLink {
	if [ -h $1 ]; then
		return 1
	else
		return 0
	fi
}

function isOwner {
	if [ -O $1 ]; then
		return 1
	else
		return 0
	fi
}

function getRealOwner {
	realOwner=$(stat -c "%U" $1)
}

function checkParameter {
	exists $1
	if [ $? -eq 1 ]; then
		echo Der Pfad existiert

		isDirectory $1
		retval=$?
		if [ $retval -eq 1 ]; then
			echo Der angegebene Parameter verweist auf einen Ordner
		elif [ $retval -eq 2 ]; then
			echo Der angegebene Parameter verweist auf eine Datei
		else
			echo Der angegebene Parameter verweist weder auf einen Ordner, noch auf eine Datei
		fi

		isSymbolicLink $1
		if [ $? -eq 1 ]; then
			echo Der angegebene Parameter verweist auf einen symbolischen Link
		fi

		isOwner $1
		if [ $? -eq 1 ]; then
			echo Du bist der Besitzer
		else
			echo Du bist nicht der Besitzer
			getRealOwner $1
			echo Der richtige Besitzer ist $realOwner
		fi
	fi
}

for param in $@
do
	checkParameter $param
	end=$(echo $param | rev | cut -d. -f1 | rev)
	if [ $end = "txt" ]; then
		echo Datei ist txt
		echo "Möchtest du dir die Datei anzeigen lassen?"
		select answer in ja nein
		do
			case $answer in
				ja)
					nano $param
					break
					;;
				nein)
					break
			esac	
		done
	fi
	echo
done



