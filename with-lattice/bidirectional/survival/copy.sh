#!/bin/bash
 
LANG=en_us 
I=0
for J in $(seq 0.0 0.01 1.0)
do
	echo $I - $J
	cp -r base $I
	sed -i "16 s/1.00/$J/" $I/rps.h
	cd $I
	make clean
	make
	cd ..
	I=$(($I+1))
done 
