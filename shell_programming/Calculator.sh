#!/bin/bash

# judge is  integer or not
function isInteger() 
{
	var=`echo $1 | sed 's/[0-9]//g' | sed 's/-//g'`
	if [ -z $var ]; then
		return 1
	else
		return 0 
	fi	
}


isInteger $1
echo $?
x=$1
y=$3

judge1=`isInteger $1` 
judge2=`isInteger $3`
if [ "$judge1" == 0 ] || [ "$judge2" == 0 ]; then
	echo "input is not integer"
	exit
else

case $2 in 
	+)	echo $[$x + $y];;
	-)	echo $[$x - $y];;
	x)	echo $[$x * $y];;
	/)	echo $[$x / $y];;
	*)	echo "operator is wrong!";;
esac


fi



