#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <gsl/gsl_rng.h>

#define Nx  	250     /* grid size                      		*/
#define Ny  	250     /* grid size                      		*/
#define NS  	3       /* number of types of species     		*/
#define NG 	1000   /* number of generations				*/
/* pm + pr + pp = 1.0                                			*/
#define pm  	0.50    /* probability of mobility          		*/
#define pr  	0.25    /* probability of reproduction    		*/
#define pp  	0.25    /* probability of predation 			*/
