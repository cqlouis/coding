#!/bin/bash

Num=0
for i in {1..100}
do
	Num=$(expr &Num + $i)
done
echo $Num
