#!/bin/bash

function testIfExisting {
  if [ -a $1 ]; then
    echo 1
  else
    echo 0
  fi
}

function checkType {
  if [ -f $1 ]; then
    echo "f"
  elif [ -d $1 ]; then
    echo "d"
  else
    echo "-"
  fi
}

function checkSymbolicLink {
  if [ -L $1 ]; then
    echo 1
  else
    echo 0
  fi
}

function checkOwner {
  if [ -O $1 ]; then
    echo 1
  else
    echo 0
  fi
}

function echoOwner {
  echo $(ls -ld $1 | awk '{print $3}')
}

function editIfTxt {
  if [ "$(echo $1 | awk '/.*\.txt/ {print $1}')" != "" ]; then
    echo "Wollen Sie die Datei editieren?"
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
}

for P in $@; do
  echo $P
  echo Existiert: $(testIfExisting $P)
  echo Typ: $(checkType $P)
  echo Symbolischer Link: $(checkSymbolicLink $P)
  echo Bin ich Besitzer: $(checkOwner $P)
  echo Besitzer: $(echoOwner $P)
  editIfTxt $P
  echo
done
