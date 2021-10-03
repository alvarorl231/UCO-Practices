#include "ej9.h"


int *reservamemoria(int n){
	int *v;
	v=(int*)malloc(n*sizeof(int));
	if(v==NULL){
		printf("ERROR AL CREAR EL VECTOR DINAMICO\n");
	}
	return v;
}


int *aleatorios(char** dato){
	int num=atoi(dato[2]);
	int sup=atoi(dato[3]);
	int inf=atoi(dato[4]);

	int *vec=reservamemoria(num);
	time_t t;
	srand((int)time(&t));

	for(int i=0;i<num;i++){
		vec[i]=rand()%(sup-inf+1)+(inf);
	}

	return vec;
}


void creabinario(char** dato){
int n=atoi(dato[2]);

FILE *fichero;
fichero=fopen(dato[1],"wb");

if(fichero==NULL){
		printf("ERROR AL ABRIR EL FICHERO <%S>\n",fichero);
}

int *vector=aleatorios(dato);

fwrite(vector,sizeof(int),n,fichero);

fclose(fichero);
}