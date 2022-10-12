<p> Author: Renata Trintin &lt renatatrintin@gmail.com &gt </p>
<h3> Notes </h3>    
<p> Calculates the probability of the inner species (predator) going extinct as a function of the size of the radius it initially occupies and the kappa probability of the outer species (prey) preying on the inner species. </p>
<p> <strong>Compilation:</strong> <span style="background-color: #505050; color: #FFFFFF"> gcc -Wall -O3 -mtune=native src/rps.c src/ic.c src/op.c -lgsl -lgslcblas -lm -o rps.out </span> </p>
<p> <strong>Execution:</strong> <span style="background-color: #505050; color: #FFFFFF">./rps.out <i>seed</i> </span> </p>

<p>The "base" folder contains the base files to generate desired statistical data, that is, we use the <strong style="background-color: #505050; color: #FFFFFF"> ./copy.sh</strong> command to change the radius of the initial condition (<strong><i>src/ic.c</strong></i>) by creating several folders with each simulation inside and compiling via <strong><i>makefile</i></strong>.</p>
<p>Within each folder, we use the <strong style="background-color: #505050; color: #FFFFFF">./run.torque</strong> command to run the simulation several times by changing the random number generator <i>seed</i>. Once all the repetitions are done, we run the code <strong style="background-color: #505050; color: #FFFFFF">./run.sh</strong> to separate and count the data of which species died.</p>
<p>In the main folder (collapse), we run <strong style="background-color: #505050; color: #FFFFFF">./run.sh</strong> to create the file with the column of radius and the number of times the internal species (predator) died.</p>
