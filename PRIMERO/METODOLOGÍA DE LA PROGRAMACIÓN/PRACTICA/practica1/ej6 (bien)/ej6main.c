#include <stdio.h>
#include <stdlib.h>
#include "ej6.h"

int main(){

int a,b,result;
printf("Introduce un numero: ");
scanf("%d",&a);
printf("Introduce otro numero: ");
scanf("%d",&b);

int min=minimo(a,b);
printf("El numero menor entre %d y %d es: %d\n",a,b,min);
minimo_referencia(a,b,&result);
printf("El numero menor entre %d y %d es: %d\n",a,b,result);


	return 0;
}
