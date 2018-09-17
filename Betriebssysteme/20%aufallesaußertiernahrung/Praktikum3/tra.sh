#!/bin/bash
function makeWeg {
  date=$(date '+%y%m%d%H%M%S')
  name=$date"_"$$".dat"
  dirdir=$name"! "$(pwd $1)"/"$1
  echo $dirdir >> ~/.trashbin/.dir
  mv $1 ~/.trashbin/$name
  echo $name
}

function exists {
  if test -f $1; then 
    makeWeg $1
  else
    echo Datei nicht existent
    return "0"
  fi
}

exists $1
