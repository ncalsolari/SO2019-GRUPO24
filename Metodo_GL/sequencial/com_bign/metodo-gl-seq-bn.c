
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <gmp.h>
#include <time.h>

//precisao
	mpf_set_default_prec(pow(10,5));
	
//inicializando variaveis com valor 0

	mpf_t pi;
	mpf_t var_a;
	mpf_t var_b;
	mpf_t var_t;
	mpf_t var_p;
	
	mpf_t var_a1;
	mpf_t var_b1;
	mpf_t var_t1;
	mpf_t var_p1;
	
	
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
	

void main(){
	
	
	
	
	while(i<100){
		
			
			//a1 = (a+b)/2
		mpf_add(var_a1,var_a,var_b);
		mpf_div_ui(var_a1,var_a1,2);
		
		
		//b1 = sqrt(a*b)
		mpf_mul_ui(var_b1,var_a,var_b);
		mpf_sqrt(varb1,varb1);
		
		
		//t1= t-p(a-a1)^2
		mpf_sub(var_t1,var_a,var_a1);
		mpf_pow_ui(var_t1,var_t1,2);
		mpf_mul_ui(var_t1,var_p,var_t1);
		mpf_sub(var_t1,var_t,var_t);
		
		
		//p1 = 2*p
		mpf_mul_ui(var_p1,2,var_p);
		
		
		// pi == ((a1+b1)^2)/(4*t1)
		mpf_add(pi,var_a1,var_b1);
		mpf_pow_ui(pi,pi,2);
		mpf_div_ui(pi,pi,4);
		mpf_div_ui(pi,pi,var_t1);
		
		
		//atualiza as variaveis
		
		mpf_set(var_a,var_a1);
		mpf_set(var_b,var_b1);
		mpf_set(var_t,var_t1);
		mpf_set(var_p,var_p1);
		
		
		i++;
		
		
		//printa pi
		gmp_printf("Valor de pi: %.6Ff\n",pi);
		
		

	}
	
	
	
}

