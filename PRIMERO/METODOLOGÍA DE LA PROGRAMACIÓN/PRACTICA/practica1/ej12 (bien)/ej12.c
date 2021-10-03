#include "EJ12.h"

void rellenarVectorAleatorio (int v[],int n,int rango){
	time_t t;
	srand((int)time(&t));
	for(int i=0;i<n;i++){
		v[i]=rand()%(rango+1);
	}
}

void imprimirVector(int v[], int n){
	printf("El vector es:\n");
	for(int i=0;i<n;i++){
		printf("v[%d]= %d\n",i,v[i]);
	}
}

void crearIndiceImpares(int v[],int **ind, int n, int *nindice){
	int i;
	*nindice=0;
	for(i=0;i<n;i++){
		if(v[i]%2!=0){
			ind[*nindice]=&v[i];
			(*nindice)++;
		}
	}
}

void crearIndiceDivisibles(int v[], int *ind[] ,int n,int *nindice){
	int i;
	*nindice=0;
	for(i=0;i<n;i++){
		if(v[i]%3==0){
			ind[*nindice]=&v[i];
			(*nindice)++;
		}
	}
}

void imprimeIndices(int *ind[],int nindice){
	printf("Los indices son:\n");
	int i;
	for (i=0;i<nindice;i++){
		printf("ind[%d]= %d\n",i,*(ind[i]));
	}
}