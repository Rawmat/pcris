#include <stdio.h>

/* Example for an NN
 *
 */


/* gradient descent learning */
void learn_hot_gd(){
   float in = -1.0;
   float w = 0.8;
   float pred;
   float goal = 2.0;
   float delta_w;
   float error;
   float alpha = 0.8;
   int i;

   for(i = 0; i < 200; i++){

      /* 
       * error is prediction minus goal
       * (squared) for gives priority to higher error and
       * and when averaging to not consider opposite miss same magnitude
       */

      {
	 /* normal prediction */
	 pred = in * w; 

	 /* calculate delta weight - direction and amount 
	  * multiplying by input performs - stopping, negative reversal, scaling 
	  */
	 delta_w = (pred - goal ) * in ;

	 /* factor */
	 delta_w *= alpha;
	 
	 w -= delta_w;
	 
	 /* calculate network learning loop error */
	 error = (pred - goal) * (pred - goal);
	 printf("Cycle: %d      Prediction: %f      Error: %f\n", i, pred, error);
	    
      }
   }
}



void main(){
   printf("\n");

   learn_hot_gd();

   printf("\n");   
}
