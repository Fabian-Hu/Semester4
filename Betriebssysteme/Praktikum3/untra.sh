#!/bin/bash
function makeWiederHin {
  dings=$((grep $1 ~/.trashbin/.dir)| awk '{print $2}')
  grep -v  $1 ~/.trashbin/.dir > ~/.trashbin/.tempdatei
  mv ~/.trashbin/.tempdatei ~/.trashbin/.dir
  mv ~/.trashbin/$1 $dings
}

makeWiederHin $1
