#include "ej7.h"


float MediaPares(char *nombre){
	FILE *fichero;
	fichero=fopen(nombre,"r");

	if(fichero==NULL){
		printf("ERROR AL ABRIR EL FICHERO <%s>\n",fichero);

	}

	char linea[256];
	float aux,suma=0;
	int cont=0;

	while(fgets(linea,256,fichero)!=NULL){
		
		fscanf(fichero,"%f",&aux);

		if((int)aux%2==0){
			suma+=aux;
			cont++;
		}
	}

	float media;

	return media=suma/cont;

	fclose(fichero);
}