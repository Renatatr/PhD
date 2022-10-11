#include "../rps.h"

void ic(const gsl_rng *w, int *);     /* initial conditions      */
void op(int , int *);                 /* data output             */

int main(int argc, char **argv){
	int i, j, t, ac, ps, tp, gd, nb; /* i, j: index; 
								 t: time; 
								 ac: active individual; 
								 ps: passive individual; 
								 tp: variable to store a temporary value; 
								 gd: generations (if you want to get this information); 
								 nb: neighbor */
	int who_died, t_died;
	int *phi;  /* phi: vector that stores which species/empty space is at a given place on the network */
	int *dst;  /* density species time */
	double at; /* action to be taken */
	PROBABILITY_OF_PREDATION1 /* Matrix defined in ../rps.h that configures who is the prey or predator (unidirectional predation) 	 */
	PROBABILITY_OF_PREDATION  /* Matrix defined in ../rps.h that configures that the prey is also a predator (bidirectional predation) */
	FILE *file;

	phi= (int *) calloc(Nx*Ny*Nz, sizeof(int));
	dst= (int *) calloc((NS+1), sizeof(int));

	gsl_rng_default_seed= (argc == 2) ? atoi(argv[1]) : time(NULL);
	gsl_rng *w= gsl_rng_alloc(gsl_rng_taus);

	ic(w, phi);
	op(0, phi);
	t_died= 0;
	
	for(i= 0; i< Nx*Ny*Nz; i++){
		dst[phi[i]]++;
	}

	file= fopen("dat/dst.dat", "a"); /* printing of initial species density over time */
	for(i= 1; i< (NS+1); i++){
		fprintf(file, "%e ", (double)dst[i]/(Nx*Ny*Nz));
	}
	fprintf(file, "%e\n", (double)dst[0]/(Nx*Ny*Nz));
	fclose(file);

	for(t= 1; t<=NG; t++){
		gd= 0;
		while(gd < Nx*Ny*Nz){
			i= gsl_rng_uniform(w)*Nx;
			j= gsl_rng_uniform(w)*Ny;
			ac= j*Nx+i;
			if(phi[ac] != 0){
				nb= gsl_rng_uniform(w)*4;
				switch(nb){ /* neighbor selection with continuous boundary conditions */ 
					case 0:
						ps= j*Nx+((i+1)%Nx);
					break;
					case 1:
						ps= j*Nx+((i-1+Nx)%Nx);
					break;
					case 2:
						ps= ((j+1)%Ny)*Nx+i;
					break;
					default:
						ps= ((j-1+Ny)%Ny)*Nx+i;
				}
				at= gsl_rng_uniform(w);
				if(at < pm){ /* mobility */
					tp= phi[ps];
					phi[ps]= phi[ac];
					phi[ac]= tp;
					gd++;
				}else{
					if(at >= pm && at < (pm+pp)){
						if (gsl_rng_uniform(w) >= kappa){
							if(phi[ps] != 0 && gsl_rng_uniform(w) < p1[(phi[ac]-1)*NS+phi[ps]-1]){ /* unidirectional predation */
								dst[phi[ps]]--;
								dst[0]++;
								phi[ps]= 0;
								gd++;
							}	
						}else{
							if(phi[ps] != 0 && gsl_rng_uniform(w) < p[(phi[ac]-1)*NS+phi[ps]-1]){ /* bidirectional predation */
								dst[phi[ps]]--;
								dst[0]++;
								phi[ps]= 0;
								gd++;
							}
						}					
					}else{
						if(phi[ps] == 0){ /* reproduction */
							phi[ps]= phi[ac];
							dst[phi[ps]]++;
							dst[0]--;
							gd++;
						}
					}
				}
			}
		}

		file= fopen("dat/dst.dat", "a"); /* printing of species density over time */
		for(i= 1; i< (NS+1); i++){
			fprintf(file, "%e ", (double)dst[i]/(Nx*Ny*Nz));
		}
		fprintf(file, "%e\n", (double)dst[0]/(Nx*Ny*Nz));
		fclose(file);

		for (i = 1; i <= NS; i += 1){ /* extinction check */
			if(dst[i] == 0.0){
				who_died= i;
				t_died= t;
				t= NG;
			}
		}
	}

	op(1, phi); /* printing of the last snapshot */

	file= fopen("dat/died.dat", "a"); /* printing of species who died first */
	if(t_died != 0){
		fprintf(file, "%d %d\n", who_died, t_died);
	}else{
		fprintf(file, "%d %d\n", 0, NG);
	}
	fclose(file);

	gsl_rng_free(w);
	free(phi);
	free(dst);
	return 0;
}
