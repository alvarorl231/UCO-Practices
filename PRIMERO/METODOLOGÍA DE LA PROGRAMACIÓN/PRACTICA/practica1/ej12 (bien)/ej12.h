#ifndef __EJ12__
#define __EJ12__

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void rellenarVectorAleatorio (int v[],int n,int rango);
void imprimirVector(int v[], int n);
void crearIndiceImpares(int v[],int **ind, int n, int *nindice);
void crearIndiceDivisibles(int v[], int *ind[] ,int n,int *nindice);
void imprimeIndices(int *ind[],int nindice);

#endif