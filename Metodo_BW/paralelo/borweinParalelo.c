



/*
Para compilação no linux, lembrar de incluir as bibliotecas, como descrito abaixo. 
- gcc metodo-gl-par-bn.c -o metodoglparbn -lm -lgmp -lpthread
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <gmp.h>



	int numthreads = 4;// nmero total de threads



	//inicializando variaveis
	mpf_t um;
	mpf_t var_a;
	mpf_t var_b;
	mpf_t var_p;
	
	mpf_t var_a1;
	mpf_t var_b1;
	mpf_t var_p1;

	//variavel auxiliar
	mpf_t var_t1;  
	mpf_t var_t2;
	mpf_t var_t3;
	mpf_t var_t4;



	void *calc_a1 (void *indice); // faz os calculos nas threads

	void *calc_b1 (void *indice); // faz os calculos nas threads

	void *calc_p1 (void *indice);



	

void main(){


	pthread_t thread_name[3];  // ID das threads
	//precisao
	mpf_set_default_prec(pow(10,5));	
	//inicializando variaveis com valor 0
	mpf_init(um);
	mpf_init(var_a);
	mpf_init(var_b);
	mpf_init(var_p);
	mpf_init(var_a1);
	mpf_init(var_b1);
	mpf_init(var_p1);
	mpf_init(var_t1);
	mpf_init(var_t2);
	mpf_init(var_t3);
	mpf_init(var_t4);

	// valores iniciais

	
	mpf_init_set_d(var_a,sqrt(2));
	mpf_init_set_d(var_b,0);
	mpf_init_set_d(var_p, 2 + sqrt(2));
	mpf_init_set_d(um, 1);
	
	//iterador
	int i = 0;

	int TAMANHO = 10000;
	
	
	
	while(i<TAMANHO){
		int i1, i2 , i3;
		i1 = 1;
		i2 = 2;
		i3 = 3;
		
	pthread_create(&thread_name[0],NULL, calc_a1, &i1);
	pthread_create(&thread_name[1],NULL, calc_b1, &i2); 
	pthread_join(thread_name[0], NULL);
	pthread_join(thread_name[1], NULL);
	pthread_create(&thread_name[2],NULL, calc_p1, &i3);
	pthread_join(thread_name[2], NULL);
	//atualiza as variaveis
	mpf_set(var_a,var_a1);
	mpf_set(var_b,var_b1);
	mpf_set(var_p,var_p1);

	i++;
	
	}	
	gmp_printf("\nvalor de pi: %.15Ff\n\n",var_p);

	mpf_clear(um);
	mpf_clear(var_a);
	mpf_clear(var_b);
	mpf_clear(var_p);
	mpf_clear(var_a1);
	mpf_clear(var_b1);
	mpf_clear(var_p1);
	mpf_clear(var_t1);
	mpf_clear(var_t2);
	mpf_clear(var_t3);
	mpf_clear(var_t4);
}

void *calc_a1 (void *indice){
	mpf_set_default_prec(pow(10,5));
	//a1 = [sqrt(a0)+1/sqrt(a0)]/2
	mpf_sqrt(var_t1,var_a);
	mpf_div(var_t2,um,var_t1);
	mpf_add(var_t2,var_t2,var_t1);
	mpf_div_ui(var_a1,var_t2,2);
	pthread_exit(0);
}

void *calc_b1 (void *indice){
	mpf_set_default_prec(pow(10,5));
	//b1 = (1 + b0)*srqt(a0)/[a0 + b0]
	mpf_add_ui(var_t3,var_b,1);
	mpf_sqrt(var_t4,var_a);
	mpf_mul(var_t3,var_t3,var_t4);
	mpf_add(var_t4,var_a,var_b);
	mpf_div(var_b1,var_t3,var_t4);	
	pthread_exit(0);
}

void *calc_p1 (void *indice){
	mpf_set_default_prec(pow(10,5));
	//p1 = (1 + a1)*p0*b1/(1 + b1)
	mpf_add_ui(var_t1,var_a1,1);
	mpf_mul(var_t2,var_p,var_b1);
	mpf_mul(var_t1,var_t1,var_t2);
	mpf_add_ui(var_t2,var_b1,1);
	mpf_div(var_p1,var_t1,var_t2);	
	pthread_exit(0);
}