#include "ej6.h"
/**
@date 11/04/2020
@author Alvaro Roldan L.
@fn reservarMemoria (int nFil, int nCol) Reserva memoria de una matriz 
@param nFil Numero de filas
@param nCol Numero de columnas
@return Matriz con memoria reservada
*/
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
/**
@date 11/04/2020
@author Alvaro Roldan L.
@fn rellenaMatriz (int **matriz, int nFil, int nCol) 
Rellena la matriz de forma aleatoria 
@param matriz Matriz 
@param nFil Numero de filas
@param nCol Numero de columnas
@return Nada
*/
void rellenaMatriz (int **matriz, int nFil, int nCol){
	time_t t;
	srand((int)time(&t));
	for(int i=0;i<nFil;i++){
		for(int j=0;j<nCol;j++){
			matriz[i][j]=rand()%20+1;
		}
	}
}
/**
@date 11/04/2020
@author Alvaro Roldan L.
@fn imprimeMatriz (int **matriz, int nFil, int nCol) 
Imprime los valores de la matriz
@param matriz Matriz 
@param nFil Numero de filas
@param nCol Numero de columnas
@return Nada
*/
void imprimeMatriz (int **matriz, int nFil, int nCol){
	printf("\nTu matriz es:");
	for(int i=0;i<nFil;i++){
		printf("\n");
		for(int j=0;j<nCol;j++){
			printf("%d ",matriz[i][j]);
		}
	}
}
/**
@date 11/04/2020
@author Alvaro Roldan L.
@fn minCol (int **matriz, int nFil, int nCol) 
Crea un vector con los elementos menores de cada columna
@param matriz Matriz 
@param nFil Numero de filas
@param nCol Numero de columnas
@return Vector con elementos menores
*/
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

/**
@date 11/04/2020
@author Alvaro Roldan L.
@fn liberarMemoria(int ***matriz, int nFil) 
Libera el espacio de memoria de la matri
@param matriz Matriz de triple puntero
@param nFil Numero de filas
@return Nada
*/
void liberarMemoria(int ***matriz, int nFil){
	for(int i=0;i<nFil;i++){
		free(**matriz);
	}
	free(*matriz);
	(*matriz)=NULL;
}
