#include <stdio.h>

/* Example for an NN
 *
 * Predict / Compare / Learn
 */

/* One input and one prediction */
void predict_1_1(){
   float in[] = { 1.0, 0.5, 0.2 };
   float w = 0.8;
   float pred;

   /* only one known information (input) scaled with the weight
    * gives the prediction */
   pred = in[0] * w;

   printf("ONE SINGLE PREDICTION\n");
   printf("Input: %.2f Weight: %.2f Prediction %.2f\n", in[0], w, pred);
}



/* Three inputs and one predict
 * more inputs (information) gives more information
 * then more accurate prediction
 */
void predict_3_1(){
   float in[] = { 1.0, 0.5, 0.2 };
   float w[] = { 0.8, 0.6, 1.2 };
   float p1, p2, p3, pred;

   /* Single prediction for the different information (input) with own weight */
   p1 = in[0] * w[0];
   p2 = in[1] * w[1];
   p3 = in[2] * w[2];

   /* Weighted sum - the three independent prediction  summed to contribute 
    * to the single prediction */
   pred = p1 + p2 + p3;

   printf("ONE SINGLE PREDICTION WITH THREE INPUT CONTRIBUTION\n");
   printf("Input1: %.2f * Weight1 %.2f = %.2f\n", in[0], w[0], p1);
   printf("Input2: %.2f * Weight2 %.2f = %.2f\n", in[1], w[1], p2);
   printf("Input3: %.2f * Weight3 %.2f = %.2f\n", in[2], w[2], p3);
   printf("Pred = %.2f + %.2f + %.2f = %.2f\n", p1, p2, p3, pred);
}

/* One input and three prediction (different responses)
 */
void predict_1_3(){
   float in[] = { 1.0, 0.5, 0.2 };
   float w[] = { 0.8, 0.6, 1.2 };
   float p1, p2, p3;

   /* Three different prediction with the same information (input)
    * this are really a three single predictions
    */
   p1 = in[0] * w[0];
   p2 = in[0] * w[1];
   p3 = in[0] * w[2];

   /* Weighted sum - the three independent prediction summed to contribute 
    * to the single prediction */
   printf("THREE SEPARATE PREDICTION WITH THE SAME INPUT INFORMATION WITH DIFFERENT WEIGHT\n");
   printf("Input1: %.2f * Weight1 %.2f Pred1 = %.2f\n", in[0], w[0], p1);
   printf("Input1: %.2f * Weight2 %.2f Pred2 = %.2f\n", in[0], w[1], p2);
   printf("Input1: %.2f * Weight3 %.2f Pred3 = %.2f\n", in[0], w[2], p3);

}



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

   predict_1_1();
   printf("\n");   

   predict_3_1();
   printf("\n");

   predict_1_3();
   printf("\n");

   learn_hot_cold();
   printf("\n");   

   learn_hot_gd();
   printf("\n");   
}
