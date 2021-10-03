#include "ej7.h"

int generarAleatorios(int sup,int inf){
	return (rand()%(sup-inf+1)+(inf));
}

void creaFicheroAleatorio(char *fichero, int n, int sup, int inf){
	FILE *f;

	time_t t;
	srand((int)time(&t));
	f=fopen(fichero,"w");

	if(f==NULL){
		printf("\nError, no se puedo abrir el fichero <%s>",fichero);
		exit(-1);
	}

	for(int i=0;i<n;i++){
		fprintf(f, "%d\n",generarAleatorios(sup,inf));
	}
fclose(f);
}

float mediapares(char *fichero){
	char linea[256];
	float media=0,aux;
	int cont=0;
	FILE *Fichero;

	Fichero=fopen(fichero,"r");
	if(Fichero==NULL){
		printf("\nError al abrir el fichero <%s>",fichero);
		exit(-1);
	}

	while(fgets(linea,256,Fichero)!=NULL){
		sscanf(linea,"%f",&aux);
		if((int)aux%2==0){
			media=media+aux;
			cont++;
		}
	}
	media=media/cont;
	fclose(Fichero);
	return media;
}