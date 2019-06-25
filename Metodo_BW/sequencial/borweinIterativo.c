

/*
Para compilação no linux, lembrar de incluir as bibliotecas, como descrito abaixo. 
- gcc metodo-gl-par-bn.c -o metodoglparbn -lm -lgmp -lpthread
 */



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <gmp.h>
#include <time.h>

void main(){


	//precisao
	mpf_set_default_prec(pow(10,5));

	//inicializando variaveis com valor 0

	mpf_t um;
	mpf_t var_a;
	mpf_t var_b;
	mpf_t var_p;
	
	mpf_t var_a1;
	mpf_t var_b1;
	mpf_t var_p1;

	mpf_t var_t1;  //variavel auxiliar
	mpf_t var_t2;
	mpf_t var_t3;
	
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

	// valores iniciais

	mpf_init_set_d(var_a,sqrt(2));
	mpf_init_set_d(var_b,0);
	mpf_init_set_d(var_p, 2 + sqrt(2));
	mpf_init_set_d(um, 1);
	

	int TAMANHO=10000;
	

	int i;

	for(i=0; i<TAMANHO; i++){

		//a1 = [sqrt(a0)+1/sqrt(a0)]2
		mpf_sqrt(var_t1,var_a);
		mpf_div(var_t2,um,var_t1);
		mpf_add(var_t2,var_t2,var_t1);
		mpf_div_ui(var_a1,var_t2,2);


		//b1 = (1 + b0)*srqt(a0)/[a0 + b0]
		mpf_add_ui(var_t2,var_b,1);
		mpf_mul(var_t2,var_t2,var_t1);
		mpf_add(var_t3,var_a,var_b);
		mpf_div(var_b1,var_t2,var_t3);

		//c1 = (1 + a1)*p0*b1/(1 + b1)
		mpf_add_ui(var_t1,var_a1,1);
		mpf_mul(var_t2,var_p,var_b1);
		mpf_mul(var_t1,var_t1,var_t2);
		mpf_add_ui(var_t2,var_b1,1);
		mpf_div(var_p1,var_t1,var_t2);

		//atualiza as variáveis
		mpf_set(var_a,var_a1);
		mpf_set(var_b,var_b1);
		mpf_set(var_p,var_p1);




		
	}
	gmp_printf("Valor de pi: %.100Ff\n",var_p);

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

	
}



