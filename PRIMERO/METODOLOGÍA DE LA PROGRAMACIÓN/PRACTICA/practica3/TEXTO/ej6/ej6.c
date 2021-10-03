#include "ej6.h"

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
