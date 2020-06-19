#include <stdio.h>

/* 
 * Example for an NN
 */

#define NIN 3
#define NDS 6
#define NTR 400

float in[ NDS ][ NIN ] = {
		{1, 0, 1},
		{0, 1, 1},
		{0, 0, 1},
		{1, 1, 1},
		{0, 1, 1},
		{1, 0, 1}, };

float goal[ NDS ] = { 0,
		      1,
		      0,
		      1,
		      1,
		      0 };

float w[NIN] = { 0.5, 0.7, 0.1 };

float alpha = 0.01;

/* 
 * Gradient descent 
 * Multiple data sets
 */
void learn_gd_mds(){
   int i, j, t, z;
   float pred, delta, delta_w, g_error;

   g_error = 0;
   
   /* Train network NTR times */
   for(t = 0; t < NTR; t++) {

      /* predict datatasets */
      for(i = 0; i < NDS; i++){
	 pred = 0;
	 for( j = 0; j < NIN; j++ )
	    pred += in[i][j] * w [j];

	 /* single dataset prediction Compare */
	 delta = pred - goal[i];

	 /* single dataset prediction Learn */
	 for( z = 0; z < NIN; z++) {
	    delta_w = alpha * delta  * in[i][z];
	    w[z] -= delta_w;
	 }
	 g_error = delta * delta;
	 printf("Pred: %f\t Error %f\n", pred, g_error);
      }

      printf("\n");
   }
}



void main(){
   printf("\n");

   learn_gd_mds();

   printf("\n");   
}
