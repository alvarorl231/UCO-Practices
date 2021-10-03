#include "ej4recur.h"

void main(){
int a,result;
printf("Introduce un numero: ");
scanf("%d",&a);

result=sumadigitos(a);
printf("\nLa suma de los digitos de %d es %d\n",a,result);

}