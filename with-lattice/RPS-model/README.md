<p> Author: Renata Trintin &lt renatatrintin@gmail.com &gt </p>
<h3> Notes </h3>
<p> It performs the simulation of the RPS model with the properties explained in the <strong><i>rps.h</i></strong> file.</p>
<p> <strong>Compilation:</strong> <span style="background-color: #505050; color: #FFFFFF"> gcc -Wall -O3 -mtune=native src/rps.c src/ic.c src /op.c -lgsl -lgslcblas -lm -o rps.out </span> </p>
<p> <strong>Execution:</strong> <span style="background-color: #505050; color: #FFFFFF">./rps.out <i>seed</i> </span> </p>

<p> We use the command <strong style="background-color: #505050; color: #FFFFFF">./run.sh</strong> to delete the <strong><i>data</i></strong> folder, compile and run the simulation with a <i>seed</i>. At the end of the simulation, delete the figures inside the <strong><i>plt</i></strong> folder and generate the snapshots via gnuplot.</p>
