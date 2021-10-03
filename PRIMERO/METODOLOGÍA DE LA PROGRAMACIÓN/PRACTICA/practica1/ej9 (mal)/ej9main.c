#include "EJ9.h" 

int main(){

struct Monomio{
	int coeficiente,grado;
};

int n,i,x;
printf("Cuantos monomios tiene su polinomio?:\n");
scanf("%d",&n);
struct Monomio polinomio[n], mayor, menor;

for(i=0;i<n;i++){
	leerMonomio(*polinomio[i]);
}


printf("Tu polinomio es: \n");
for(i=0;i<n;i++){
	imprimirMonomio(polinomio[i]);
}


mayorymenor(polinomio,n,&mayor,&menor);
printf("Tu monomio mayor es (%dx)^%d\n",mayor.coeficiente, mayor.grado);
printf("Tu monomio menor es (%dx)^%d\n",menor.coeficiente, menor.grado);


printf("Introduzca un valor para darle a su polinomio: ");
scanf("%d",&x);
printf("El resultado de ' ");
for(i=0;i<n;i++){
	imprimirMonomio(polinomio[i]);
}
printf(" con x=%d es = %d\n",x,resolverfuncion(polinomio,n,x));

return 0;
}