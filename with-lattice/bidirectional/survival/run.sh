#!/bin/bash
rm died.txt
for I in $(seq 1 1 100)
do
	cd $I
		./run.sh
	cd died
	cat d.dat | awk '{print $1}' |head -n1 |tail -1 >> ../../A.dat
	cat d.dat | awk '{print $1}' |head -n2 |tail -1 >> ../../B.dat
	cat d.dat | awk '{print $1}' |head -n3 |tail -1 >> ../../C.dat
	cat d.dat | awk '{print $1}' |head -n5 |tail -1 >> ../../coe.dat
	cd ../../
done

seq 1 1 100 > seq.dat
paste seq.dat A.dat B.dat C.dat coe.dat >> died.txt

rm *.dat
