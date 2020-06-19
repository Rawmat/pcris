#include <stdio.h>

/* 
 * Example for an NN
 */

#define NIN 3
#define NDS 6
#define NTR 4000

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

float w[NIN] = { 7.0, 0.0, 10 };

float alpha = 0.01;

/* 
 * Gradient descent 
 * Multiple data sets
 */
void learn_gd_mds(){
   int i, j, t, z;
   float pred, delta, delta_w, g_error;
   char cont;

   g_error = 0;

   cont = 1;
   
   /* Train network NTR times */
   for(t = 0; (t < NTR) && (cont == 1 ) ; t++) {

      cont = 0;

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

	 if (g_error > 0.00001)
	    cont = 1;
	    
	 //	 printf("[%4d]\tPred: %12.5f\t Error: %12.5f\tw0: %12.5f w1: %12.5f w2: %12.5f\n" \
		, t, pred, g_error, w[0], w[1], w[2]);
	 printf("%d4\t%12.5f\n", t, w[1]);
      }

      //      printf("\n");
   }
}



void main(){
   printf("\n");

   learn_gd_mds();

   printf("\n");   
}
