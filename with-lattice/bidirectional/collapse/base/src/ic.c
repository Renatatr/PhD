#include "../rps.h"

void ic(const gsl_rng *w, int *phi){
	int i, j;

	for(i= 0; i< Nx; i++){
		for(j= 0; j< Ny; j++){
			if (sqrt((i-Nx/2)*(i-Nx/2)+(j-Ny/2)*(j-Ny/2)) < 10){
				phi[i*Ny+j]= 1;
			}else{
				phi[i*Ny+j]= 2;
			}
		}
	}

}
