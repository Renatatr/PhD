#include "../rps.h"

void op(int n, int *phi){
	int i, j;
	char nome[100];
	sprintf(nome, "dat/phi-%d.dat", n);
	FILE *arquivo= fopen(nome, "w");

	for(i= 0; i< Nx; i++){
		for(j= 0; j< Ny; j++){
			fprintf(arquivo, "%d ", phi[i*Ny+j]);
		}
		fprintf(arquivo, "\n");
	}
	fclose(arquivo);
}
