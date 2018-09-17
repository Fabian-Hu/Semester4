#!/bin/bash
divisor=$1
shift

number=$1
shift

while test $1; do
number=$(($number*$1))
shift
done

number=$(($number/$divisor))
echo $number
echo $(basename $0)
