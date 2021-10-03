#include "ej4.h"

int ** reservarMemoria (int nFil, int nCol){
	int**matriz;
	int i,error=0;
	matriz=(int**)malloc(nFil*sizeof(int*));
	if(matriz==NULL){
		printf("\nError en la reserva memoria");
	}
	for(i=0;i<nFil;i++){
		matriz[i]=(int*)malloc(nCol*sizeof(int));

		if(matriz[i]==NULL){
				printf("\nError en la reserva memoria");
		}
	}
return (matriz);
}

void rellenaMatriz (int **matriz, int nFil, int nCol){
	time_t t;
	srand((int)time(&t));
	for(int i=0;i<nFil;i++){
		for(int j=0;j<nCol;j++){
			matriz[i][j]=rand()%20+1;
		}
	}
}

void imprimeMatriz (int **matriz, int nFil, int nCol){
	printf("\nTu matriz es:");
	for(int i=0;i<nFil;i++){
		printf("\n");
		for(int j=0;j<nCol;j++){
			printf("%d ",matriz[i][j]);
		}
	}
}

int * minCol (int **matriz, int nFil, int nCol){
	int *v;
	int i,j;

	v=(int*)calloc(nCol,sizeof(int));
	if (v==NULL)printf("ERROR");

	for(j=0;j<nCol;j++){
		v[j]=matriz[0][j];
		for(i=0;i<nFil;i++){
			if(matriz[i][j]<v[j]){
				v[j]=matriz[i][j];
		}
	}
}

	printf("\nEl vector minimo es:\n");
	for(int i=0; i<nCol;i++){
		printf("%d ",v[i]);
	}
	printf("\n");

	return (v);
}


void liberarMemoria(int ***matriz, int nFil){
	for(int i=0;i<nFil;i++){
		free(**matriz);
	}
	free(*matriz);
	(*matriz)=NULL;
}