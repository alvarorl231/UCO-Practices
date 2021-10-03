#include "ej1recur.h"

int main(){

int a,b;
int mcd;

printf("Introduce un numero:\n");
scanf("%d",&a);
printf("Introduce otro numero:\n");
scanf("%d",&b);

mcd=EuclidesMCD(a,b);

printf("El maximo comun divisor de %d y %d es %d\n",a,b,mcd);

}
