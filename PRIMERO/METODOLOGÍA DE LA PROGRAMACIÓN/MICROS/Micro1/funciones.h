#ifndef __FUNCIONES__
#define __FUNCIONES__


#include <stdio.h>
#include <stdlib.h>
/**
@file funciones.h
@author XXXX
@date 13/04/2020
@brief Cabeceras funciones.
*/
/**
@fn reservarMemoria (int nFil, int nCol) Reserva memoria de una matriz
@author XXXX
@pre Pedimos nfil y ncol en el main al usuario, para generar la matriz.
@param nfil Numero de filas.
@param ncol Numero de columnas.
@brief Reserva memoria de manera dinámica a través de la función malloc según el numero introducido en las filas y columnas pedidas al usuario.
@return matriz Tipo doble puntero, con memoria reservada dinamicamente.
*/
int ** reservarMemoria (int nFil, int nCol);
void rellenaMatriz (int **matriz, int nFil, int nCol);
void imprimeMatriz (int **matriz, int nFil, int nCol);
void divisiblestres(int **matriz,int nfil, int ncol,int *divisibles, int *sumadiv);
void liberarMemoria(int ***matriz, int nFil);

#endif 
