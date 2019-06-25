
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <gmp.h>

//para compilar usar gcc metodo-mc-par-bn.c -o metodomcparbn -lm -lgmp -lpthread




	int numthreads = 4;// nmero total de threads
	int nm_iteracoes = 100000;


	mpf_t pi;
	mpf_t var_pin [4];  // Total de pontos no circulo p analise dentro das threads
	mpf_t totalpin; // numero total de pontos dentro do circulo

	void *check (void *indice); // sorteia e verifica os pnts nas threads

 
	int main (int argc, char *argv[]){


		mpf_set_default_prec(pow(10,5));

		srand(time(NULL)); // garante a aleatoriedade
	


		int pontos_threads_total = numthreads*nm_iteracoes; // total de pontos
		int pontos_threads_check = 0; // pontos no circulo
		pthread_t thread_name[4];  // ID das threads



		mpf_init (totalpin);
		mpf_init(pi);


		for(int i=0; i<numthreads; i++){ //todas as threads

			pthread_create(&thread_name[i],NULL, check, &i); //cria as threads
		}

	 
		for(int i = 0; i<numthreads; i++){
			pthread_join(thread_name[i], NULL);
		}

		for(int i = 0; i<numthreads; i++){ // soma todos os pontos que cairam no circulo de todas as threads
			mpf_add(totalpin,totalpin,var_pin[i]);
		}

		//calculo de pi
		mpf_add(pi,totalpin,totalpin); 
		mpf_add(pi,pi,totalpin);
		mpf_add(pi,pi,totalpin); //pi = 4*pin

		mpf_div_ui(pi,pi,pontos_threads_total);  // pi/numero de iteracoes
		

		//impreime pi
		gmp_printf("Valor de pi: %.6Ff\n",pi);

		mpf_clear (totalpin);
		mpf_clear(pi);
 }
 
 
 
 

 
void *check (void *indice){

	mpf_set_default_prec(pow(10,5));
	
	double x;
	double y;

	int thread_indice = *((int *)indice);
	
	mpf_init(var_pin [thread_indice]);
	

	for(int i = 0; i  < nm_iteracoes; i++){

		
		// calcula um numero entre 0 e 1 com precisao de 7 casas decimais
		x = (rand() % 10000001);
		y = (rand() % 10000001);
		x = x/10000000;
		y = y/10000000;

		

		if( ((x*x) + (y*y)) < 1){

			mpf_add_ui(var_pin[thread_indice],var_pin[thread_indice],1);
			//gmp_printf("Valor de pin[%d]:  %.6Ff\n", thread_indice,var_pin[thread_indice]);

		}

	}


	pthread_exit(0);

}

