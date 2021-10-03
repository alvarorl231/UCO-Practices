#include "ej4.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void liberarMemoria(int ***matriz, int nFil){
	int i;
	for(i=0;i<nFil;i++){
		free((*matriz)[i]);
	}
	free(*matriz);
	(*matriz)=NULL;
}

void imprimeMatriz (int **matriz, int nFil, int nCol){
	for(int i=0;i<nFil;i++){
		for(int j=0;j<nCol;j++)
				printf("matriz[%d][%d]=%d\n",i,j,matriz[i][j]);

	}
	printf("\n");
}

void rellenaMatriz (int **matriz, int nFil, int nCol){
	time_t t;
	srand((int)time(&t));

	for(int i = 0; i<nFil; i++){
		for (int j = 0; j<nCol; j++){
			matriz[i][j]=rand()%20+1;
		}
	}	
}

int * minCol (int **matriz, int nFil, int nCol){
	int *v_min;
	
	//Reservar vector
	if((v_min=(int *)calloc(nCol,sizeof(int)))==NULL){
		printf("Error reserva");
	}

	for(int j=0; j<nCol; j++){
		v_min[j]=matriz[0][j];
		for(int i=0; i<nFil; i++){
			if(matriz[i][j]<=v_min[j]){
				v_min[j]=matriz[i][j];
			}
		}
	}

	printf("El vector minimo es:\n");
	for(int j=0; j<sizeof(v_min);j++){
		printf("%d ",v_min[j]);
	}

	return v_min;
}
