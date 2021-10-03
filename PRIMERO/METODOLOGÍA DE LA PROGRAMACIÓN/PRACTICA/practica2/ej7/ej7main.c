#include "ej7.h"
#include "ej6.h"
/**
@file ej7main.c
@version 1.0
@author Alvaro Roldan L.
@date 11/04/2020
@brief Programa rellena un vector con los numeros menores de las columnas de una matriz generada aleatoriamente.
*/
int main(){
	int filas1,columnas1,filas2,columnas2;
	int **m1,**m2,**mult;
	
	printf("Introduce el numero de filas de tu matriz1: ");
	scanf("%d",&filas1);
	printf("Introduce el numero de columnas de tu matri1z: ");
	scanf("%d",&columnas1);
	
	m1=reservarMemoria(filas1,columnas1);
	rellenaMatriz(m1,filas1,columnas1);

	printf("Introduce el numero de filas de tu matriz2: ");
	scanf("%d",&filas2);
	printf("Introduce el numero de columnas de tu matriz2: ");
	scanf("%d",&columnas2);

	m2=reservarMemoria(filas2,columnas2);
	rellenaMatriz(m2,filas2,columnas2);

	imprimeMatriz(m1,filas1,columnas1);
	imprimeMatriz(m2,filas2,columnas2);

	mult=reservarMemoria(filas1,columnas2);
	mult=multiplicarMxM(m1,m2,filas1,columnas1,columnas2);
	imprimeMatriz(mult,filas1,columnas2);

	liberarMemoria(&m1,filas1);
	liberarMemoria(&m2,filas2);
	liberarMemoria(&mult,filas1);

	return 0;
}
