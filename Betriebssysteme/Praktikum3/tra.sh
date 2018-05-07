#!/bin/bash
function makeWeg {
  date=$(date '+%y%m%d%H%M%S')
  name=$date"_"$$".dat"
  dirdir=$name"! "$(pwd $1)"/"$1
  echo $dirdir >> ~/.trashbin/.dir
  mv $1 ~/.trashbin/$name
  echo $name
}

makeWeg $1
