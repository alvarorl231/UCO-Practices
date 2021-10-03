#include "EJ10.h"

int i;

void leeVector(double v[],int n){
	printf("Introduce los datos de tu vector:");
	for(i=0;i<n;i++){
	scanf(" %lf ",&v[i]);
	}
}

void escribeVector(double v[],int n){
	printf("\nEstos son los datos de tu vector:");
for(i=0;i<n;i++){
	printf(" %lf ",v[i]);
	}
		printf("\n");
}


void sumapositivos(double v[],int n,double *resultado){
*resultado=0;
	for(i=0;i<n;i++){
		if(v[i]>0){
			(*resultado)+=v[i];
		}
	}
}