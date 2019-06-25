



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



	mpf_t pi;
	mpf_t var_a;
	mpf_t var_b;
	mpf_t var_t;
	mpf_t var_p;
	
	mpf_t var_a1;
	mpf_t var_b1;
	mpf_t var_t1;
	mpf_t var_p1;



	void *calc_a1 (void *indice); // faz os calculos nas threads

	void *calc_b1 (void *indice); // faz os calculos nas threads

	void *calc_t1 (void *indice);

	void *calc_p1 (void *indice);

	

void main(){


	pthread_t thread_name[4];  // ID das threads


	//precisao
	mpf_set_default_prec(pow(10,5));
	
	//inicializando variaveis com valor 0
	mpf_init(pi);
	mpf_init(var_a);
	mpf_init(var_b);
	mpf_init(var_t);
	mpf_init(var_p);
	mpf_init(var_a1);
	mpf_init(var_b1);
	mpf_init(var_t1);
	mpf_init(var_p1);
	
	
	// valores iniciais
	mpf_init_set_d(var_a,1);
	mpf_init_set_d(var_b,1/sqrt(2));
	mpf_init_set_d(var_t,0.25);
	mpf_init_set_d(var_p,1);
	
	
	//iterador
	
	int i = 0;
	
	
	while(i<10000){
		
	printf("%d\n", 10000 - i );




	pthread_create(&thread_name[0],NULL, calc_a1, &i); //cria as threads

	
	pthread_create(&thread_name[1],NULL, calc_b1, &i); //cria as threads

	
	

	
	pthread_create(&thread_name[3],NULL, calc_p1, &i); //cria as threads



	
	pthread_join(thread_name[0], NULL);

	pthread_join(thread_name[1], NULL);


	pthread_join(thread_name[3], NULL);

	

	pthread_create(&thread_name[2],NULL, calc_t1, &i); //cria as threads

	pthread_join(thread_name[2], NULL);


	
		// pi == ((a1+b1)^2)/(4*t1)
		mpf_add(pi,var_a1,var_b1);

		mpf_pow_ui(pi,pi,2);

		mpf_div_ui(pi,pi,4);

	
		mpf_div(pi,pi,var_t1);
		
		
		
		//atualiza as variaveis
		
		mpf_set(var_a,var_a1);
		mpf_set(var_b,var_b1);
		mpf_set(var_t,var_t1);
		mpf_set(var_p,var_p1);
		
		
	
		i++;
		
		
		
		
	

	}
	//printa pi
		gmp_printf("Valor de pi: %.15Ff\n",pi);





	mpf_clear(pi);
	mpf_clear(var_a);
	mpf_clear(var_b);
	mpf_clear(var_t);
	mpf_clear(var_p);
	mpf_clear(var_a1);
	mpf_clear(var_b1);
	mpf_clear(var_t1);
	mpf_clear(var_p1);
	
	
	
	
}






void *calc_a1 (void *indice){
	


	mpf_set_default_prec(pow(10,5));
	

	//a1 = (a+b)/2
	mpf_add(var_a1,var_a,var_b);
	mpf_div_ui(var_a1,var_a1,2);
		


	
	pthread_exit(0);

}




void *calc_b1 (void *indice){


	mpf_set_default_prec(pow(10,5));
	
	//b1 = sqrt(a*b)
		mpf_mul(var_b1,var_a,var_b);
		mpf_sqrt(var_b1,var_b1);
				

	
	pthread_exit(0);

}




void *calc_t1 (void *indice){


	mpf_set_default_prec(pow(10,5));


	//t1= t-p(a-a1)^2
		mpf_sub(var_t1,var_a,var_a1);
		mpf_pow_ui(var_t1,var_t1,2);
		mpf_mul(var_t1,var_p,var_t1);
		mpf_sub(var_t1,var_t,var_t1);

				

	
	pthread_exit(0);

}



void *calc_p1 (void *indice){

	mpf_set_default_prec(pow(10,5));
	


	//p1 = 2*p
		mpf_add(var_p1,var_p,var_p);

		


	pthread_exit(0);

}
