#!/bin/bash
function makeWiederHin {
  dings=$((grep $1 ~/.trashbin/.dir)| awk '{print $2}')
echo $dings
  cat ~/.trashbin/.dir | grep -v $(grep $1 ~/.trashbin/.dir) > outfile
  mv ~/.trashbin/$1 $dings
}

makeWiederHin $1
