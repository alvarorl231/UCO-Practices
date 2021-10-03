#include "funciones.h"

int ** reservarMemoria (int nfil, int ncol){
	int**matriz;
	int i,error=0;
	matriz=(int**)malloc(nfil*sizeof(int*));
	if(matriz==NULL){
		printf("\nError en la reserva memoria");
	}
	for(i=0;i<nfil;i++){
		matriz[i]=(int*)malloc(ncol*sizeof(int));

		if(matriz[i]==NULL){
				printf("\nError en la reserva memoria");
		}
	}
return (matriz);
}

void rellenaMatriz (int **matriz, int nfil, int ncol){
	int i,j;
	for(i=0;i<nfil;i++){
		printf("\n");
		for(j=0;j<ncol;j++){
			printf("matriz[%d][%d]= ",i,j);
			scanf("%d",&matriz[i][j]);
		}
	}
}

void imprimeMatriz (int **matriz, int nfil, int ncol){
	int i,j;
	printf("Su matriz es:");
	for(i=0;i<nfil;i++){
		printf("\n");
		for(j=0;j<ncol;j++){
			printf(" %d ",matriz[i][j]);
		}
	}
}

void divisiblestres(int **matriz,int nfil, int ncol,int *divisibles, int *sumadiv){
	int i,j;
	*divisibles=0;
	*sumadiv=0;
	for(i=0;i<nfil;i++){
		for(j=0;j<ncol;j++){
			if((matriz[i][j])%3==0){
				(*divisibles)++;
				(*sumadiv)+=(matriz[i][j]);
			}
		}

	}
	if((*divisibles)==0){
		printf("No existen elementos que sean divisibles entre 3");
	}

}

void liberarMemoria(int ***matriz, int nFil){
	for(int i=0;i<nFil;i++){
		free(**matriz);
	}
	free(*matriz);
	(*matriz)=NULL;
}
