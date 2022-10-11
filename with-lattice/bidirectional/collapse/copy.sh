#!/bin/bash
 
LANG=en_us 
I=10
for J in $(seq 10 1 26)
do
	echo $I - $J
	cp -r base r$I
	sed -i "8 s/10/$J/" r$I/src/ic.c
	cd r$I
		make clean
		make
	cd ../
	I=$(($I+1))
done
