#!/bin/bash

FILE="$(cat ~/.trashbin/.dir | grep $1 | awk '{print $2}')"

FILE_PATH=$(echo $FILE | rev | cut -d/ -f 2- | rev)

if [ -a $FILE_PATH ] && [ -a ~/.trashbin/$1 ]; then
  mv ~/.trashbin/$1 $FILE
  cat ~/.trashbin/.dir | grep -v $1 > ~/.trashbin/.temp
  mv ~/.trashbin/.temp ~/.trashbin/.dir
else
  echo "Verzeichnis nicht mehr Vorhanden"
fi
