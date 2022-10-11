#!/bin/bash
rm -r died
mkdir died
cp dat/died.dat died
cd died
cat died.dat | cut -d" " -f1 > died2.dat
for I in $(seq 1 2)
do
grep -c "$I" < died2.dat >> d.dat
done
grep -c "0" < died2.dat >> d.dat

