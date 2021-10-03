#include "ej10.h"

int *reservavector(int n){
int *v;
	if((v=(int*)malloc(n*sizeof(int)))==NULL){
		printf("ERROR AL RESERVAR MEMORIA\n");
		exit(-1);
	}
return v;
}


int cuentanumeros(char *fichero){
	FILE *f;
	if((f=fopen(fichero,"rb"))==NULL){
		printf("ERROR AL ABRIR EL FICHERO\n");
		exit(-1);
	}

int numero;
int cont=0;

	while(fread(&numero,sizeof(int),1,f)==1){
		cont++;
	}
return cont;
fclose(f);
}


void mediapares(char *fichero,int n,int *v){
	float suma=0;
	float media=0;
	int npares=0;

	FILE *f;
	if((f=fopen(fichero,"rb"))==NULL){
		printf("ERROR AL ABRIR EL FICHERO\n");
		exit(-1);
	}

	fread(v,sizeof(int),n,f);

	for(int i=0;i<n;i++){
		if((v[i])%2==0){
			suma+=v[i];
			npares++;
		}
	}

		media=suma/npares;

	printf("La media de los pares es: %f\n",media);

fclose(f);
}