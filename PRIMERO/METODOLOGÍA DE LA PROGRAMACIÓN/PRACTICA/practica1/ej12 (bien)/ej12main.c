#include "EJ12.h"

int main(){
	
	int n,rango,nindimpares,nindpares;
	printf("¿De cuantos elementos quieres su vector?:");
	scanf("%d",&n);
	int v[n],*indicesimpares[n],*indicespares[n];
	printf("Los numeros aleatorios entre 0 y :");
	scanf("%d",&rango);

	rellenarVectorAleatorio(v,n,rango);
	imprimirVector(v,n);
	printf("Idices impares:\n");
	crearIndiceImpares(v,indicesimpares,n,&nindimpares);
	imprimeIndices(indicesimpares,nindimpares);
	printf("Idices divisibles entre 3:\n");
	crearIndiceDivisibles(v,indicespares,n,&nindpares);
	imprimeIndices(indicespares,nindpares);

	return 0;
}