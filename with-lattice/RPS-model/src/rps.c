#include "../rps.h"

void ic(const gsl_rng *, int *); /* initial conditions	*/
void op(int , int *);		   /* data output        */                

int main(int argc, char **argv){
	int i, j, t, n, nb, gd, ac, ps, temp; /* i, j: index; 
								 	 t: time; 
								 	 n: number of files in the output
								 	 ac: active individual; 
								 	 ps: passive individual; 
								 	 temp: variable to store a temporary value; 
								 	 gd: generations; 
								 	 nb: neighbor */
	int *phi;  /* phi: vector that stores which species/empty space is at a given place on the network */
	double at; /* action to be taken */

	phi= (int *) calloc(Nx*Ny, sizeof(int));

	gsl_rng_default_seed= (argc == 2) ? atoi(argv[1]) : time(NULL);
	gsl_rng *w= gsl_rng_alloc(gsl_rng_taus);

	n= 0;
	ic(w, phi);
	op(n++, phi);

	for(t= 1; t<= NG; t++){
		gd= 0;
		while(gd < Nx*Ny){
			i= gsl_rng_uniform(w)*Nx;
			j= gsl_rng_uniform(w)*Ny;
			ac= j*Nx+i;
			if(phi[ac] != 0){
				nb= gsl_rng_uniform(w)*4;
				switch(nb){ /* neighbor selection with continuous boundary conditions */ 
					case 0:
						ps= ((j+1)%Ny)*Nx+i;
					break;
					case 1:
						ps= ((j-1+Ny)%Ny)*Nx+i;
					break;
					case 2:
						ps= j*Nx+(i+1)%Nx;
					break;
					default:
						ps= j*Nx+(i-1+Nx)%Nx;
				}
				at= gsl_rng_uniform(w);
				if(at < pm){ /* mobility */
					temp= phi[ac];
					phi[ac]= phi[ps]; 
					phi[ps]= temp;
					gd++;
				}else{
					if(at > pm && at < (pm+pp)){
						if((phi[ac]%NS) == (phi[ps]-1)){ /* predation */
							phi[ps]= 0;
							gd++;
						}
					}else{
						if(phi[ps] == 0){
							phi[ps]= phi[ac]; /* reproduction */
							gd++;
						}
					}
				}
			}
		}
		if(t % 100 == 0){ /* printing of snapshots */
			op(n++, phi);
		}
	}

	free(phi);
	gsl_rng_free(w);
	return 0;
}
