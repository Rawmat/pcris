#include <stdio.h>

/* 
 * Example for an NN
 */

#define NIN 3
#define NDS 4
#define NTR 4000
#define ERROK 0.00000001

#define STDOUT

/***************

    o
     \
      \
    o--o
      /
     /
    o


***************/

float in[ NDS ][ NIN ] = {           
		{1, 0, 1},
		{0, 1, 1},
		{0, 0, 1},
		{1, 1, 1}
};		

float goal[ NDS ] = { 0,
		      1,
		      0,
		      1,
};

float w[NIN] = { 2, 2, 2 };

float alpha = 0.1;

/* 
 * Gradient descent 
 * Multiple data sets
 */
void learn_gd_mds(){
   int i, j, t, z;
   float pred, delta, delta_w, g_error[NDS], g_error_avg;
   char cont;
   float w0old, w0new, w1old, w1new, w2old, w2new;
   char w0c, w1c, w2c;

   /* calculate weights adjust direction */
   w0old = 0;
   w0new = 0;
   w1old = 0;
   w1new = 0;
   w2old = 0;
   w2new = 0;

   w0c = ' ';
   w1c = ' ';
   w2c = ' ';   
   
   cont = 1;
   
   /* Train network NTR times */
   for(t = 0; ( (t < NTR) && (cont == 1 )); t++) {

      cont = 0;

      /* predict datatasets */
      for(i = 0; i < NDS; i++){
	 pred = 0;
	 for( j = 0; j < NIN; j++ )
	    pred += in[i][j] * w [j];

	 /* single dataset prediction Compare */
	 delta = pred - goal[i];

	 /* network error */
	 g_error[i] = delta * delta;	 

	 #ifdef STDOUT
	 /* for display */
	 //printf("|%4d|\t%1.0f %1.0f %1.0f  %1.0f \tw0: %8.5f\tw1: %8.5f\tw2: %8.5f \tPred: %12.5f\t Error: %12.5f\n", \
		t, in[i][0], in[i][1], in[i][2], goal[i], w[0], w[1], w[2], pred, g_error[i]);
	 /* Displat weight change direction */
	 printf("|%4d|\t%1.0f %1.0f %1.0f  %1.0f \tw0: %8.5f\tw1: %8.5f\tw2: %8.5f \t%c\t%c\t%c\n",\
		t, in[i][0], in[i][1], in[i][2], goal[i], w[0], w[1], w[2], w0c, w1c, w2c);
	 #else
	 /* for gnuplot */
	 printf("%d,%f,%f,%f,%f\n" , t, g_error[i], w[0], w[1], w[2]);
	 #endif



	 /* single dataset prediction Learn */
	 for( z = 0; z < NIN; z++) {
	    float old, diff;

	    delta_w = alpha * delta  * in[i][z];

	    old = w[z];
	    w[z] -= delta_w;

	    /* calculate weights adjust direction */
	    diff = w[z] - old;
	    switch (z) {
	    case 0: 
	       if (diff > 0.0)
		  w0c = '+';
	       else if (diff < 0.0 )
		  w0c = '-';
	       else if (diff == 0.0)
		  w0c = ' ';
	       break;
	    case 1: 
	       if (diff > 0.0)
		  w1c = '+';
	       else if (diff < 0.0 )
		  w1c = '-';
	       else if (diff == 0.0)
		  w1c = ' ';
	       break;
	    case 2: 
	       if (diff > 0.0)
		  w2c = '+';
	       else if (diff < 0.0 )
		  w2c = '-';
	       else if (diff == 0.0)
		  w2c = ' ';
	       break;
	    }
	 }
      } 

      /* evaluate errror on dataset */
      {
	 float _sum = 0;
	 for( i = 0; i < NDS; i++)
	    _sum += g_error[i];
	 g_error_avg = _sum / NDS;
      }
	 
      if (g_error_avg > ERROK)
	  cont = 1;
     
      #ifdef STDOUT
      printf("\n");
      #endif
   }

   #ifdef STDOUT
   printf("----------------------------------------------------\n");
   #endif
	
}



void main(){
   printf("\n");

   learn_gd_mds();

   printf("\n");   
}
