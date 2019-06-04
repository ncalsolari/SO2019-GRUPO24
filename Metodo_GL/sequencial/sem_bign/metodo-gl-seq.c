

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <gmp.h>
#include <time.h>


void main(){

	double pi;

	double var_a;
	double var_b;
	double var_t;
	double var_p;




	double var_a1;
	double var_b1;
	double var_t1;
	double var_p1;


	var_a = 1;
	var_b = (1/sqrt(2));
	var_t = 0.25;
	var_p = 1;

	var_a1 = ((var_a + var_b)/2);
	var_b1 = sqrt(var_a*var_b);
	var_t1 = var_t - var_p*((var_a-var_a1)*(var_a-var_a1));
	var_p1 = 2*var_p;

	pi = ((var_a1 + var_b1)*(var_a1 + var_b1))/(4*var_t1);

	int controle = 1;

	printf("a %lf\n",var_a );
	printf("b %lf\n",var_b );
	printf("t %lf\n",var_t );
	printf("p %lf\n",var_p );
	printf("a1 %lf\n",var_a1 );
	printf("b1 %lf\n",var_b1);
	printf("t1 %lf\n",var_t1 );
	printf("p1 %lf\n",var_p1 );







	printf("entrei no while \n\n" );

	while(controle<1000){
		
		pi = ((var_a1 + var_b1)*(var_a1 + var_b1))/(4*var_t1);

		var_a = var_a1;
		var_b = var_b1;
		var_t = var_t1;
		var_p = var_p1;
		
		
		var_a1 = (var_a + var_b)/2;
		var_b1 = sqrt(var_a*var_b);
		var_t1 = var_t - var_p*((var_a-var_a1)*(var_a-var_a1));
		var_p1 = 2*var_p;
		
		controle++;
/*
		if(controle%10 == 0){
			printf("%d\n", controle );
			printf("%.15lf\n", pi ); // trocar para mostrar apenas as 6 casas
		}
		*/
		
	}
	printf("%.15lf\n", pi );
}