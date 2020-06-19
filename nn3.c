#include <stdio.h>

/* Example for an NN
 *
 */


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



void main(){
   printf("\n");

   predict_1_3();

   printf("\n");

}
