#include "ej2recur.h"

void main(){

int a,b,resultado;

printf("Introduzca el dividendo: ");
scanf("%d",&a);
printf("\nIntroduzca el divisor: ");
scanf("%d",&b);

resultado=divisionRestas(a,b);

printf("\nEl resultado de la division es: %d\n",resultado);
}