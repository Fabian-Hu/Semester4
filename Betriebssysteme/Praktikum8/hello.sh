#!/bin/bash
datum=$(date +%H)
if [ "$datum" -ge "17" ]
   then
      echo "Guten Abend" $USER
elif [ "$datum" -le "12"]
   then
      echo "Guten Morgen" $USER
else
      echo "Guten Tag" $USER
fi
