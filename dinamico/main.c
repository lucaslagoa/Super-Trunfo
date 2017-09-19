#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "tp1.h"
#include "args.h"

typedef struct timeval Time;

int main (int argc, char *argv[]) { 
	//a função main contém as chamadas de leitura do arquivo e também as chamadas para a resolução
	//juntamente com as funções de tempo

	arg entrada, saida;

	struct rusage usage;
	struct timeval start,end;

	long long int cartaspessoa,i=0,j=0,cartastotal,*cartas,**cartas1,**cartas2,cartasadv,soma;
	
	double tempo;
	Time inicio, fim;
	
	entrada = leitura_parametro(argc,argv);

	getrusage(RUSAGE_SELF,&usage);
	start = usage.ru_stime;
	gettimeofday(&inicio,0);

	FILE *arq;
	FILE *arq2;
	arq = fopen(entrada.i,"r");
	arq2 = fopen(entrada.o,"w");

	while(fscanf(arq,"%lli",&cartaspessoa)!=EOF) {
		
		cartastotal = 2*cartaspessoa;
		cartas = (long long int *) malloc (cartastotal*sizeof(long long int));
		
		for(i = 0;i < cartastotal;i++) {
			fscanf(arq,"%lli",&cartas[i]);
		}

		soma = dinamico(cartas,cartastotal);

		getrusage(RUSAGE_SELF, &usage);
		end = usage.ru_stime;
		gettimeofday(&fim, 0);
		tempo = (fim.tv_sec + fim.tv_usec/1000000.0) - (inicio.tv_sec  + inicio.tv_usec/1000000.0);

		printf("Resposta:%lli\n",soma);
		fprintf(arq2,"Resposta:%lli\n",soma);
		printf("Tempo do sistema: %f segundos\n",tempo);
		printf("Tempo de usuário: Começo: %ld.%lds\n",start.tv_sec,start.tv_usec);
		printf("Tempo de usuário: Fim: %ld.%lds\n",end.tv_sec,end.tv_usec);
		printf("\n");
	}	

	fclose(arq);
	fclose(arq2);
	return 0;
       
}