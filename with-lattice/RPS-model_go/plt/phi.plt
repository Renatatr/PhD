set terminal pngcairo size 1040, 1040

set size ratio -1
set xrange [0.0:150.0]
set yrange [0.0:150.0]
set xtics 200
set ytics 200
unset tics
set cbrange[0:3]
unset colorbox

set palette defined \
(0 "#ffffff", \
 1 "#ff8080", \
 2 "#80ff80", \
 3 "#8080ff")

i=0
while (i <= 20000){
	set output sprintf("data-%d.png", i)
	plot sprintf("../dat/data-%d.dat", i) u ($1+1):($2+1):3 matrix w image
	unset output
	i = i + 1
}

