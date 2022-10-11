#!/bin/bash
rm -rf dat
make
./rps.out 1
cd plt
	rm *.png
	gnuplot phi.plt
	cd .. 
