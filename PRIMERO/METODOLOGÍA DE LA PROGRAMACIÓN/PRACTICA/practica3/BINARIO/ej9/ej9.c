#include "ej9.h"

int *reservaVector(int n){
	int *v;
	v=(int*)calloc(n,sizeof(int));
	if(v==NULL){
		printf("\nError al reservar memoria");
		exit(-1);
	}
	return v;
}


void generarAleatorios(int *v, int n,int inf,int sup){
	time_t t;
	srand((int)time(&t));
	for(int i=0;i<n;i++){
		v[i]=rand()%(sup-inf+1)+(inf);
	}
}


void creaFicheroAleatorio(char *fichero,int *v,int n){
	FILE *f;

	f=fopen(fichero,"wb");

	if(f==NULL){
		printf("\nError, no se puedo abrir el fichero <%s>",fichero);
		exit(-1);
	}

	fwrite(v,sizeof(int),n,f);

fclose(f);
}
