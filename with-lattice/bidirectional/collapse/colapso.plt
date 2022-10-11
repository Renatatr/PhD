set terminal tikz size 8.4cm, 4.2cm fontscale 0.8 fulldoc dl 0.5
set output "colapso.tex"

set xlabel offset  0.0, 0.2 "R"
set ylabel offset  1.05, 0.0 "Probability of collapse"
set xrange [10:26]
set yrange [0.0:1.0]
set xtics  offset 0.0, 0.0 
set ytics  offset 1.0, 0.0
set key at graph 0.85, 0.90 Left reverse samplen -1.0 width -7.0 spacing 1.2
#set xtics 0.1

#f(x) = a*x + b
#fit f(x) "sur.txt" u ($1):($2/1000) via a, b

plot \
"sur.txt" u ($1):($2/1000) w l lw 3 lc rgb "#c0c0c0"  t"" ,\
"sur.txt" u ($1):($2/1000) w p lw 2 pt 6  lc rgb "#808080"  t"" 

unset output
