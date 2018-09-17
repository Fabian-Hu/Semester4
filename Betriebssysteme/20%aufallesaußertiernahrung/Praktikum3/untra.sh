#!/bin/bash
function makeWiederHin {
  dings=$((grep $1 ~/.trashbin/.dir)| awk '{print $2}')
  pfad=${dings%/*}
  exists $pfad
  da=$?
  if [ "$da" = "1" ]
  then
    grep -v  $1 ~/.trashbin/.dir > ~/.trashbin/.tempdatei
    mv ~/.trashbin/.tempdatei ~/.trashbin/.dir
    mv ~/.trashbin/$1 $dings
  fi
}

function exists {
  if test -d $1; then 
    return "1"
  else
    echo Alter Pfad nicht existent
    return "0"
  fi
}

makeWiederHin $1
