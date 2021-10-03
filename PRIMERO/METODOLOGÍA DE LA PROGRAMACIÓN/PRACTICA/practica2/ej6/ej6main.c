#include "ej6.h"
/**
@file ej6main.c
@version 1.0
@author Alvaro Roldan L.
@date 11/04/2020
@brief Programa rellena un vector con los numeros menores de las columnas de una matriz generada aleatoriamente.
*/
int main(){
	int filas,columnas;
	int **m;
	
	printf("Introduce el numero de filas de tu matriz: ");
	scanf("%d",&filas);
	printf("Introduce el numero de columnas de tu matriz: ");
	scanf("%d",&columnas);

	m=reservarMemoria(filas,columnas);
	rellenaMatriz(m,filas,columnas);
	imprimeMatriz(m,filas,columnas);
	int *vmin;
	vmin=minCol(m,filas,columnas);
	liberarMemoria(&m,filas);

	return 0;
}
