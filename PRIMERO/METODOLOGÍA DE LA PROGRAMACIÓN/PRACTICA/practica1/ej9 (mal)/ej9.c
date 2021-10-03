#include "EJ9.h" 

struct Monomio{
	int coeficiente,grado;
};

void leerMonomio(struct Monomio *m){
	printf("Introduzca el coeficiente del monomio: ");
	scanf("%d\n",&m->coeficiente);
	printf("Introduzca el grado del monomio: ");
	scanf("%d\n",&m->grado);
}

void imprimirMonomio(struct Monomio m){
	printf("(%dx)^%d\n",m.coeficiente, m.grado);
}

void mayorymenor(struct Monomio *m,int n, struct Monomio *mayor, struct Monomio *menor){
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if((m+i)->grado<(m+j)->grado){
				struct Monomio aux=m[i];
				m[i]=m[j];
				m[j]=aux;
			}
		}
	}
	*mayor=m[0];
	*menor=m[n-1];
}

int resolverfuncion(struct Monomio *m, int n, int punto){
	int i,resultado=0;
	for(i=0;i<n;i++){
		resultado+=pow(((m+i)->coeficiente*punto),(m+i)->grado);
		return resultado;
	}
}
