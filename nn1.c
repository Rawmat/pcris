#include <stdio.h>

/* Example for an NN
 *
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




void main(){
   printf("\n");

   predict_1_1();
   printf("\n");   

}
