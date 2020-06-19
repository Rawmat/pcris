#include <stdio.h>

/* Example for an NN
 *
 */



/* hot/cold learning */
void learn_hot_cold(){
   float in = -1.0;
   float w = 0.8;
   float pred, pred_p, pred_m;
   float goal = 2.0;
   float re, re_p, re_m;
   float error, err, err_p, err_m;
   float hl = 0.001;
   int i;

   for(i = 0; i < 300; i++){

      /* tre step 
       * 1 - normal prediction
       * 2 - prediction with weight plus
       * 3 - prediction with weight minus
       * choose the one with lower error
       * error is prediction minus goal
       * (squared) for gives priority to higher error and
       * and when averaging to not consider opposite miss same magnitude
       *
       * hot learning is trying without considering error of the prediction
       * without knowing direction, only by trying
       * and the fixed increase can make not reaching the goal, only oscillate around
       */

      {
	 /* normal prediction */
	 pred = in * w; 
	 re = (pred - goal );
	 err = re * re;

	 /* calculate network learning loop error */
	 error = (pred - goal) * (pred - goal);
	 printf("Cycle: %d      Prediction: %f      Error: %f\n", i, pred, error);
	    
      }
      
      {
	 /* prediction with wieght plus */
	 pred_p = in * (w + hl); 
	 re_p = (pred_p - goal );
	 err_p = re_p * re_p;
      }

      {
	 /* prediction with wieght minus */
	 pred_m = in * (w - hl); 
	 re_m = (pred_m - goal );
	 err_m = re_m * re_m;
      }

      // choose who do best
      if ( (err > err_p) || (err > err_m) )
	 if (err_p < err_m)
	    w += hl;
	 else
	    w-= hl;
   }
}





void main(){
   printf("\n");

   learn_hot_cold();

   printf("\n");   
}
