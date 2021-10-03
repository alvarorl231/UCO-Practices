#include <stdio.h>
#include <stdlib.h>
#include "ej2.h"

int * reservaVector(int n){
	int *v;
	if((v=(int *)malloc(sizeof(int)*n))==NULL){
		printf("Error reserva");
	}
	return v;
}

void imprimeVector(int *v, int n){
	
	for(int i=0; i<n;i++){
	printf("%d ",v[i] );
	}
	printf("\n");
}

void separarVector(int *v, int n, int num,int **vmin, int **vmay, int *tam1, int *tam2){
	*tam1=0;
	*tam2=0;
	for(int i=0;i<n;i++){
		if(v[i]>=num){
			(*tam1)++;
		}
		else {
			(*tam2)++;
		}
	}
	*vmin=reservaVector(*tam2);
	*vmay=reservaVector(*tam1);

	int contmin=0;
	int contmay=0;

	for(int i=0;i<n;i++){
			if(v[i]<num){
				(*vmin)[contmin]=v[i];
				contmin++;
			}
			else{
				(*vmay)[contmay]=v[i];
				contmay++;
			}

	}

}