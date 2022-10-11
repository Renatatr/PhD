set terminal tikz size 8.4cm, 4.2cm fontscale 0.8 fulldoc dl 0.5
set output "sobrev.tex"

set xlabel offset  0.0, 0.2 "$\\kappa$"
set ylabel offset  1.05, 0.0 "Probability of coexistence"
set xrange [0.0:1.0]
set yrange [0.0:1.0]
set xtics  offset 0.0, 0.0 
set ytics  offset 1.0, 0.0
set key at graph 0.85, 0.90 Left reverse samplen -1.0 width -7.0 spacing 1.2
#set xtics 0.1

plot \
"died.txt" u ($1*0.01):(($5)/1000) w l lw 3 lc rgb "#c0c0c0"  t"" ,\
"died.txt" u ($1*0.01):(($5)/1000) w p lw 2 pt 6  lc rgb "#808080"  t"" ,\


unset output
