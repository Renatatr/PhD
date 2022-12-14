<p> Author: Renata Trintin &lt renatatrintin@gmail.com &gt </p>
<h3> Notes </h3>
<p> Calculates the probability of coexistence as a function of the <i>kappa</i> probability.</p>
<p> <strong>Compilation:</strong> gcc -Wall -O3 -mtune=native src/rps.c src/ic.c src /op.c -lgsl -lgslcblas -lm -o rps.out </p>
<p> <strong>Execution:</strong> ./rps.out <i>seed</i> </p>

<p>The "base" folder contains the base files to generate the desired statistical data, that is, we use the <strong> ./copy.sh</strong> command to change <i>kappa</i> probability (<strong><i>rps.h</strong></i>) creating multiple folders with each simulation inside and compiling via <strong> <i>makefile</i> </strong>.</p>
<p>Within each folder, we use the command <strong>./run.torque</strong> to run the simulation multiple times by changing the random number generator <i>seed</i>. Once all the repetitions are done, we run the code <strong>./run.sh</strong> to separate and count the data on which species died. </p>
<p>In the main folder (survival) we run <strong>./run.sh</strong> to create the file with three columns with the number of times each species died plus one column with the coexistence of the species, that is, no species died.</p>
