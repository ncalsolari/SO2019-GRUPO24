/*
Para compilação no linux, lembrar de incluir as bibliotecas, como descrito abaixo. 
- gcc nome_programa.c -o nome_programa -lm -lgmp -lpthread
 */



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <gmp.h>
#include <unistd.h>




	

	double vetor[100000]; // tamanho de M

	int var_m;

	double var_s, var_e, r, var_t;

	double sigma, t, media, media2, stddev, intervalo, conf_min, conf_max;




	void *black_scholes (void *indice); 

	void main(){

		int numthreads = 4;

		pthread_t thread_name[4];  // ID das threads


		scanf("%lf %lf %lf %lf %lf %d", &var_s, &var_e, &r, &sigma, &var_t, &var_m );



		
		


		 //todas as threads
		int i0 = 0;
		int i1 = 1;
		int i2 = 2;
		int i3 = 3;
		pthread_create(&thread_name[0],NULL, black_scholes, &i0); //cria as threads
	
		pthread_create(&thread_name[1],NULL, black_scholes, &i1);
	
		pthread_create(&thread_name[2],NULL, black_scholes, &i2);
	
		pthread_create(&thread_name[3],NULL, black_scholes, &i3);

			
		

	 
		for(int i = 0; i<numthreads; i++){
			pthread_join(thread_name[i], NULL);
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
	

		conf_max= media + intervalo;

		conf_min= media - intervalo;


		printf("\nS:%lf \n", var_s);
		printf("E:%lf \n", var_e);
		printf("r:%lf \n", r);
		printf("sigma:%lf \n", sigma);
		printf("T:%lf \n", var_t);
		printf("M:%d \n\n", var_m);

		printf("Confidence Interval: (%lf, %lf)\n", conf_min, conf_max);



	}




		void *black_scholes (void *indice){

			srand(time(NULL));

			int thread_indice = *((int *)indice);

			printf("%d\n", thread_indice );

			double nmero_aleatorio;

			media2=0;
			media = 0;


			//calculando o t temporario


			//primeiro quarto das iteracoes
			if(thread_indice == 0){

				for(int i=0; i<(var_m/4) ; i++){

				
					nmero_aleatorio= (rand() % 10000001);

					nmero_aleatorio = nmero_aleatorio / 10000000;



					double exponencial1 = var_t*(r-(0.5*sigma*sigma)) + (sigma*sqrt(var_t)*nmero_aleatorio);

					t = (var_s*pow(M_E,exponencial1));




					double exponencial2 = (-1)*r*var_t;

					vetor[i]= pow(M_E,exponencial2)*fmax((t - var_e),0);

					

				}


			}
				



				//segundo quarto das iteracoes
				if(thread_indice == 1){

				for(int i=(var_m/4); i<(2*var_m/4) ; i++){

				
					nmero_aleatorio= (rand() % 10000001);

					nmero_aleatorio = nmero_aleatorio / 10000000;



					double exponencial1 = var_t*(r-(0.5*sigma*sigma)) + (sigma*sqrt(var_t)*nmero_aleatorio);

					t = (var_s*pow(M_E,exponencial1));




					double exponencial2 = (-1)*r*var_t;

					vetor[i]= pow(M_E,exponencial2)*fmax((t - var_e),0);

					

				}


			}


				//terceiro quarto da iteracoes
				if(thread_indice == 2){

				for(int i=(2*var_m/4); i<(3*var_m/4) ; i++){

				
					nmero_aleatorio= (rand() % 10000001);

					nmero_aleatorio = nmero_aleatorio / 10000000;



					double exponencial1 = var_t*(r-(0.5*sigma*sigma)) + (sigma*sqrt(var_t)*nmero_aleatorio);

					t = (var_s*pow(M_E,exponencial1));




					double exponencial2 = (-1)*r*var_t;

					vetor[i]= pow(M_E,exponencial2)*fmax((t - var_e),0);

					

				}


			}


				//quarto quarto das iteracoes
				if(thread_indice == 3){

				for(int i=(3*var_m/4); i<var_m ; i++){

				
					nmero_aleatorio= (rand() % 10000001);

					nmero_aleatorio = nmero_aleatorio / 10000000;



					double exponencial1 = var_t*(r-(0.5*sigma*sigma)) + (sigma*sqrt(var_t)*nmero_aleatorio);

					t = (var_s*pow(M_E,exponencial1));




					double exponencial2 = (-1)*r*var_t;

					vetor[i]= pow(M_E,exponencial2)*fmax((t - var_e),0);

					

				}


			}



			pthread_exit(0);


		}