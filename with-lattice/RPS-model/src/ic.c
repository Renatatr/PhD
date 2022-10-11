#include "../rps.h"

void ic(const gsl_rng *w, int *phi){
	int i;
	
	for(i= 0; i< Nx*Ny; i++){
		phi[i]= gsl_rng_uniform(w)*4;
	}
}
