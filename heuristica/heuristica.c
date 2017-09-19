#include "heuristica.h"

long long int heuristica (long long int *cartas,long long int cartastotal){
	//função que realiza as operações para o algoritmo de heuristica

	long long int j=0,soma=0,somatotal=0,x=0,y=0,k=0,indice=0;
	j=cartastotal-1;

	while(k<j) {
		
			x=cartas[k]+cartas[j-1];
			y=cartas[j]+cartas[k+1];
			
			if(x>y){
			soma=cartas[k];
			k++;

			} else { 
			soma=cartas[j];
			j--;
			}
			

			if(indice%2==0){
				somatotal=somatotal+soma;
			}

			indice++;
		}
	
	return somatotal;	
    }

