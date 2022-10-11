set terminal pngcairo size 1045, 1045 crop
set size ratio -1
set xrange [0.5:100.5]
set yrange [0.5:100.5]
set xtics 200
set ytics 200
unset tics
set cbrange[0:2]
unset colorbox

set palette defined \
(0 "#ffffff", \
 1 "#ff8080", \
 2 "#8080ff")

i=0
while (i <= 20000){
	set output sprintf("phi-%d.png", i)
	plot sprintf("../dat/phi-%d.dat", i) u ($1+1):($2+1):3 matrix w image
	unset output
	i = i + 1
}

