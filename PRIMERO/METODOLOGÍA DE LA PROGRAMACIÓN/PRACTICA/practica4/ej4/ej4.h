#ifndef __EJ4__
#define __EJ4__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct lista{
	float coef;
	int exp;
	struct lista *siguiente;
};

typedef struct lista Lista;

Lista *NuevoElemento();
void anyadeMonomio(Lista **cabeza,float coef,int exp);
void muestraPolinomio(Lista *cabeza,int n);
float evaluaPolinomio(Lista *cabeza,int cont);
void eliminaMonomio(Lista **cabeza,float coef, int exp);
int contiene(Lista *cabeza,float coeficiente,int exponente);

#endif