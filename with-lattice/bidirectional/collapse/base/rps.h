#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <gsl/gsl_rng.h>

#define Nx  	100     /* grid size                      		*/
#define Ny  	100     /* grid size                      		*/
#define Nz 	1       /* grid size                      		*/
#define NS  	2       /* number of types of species     		*/
/* pm + pr + pp = 1.0                                			*/
#define pm  	0.50    /* probability of mobility          		*/
#define pr  	0.25    /* probability of reproduction    		*/
#define pp  	0.25    /* probability of predation 			*/
#define kappa 	0.87    /* probability of bidirectional predation */


#define PROBABILITY_OF_PREDATION1 \ /* Matrix defined in ../rps.h that configures who is the prey or predator (unidirectional predation) 	 */
const double p1[NS*NS]= {\
	0.00, 1.00, \
	0.00, 0.00, \
};

#define PROBABILITY_OF_PREDATION \ /* Matrix defined in ../rps.h that configures that the prey is also a predator (bidirectional predation) */
const double p[NS*NS]= {\
	0.00, 1.00, \
	1.00, 0.00, \
};
