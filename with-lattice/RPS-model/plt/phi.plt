set terminal pngcairo size 800, 800
set size ratio -1
set xrange [0.5:250.5]
set yrange [0.5:250.5]
set xtics 25
set ytics 25
unset colorbox
unset tics

set palette defined \
(0 "#ffffff", \
 1 "#ff0000", \
 2 "#0000ff", \
 3 "#ffff00")

i=0
while (i <= 500){
	set output sprintf("phi-%d.png", i)
	plot sprintf("../dat/phi-%d.dat", i) u ($1+1):($2+1):3 matrix w image
	unset output
	i = i + 1
}

