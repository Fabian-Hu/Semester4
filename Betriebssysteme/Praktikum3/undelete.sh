#!/bin/bash

FILE="$(cat ~/.trashBin/.dir | grep $1 | awk '{print $2}')"

FILE_PATH=$(echo $FILE | rev | cut -d/ -f 2- | rev)

if [ -a $FILE_PATH ]; then
  mv ~/.trashBin/$1 $FILE
fi
