#include "EJ8.h"

int main(){

	int digit,mayus,minus,espa;
	char cad[50]="Pepito Grillo 2001";
	printf("La cadena es:%s\n",cad);
		

	estadisticasCadena(cad, &digit, &mayus, &minus, &espa);
	printf("El numero de digitos de la cadena es: %d\n",digit);
	printf("El numero de mayusculas de la cadena es: %d\n",mayus);
	printf("El numero de minusculas de la cadena es: %d\n",minus);
	printf("El numero de espacios de la cadena es: %d\n",espa);

	return 0;
}