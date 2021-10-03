#ifndef __EJ9__
#define __EJ9__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generarAleatorios(int *v, int n,int sup,int inf);
int *reservaVector(int n);
void creaFicheroAleatorio(char *fichero,int *v,int n);

#endif