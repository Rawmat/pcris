#include <stdio.h>
#include <stdlib.h>

/***********************************************************************
 * Due input, un output
 * ogni input e collegato tramite un peso all'output (valori reali non binari)
 * output riceve somma di inpute pesati e questo e il valore dell'output
 * uscita lineare
 *
 * 03/12/2017 
 */







/*
Apri file training
leggi k righe e popola in1, in2, output

cicla ff ogni riga di training
  calcola output
  calcola errore
  correggi pesi
*/





FILE *f;
#define TRAIN_FILE "./train_set"
#define TRAIN_RECS 5
	
float in1[TRAIN_RECS];
float in2[TRAIN_RECS];
float target[TRAIN_RECS];

float w1;
float w2;

float error;
float out;

float rate;
int epochs;




void
read_training_set(){
	int i;
	
	f = fopen(TRAIN_FILE, "r");

	if (f == NULL){
		printf("\nTrain File non trovato!\n");
		exit (-1);
	}

	for(i = 0; i < TRAIN_RECS; i++) {
		if( fscanf(f, "%f %f %f", &in1[i], &in2[i], &target[i]) == EOF) {
			printf("Training set no match for number/type of records TRAIN_RECS !\n");
			exit(-1);
		}
	}
}

void
ff(){
	int i;

	for(i = 0; i < TRAIN_RECS; i++) {
		/* calcola out */
		out = (in1[i] * w1) + (in2[i] * w2);

		/* calcola errore */ 
		error = target[i] - out;

		/* aggiorna pesi */
		w1 += (error * rate);
		w2 += (error * rate);
	}
	/* print evaluation */
	printf("\nI1 %7.3f     I2%7.3f     Target %7.3f     Out %7.3f     Error %7.3f ",
	       in1[i], in2[i], target[i], out, error);
}

void
train(){
	int i;

	for(i=0; i<epochs; i++) 
		ff();		
}




void
init(){
	w1 = 1.0;
	w2 = 1.0;
	rate = 0.2;
	epochs = 1000;
}


int
main(){
	init();	
	read_training_set();
	train();
}
