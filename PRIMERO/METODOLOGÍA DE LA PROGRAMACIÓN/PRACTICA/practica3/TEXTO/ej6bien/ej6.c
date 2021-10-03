#include "ej6.h"

int generarAleatorios(int sup,int inf){
	return (rand()%(sup-inf+1)+(inf));
}


void CreaFichero(char **datos){
	FILE *fichero;

	time_t t;
	srand((int)time(&t));

	fichero=fopen(datos[1],"w");

	if(fichero==NULL){
		printf("ERROR AL ABRIR EL FICHERO <%s>",datos[1]);
	}

	int n=atoi(datos[2]);
	int inf=atoi(datos[3]);
	int sup=atoi(datos[4]);

	for(int i=0;i<n;i++){
		fprintf(fichero,"%d\n",generarAleatorios(inf,sup));
	}

	fclose(fichero);
}