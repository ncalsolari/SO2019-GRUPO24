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

		srand(time(NULL));

		int var_m;

		double var_s, var_e, r, var_t;

		double sigma, t, media, media2, stddev, intervalo, conf_min, conf_max;



		scanf("%lf %lf %lf %lf %lf %d", &var_s, &var_e, &r, &sigma, &var_t, &var_m );
		

		
		

		double vetor[var_m];

		double nmero_aleatorio;

			media2=0;
			media = 0;






		//calculando o t temporario
		for(int i=0; i<var_m ; i++){

		
			nmero_aleatorio= (rand() % 10000001);

			nmero_aleatorio = nmero_aleatorio / 10000000;



			double exponencial1 = var_t*(r-(0.5*sigma*sigma)) + (sigma*sqrt(var_t)*nmero_aleatorio);

			t = (var_s*pow(M_E,exponencial1));




			double exponencial2 = (-1)*r*var_t;

			vetor[i]= pow(M_E,exponencial2)*fmax((t - var_e),0);

			



		}



		//calculando a media 
		for(int j=0; j<var_m ; j++){

			media= media + vetor[j];


		}

		media = media / (double)var_m;
	



		//calculando o desvio padrao nao enviesado
		for(int k = 0; k < var_m ; k++){

			media2= media2 + ((vetor[k] - media)*(vetor[k] - media));

		}

		media2 = media2 / (((double)var_m ) - 1);
		

	
		stddev = sqrt(media2);
	


		//intervalo confianca
		intervalo = 1.96*(stddev/(double)sqrt(var_m));
		printf("%lf\n", intervalo );

		conf_max= media + intervalo;

		conf_min= media - intervalo;


		printf("\nS:%lf \n", var_s);
		printf("E:%lf \n", var_e);
		printf("r:%lf \n", r);
		printf("sigma:%lf \n", sigma);
		printf("T:%lf \n", var_t);
		printf("M:%d \n\n", var_m);

		printf("Confidence Interval: %lf, %lf\n", conf_min, conf_max);



	}