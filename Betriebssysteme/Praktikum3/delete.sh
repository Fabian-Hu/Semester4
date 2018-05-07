#!/bin/bash
if [ $1 = "-i" ]; then
	files=$(cat $HOME/.trashbin/.dir)
	lastFile=''
	success=false
	for word in $files; do
		if ! $success; then
			if [ $2 = $word ]; then
				success=true
				echo ${lastFile::-1}
			fi
			lastFile=$word
		fi
	done
	if ! $success; then
		echo "Die angebene Datei wurde nicht gelöscht oder hat nie existiert"
	fi
elif [ -a $1 ]; then
	if ! [ -a "$HOME/.trashbin" ]; then
		mkdir $HOME/.trashbin
	fi
	if ! [ -a "$HOME/.trashbin/.dir" ]; then
		touch $HOME/.trashbin/.dir
	fi
	fileName=$(date '+%y%m%d%H%M%S')
	fileName="${fileName}_$$.dat"

	filePath="$HOME/.trashbin/$fileName"
	oldPath=$(realpath $1)

	echo "$fileName! $oldPath" >> $HOME/.trashbin/.dir
	mv $oldPath $filePath
	
else
	echo "Die angegebene Datei existiert nicht"
fi
