
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

 	int numthreads = 10;  // Numero total de threads
	mpf_t pi;
	mpf_t var_pin [10];  // Total de pontos da thread 
	mpf_t var_iteracao_total [10];  // Pontos no circulo


	mpf_init(pi);
	mpf_init(var_pin);
	mpf_init(var_iteracao_total);

	void *check (void *param); // sorteia e verifica os pnts nas threads
 
 

	int main (int argc, char *argv[]){

	srand(time(NULL));

	int pontos_threads_total = 0; // total de pontos
	int pontos_threads_check = 0; // pontos no circulo
	pthread_t thread_name[10];  // ID das threads
 
 
	// Para todas as threads      
	for(int i=0; i<numthreads; i++){
	// cria a i-esima thread
		pthread_create(&tid[i],NULL, check, &i);
	}

	**********************************************
 
	// Para cada thread 
	for (i = 0; i< NUMTHR ; i++){
	// espera que as threads terminem
	pthread_join (tid[i], NULL);
       }	
 
      for (i = 0; i< NUMTHR ; i++){
          totalp += num_ptos[i];  // totalp = totalp + num_ptos[i]
          totalc += num_ptos_cir[i]; // totalc = totalp + num_ptos[i]
       }	
 
 
// Calcula o valor de pi e imprime na tela	
	pi = 4.0*(((double)totalc)/((double)totalp)); // transforma totalp
						      // e totalc em double
							
	printf("Valor de pi:%fn\n",pi);
}
 
 
 
 
 
void *calcula (void *param) {
 
	int i;
	int thrnum = *((int *)param); // O número da thread ()
	double x,y,quad;
	num_ptos[thrnum] = 0;
	num_ptos_cir[thrnum] = 0;
 
	for (i = 0; i<1000000000; i++){
 
		x = drand48(); // sorteia um número de 0 a 1
		y = drand48(); // sorteia um número de 0 a 1


		printf("x eh: %lf\n",x );
		printf("y eh: %lf\n",y );

		quad = ((x*x) + (y*y));
		// Se a soma dos quadrados for menor que R = 1
		// então caiu no círculo		
		if (quad <= 1){
			num_ptos_cir[thrnum] ++; // conta pontos no círculo		
		}
 
		num_ptos[thrnum] ++; // incrementa os pontos totais da thread N (0 a 9)
 
		// A cada 10 mil iterações imprime na tela
                if (i%10000==0)
                        printf("thread: %i n\n",thrnum);
	}
 
	// Imprime na tela a qtde de pontos no círculo
	// e no total de cada thread 
	printf ("Circ t%i:%dn\n",thrnum,num_ptos_cir[thrnum]);
	printf ("Total t%i:%dn\n\n\n",thrnum,num_ptos[thrnum]);	
	pthread_exit(0);
}