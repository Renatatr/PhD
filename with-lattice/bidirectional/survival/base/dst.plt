set terminal tikz size 8.4cm, 4.0cm fontscale 0.8 fulldoc dl 0.5
set output "dst.tex"

set xlabel offset  0.0, 0.2 "$t$"
set ylabel offset  0.5, 0.0 "$\\rho_i$"
set xrange [0:1e5]
set yrange [0.0:1.0]
#set xtics  offset 0.0, 0.0 
#set ytics  offset 1.0, 0.0
#set xtics 1000
set key at graph 0.9, 0.95 horizontal Left reverse samplen 0.5 width 0.5

plot \
"dst.dat" every 10 u ($0*10):($1) w l lc rgb "#ff8080"  t"$1$" ,\
"dst.dat" every 10 u ($0*10):($2) w l lc rgb "#8080ff"  t"$2$" ,\
"dst.dat" every 10 u ($0*10):($3) w l lc rgb "#ffff80"  t"$3$" ,\
"dst.dat" every 10 u ($0*10):($4) w l lc rgb "#808080"  t"$0$"


unset output
