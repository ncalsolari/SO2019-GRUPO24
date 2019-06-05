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
	int iteracoes = 1000000;

	mpf_t pi;
	mpf_t var_pin;
	
	
	
	
	//inicia valroes das variaveis
	mpf_init(pi);
	mpf_init(var_pin);
	
	

	


	while(controle<iteracoes){

		// calcula um numero entre 0 e 1 com precisao de 7 casas decimais
		x = (rand() % 10000001);
		y = (rand() % 10000001);
		x = x/10000000;
		y = y/10000000;
		

		if(((x*x) + (y*y)) < 1){
			//pin = pi +1
			mpf_add_ui(var_pin,var_pin,1);
		}
	

		controle++;

	
	}
	


	// pi = (4*pin) /  iteracoes
	mpf_add(pi,var_pin,var_pin);
	mpf_add(pi,pi,var_pin);
	mpf_add(pi,pi,var_pin);

	mpf_div_ui(pi,pi,iteracoes);


	//printa pi
	gmp_printf("Valor de pi: %.6Ff\n",pi);

	
}