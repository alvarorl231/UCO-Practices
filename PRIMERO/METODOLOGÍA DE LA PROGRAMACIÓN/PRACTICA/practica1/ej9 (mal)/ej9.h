#ifndef __EJ9__
#define __EJ9__

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Monomio;
void leerMonomio(struct Monomio *m);
void imprimirMonomio(struct Monomio m);
void mayorymenor(struct Monomio *m,int n, struct Monomio *mayor, struct Monomio *menor);
int resolverfuncion(struct Monomio *m, int n, int punto);

#endif