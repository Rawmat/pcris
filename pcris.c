/* Perceptron.c - A perceptron with 2 inputs and a training set */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N_TRAIN_RECS   6     // Training set dimension
#define N_EPOCHS  10000     // Number of iteration epochs
#define LEARN_RATE  0.1     // Learning rate

float tin1[N_TRAIN_RECS];    // Training set for input n.1
float tin2[N_TRAIN_RECS];    // Training set for input n.2
float tout[N_TRAIN_RECS];    // Training set target output
float w1;                    // Weight for input n.1
float w2;                    // Weight for input n.2
float b;                     // bias


void read_train_set();
float calc_net_value(float, float, float, float);
float calc_output_value(float, float);
float calc_weight_correction(float, float);
void train();
int train_one_epoch();


void read_train_set(){

   int i;

   FILE *f;
   f = fopen("./training", "r");
   if(f == NULL){
      printf("Training set file open error !\n");
      exit(-1);
   }

   for(i = 0; i < N_TRAIN_RECS; i++) {
      if( fscanf(f, "%f %f %f", &tin1[i], &tin2[i], &tout[i]) == EOF) {
	 printf("Training set no match for number/type of records N_TRAIN_RECS !\n");
	 exit(-1);
      }

      // output 1 is true, 0 is false
      if(tout[i] > 0.0)
	 tout[i] = 1.0;
      else
	 tout[i] = 0.0;
   }
}



void write_train_set(){
   int i;

   printf("=== TRAINING SET ===\n");
   for(i = 0; i < N_TRAIN_RECS; i++)
      printf("Input1: %f Input2: %f T.Output %f\n", tin1[i], tin2[i], tout[i]);
   printf("\n");
}



float calc_net_value(float i1, float i2, float w1, float w2){

   return((i1 * w1) +( i2 * w2 ) );
}



float calc_output_value(float net, float bias){

   if(net > bias)
      return 1.0;
   else
      return 0.0;
}



float calc_weight_correction(float error, float input){
   
   return(error * input * LEARN_RATE) ;
}



float calc_error(float actual_out, float target_out){

   return(target_out - actual_out);
}
   
 

int train_one_epoch(){
   
   int i;
   float net;
   float out;
   float err;
   float epoch_error;     // this epoch has no error

   epoch_error = 0.0;

   printf("\n=== EPOCH ===\n");
   
   for( i = 0; i < N_TRAIN_RECS; i++){

      // net value
      net = calc_net_value(tin1[i], tin2[i], w1, w2);

      // activation function
      out = calc_output_value(net, b);

      // calc error
      err = calc_error(out, tout[i]);

      // calc this epoch error
      epoch_error += abs(err);
      

      // print perceptron evaluation
      printf("\nI1 %7.3f     i2 %7.3f     Target %7.3f     Out %7.3f     Err %7.3f ",
	     tin1[i], tin2[i], tout[i], out, err);
      
      // adjust weights of inputs based on error
      w1 = w1 + calc_weight_correction(err, tin1[i]);
      w2 = w2 + calc_weight_correction(err, tin2[i]);

      // print perceptron adjustment 
      printf("   W1 %7.3f     W2 %7.3f",
	     w1, w2);
      
   }
   printf("\n=============\n\n\n");

   return (epoch_error);
}


      
void train(){
   int i;
   float epoch_error;

   for( i= 0; i< N_EPOCHS; i++){
      epoch_error = train_one_epoch();
      /*         if (epoch_error ==   0.0 ){
	 printf("******** SOLVED in %d epochs *********\n", i);
	 printf("w1 = %f, w2 = %f, bias = %f\n", w1, w2, b);
	 i = N_EPOCHS; // exit

      }
      */
   }
}



void p_init(){

   b = 1.0;
   
   w1 = 0.1;
   w2 = -0.7;
}



// ============================================================
void main(){

   p_init();
   read_train_set();
   // write_train_set();
   train();

}
 