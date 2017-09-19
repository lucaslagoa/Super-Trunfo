#include "tp1.h"


long long int **alocarmatriz (long long int cartastotal) { 
	//essa função realiza a alocação das matrizes que serão utilizadas
	//para os calculos de acordo com a função dinamico 
	long long int **vetorcartas,i;
	vetorcartas=malloc(cartastotal*sizeof(long long int));
	for(i = 0;i < cartastotal; i++) {
		vetorcartas[i]= (long long int *) malloc (cartastotal*sizeof(long long int));
	}
	return vetorcartas;
}

long long int dinamico (long long int *cartas, long long int cartastotal) {
	//essa função realiza os cálculos necessários para calcular o super trunfo

	long long int g=cartastotal,i,j,k=0,cartasadv=0,**cartas1,**cartas2;

	cartas1=alocarmatriz(cartastotal); 
	cartas2=alocarmatriz(cartastotal);

	for (i = 0;i < g;i++){
		j=i;
		k=0;

	while(j < g){
		if (k == j) {
			cartas1[k][j] = cartas[k];
			cartas2[k][j] = 0;
		}
		else {
		 if(cartas[k] + cartas2[k+1][j] < cartas[j] + cartas2[k][j-1]) {
			cartas1[k][j] = cartas2[k][j-1] + cartas[j];
			cartas2[k][j] = cartas1[k][j-1];
			
		} else {
			cartas1[k][j] = cartas2[k+1][j] + cartas[k];
			cartas2[k][j] = cartas1[k+1][j];
		}
		}
	k++;
	j++;
	}
	}
	
	cartasadv = cartas1[0][cartastotal-1];
	return cartasadv; 

}

	





