/*
Para compilação no linux, lembrar de incluir as bibliotecas, como descrito abaixo. 
- gcc nome_programa.c -o nome_programa -lm -lgmp
 */



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <gmp.h>
#include <time.h>



void main(){

	mpf_set_default_prec(pow(10,5));
	srand(time(NULL));
	
// variaveis de controle
	double x ;
	double y ;
	int controle = 0;
	//int iteracoes = 1000000;

	mpf_t pi;
	mpf_t var_pin;
	//mpf_t controle;
	mpf_t iteracoes;
	
	
	
	
	//inicia valroes das variaveis
	mpf_init(pi);
	mpf_init(var_pin);
	//mpf_init(controle);
	mpf_init(iteracoes);


	mpf_init_set_d(iteracoes,1000000);
	
	

	


	while(controle<1000000){

		// calcula um numero entre 0 e 1 
		x = drand48();
		y = drand48();
		

		if(((x*x) + (y*y)) < 1){
			//pin = pi +1
			mpf_add_ui(var_pin,var_pin,1);
		}
	

		controle ++;

	
	}
	


	// pi = (4*pin) /  iteracoes
	mpf_add(pi,var_pin,var_pin);
	mpf_add(pi,pi,var_pin);
	mpf_add(pi,pi,var_pin);

	mpf_div(pi,pi,iteracoes);


	//printa pi
	gmp_printf("Valor de pi: %.6Ff\n",pi);


	mpf_clear(pi);
	mpf_clear(var_pin);
	mpf_clear(iteracoes);

	
}