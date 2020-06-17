#include <stdio.h>

/* Esempio di NN 
 * Dati input e tramite i weights si fa prediction
 * solo la forward propagation
 */



/* un input e un predict 
 */
void predict_1_1(){
   float in[] = { 1.0, 0.5, 0.2 };
   float w = 0.8;
   float pred;

   /* una singola informazione (input) scalata con il peso
    * restituisce il predict */
   pred = in[0] * w;

   printf("Input: %.2f Weight: %.2f Prediction %.2f\n", in[0], w, pred);
}



/* Tre input e un predict 
 * piu accurata di 1 1
 */
void predict_3_1(){
   float in[] = { 1.0, 0.5, 0.2 };
   float w[] = { 0.8, 0.6, 1.2 };
   float p1, p2, p3, pred;

   /* predict singoli dagli input differenti con pesi differenti */
   p1 = in[0] * w[0];
   p2 = in[1] * w[1];
   p3 = in[2] * w[2];

   /* somma pesata, i tre predict locali con sensibilita diversa (pesi) vengono sommati
    * per contribuire alla predict */
   pred = p1 + p2 + p3;

   printf("Input1: %.2f * Weight1 %2f = %.2f\n", in[0], w[0], p1);
   printf("Input2: %.2f * Weight2 %2f = %.2f\n", in[1], w[1], p2);
   printf("Input3: %.2f * Weight3 %2f = %.2f\n", in[2], w[2], p3);
   printf("Pred = %2f + %.2f + %.2f = %.2f\n", p1, p2, p3, pred);
}


void main(){
   printf("\n");
   predict_1_1();
   printf("\n");   
   predict_3_1();
   printf("\n");      
}
