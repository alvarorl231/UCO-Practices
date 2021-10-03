#ifndef __EJ6__
#define __EJ6__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
@file ej6.h
@version 1.0
@author Alvaro Roldan L.
@date 11/04/2020
@brief Cabeceras funciones ej6.c
*/
int ** reservarMemoria (int nFil, int nCol);
void rellenaMatriz (int **matriz, int nFil, int nCol);
void imprimeMatriz (int **matriz, int nFil, int nCol);
int * minCol (int **matriz, int nFil, int nCol);
void liberarMemoria(int ***matriz, int nFil);

#endif
