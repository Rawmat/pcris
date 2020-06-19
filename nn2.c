#include <stdio.h>

/* Example for an NN
 *
 */


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



void main(){
   printf("\n");

   predict_3_1();

   printf("\n");
}
