#include "EJ8.h"

void estadisticasCadena(char cadena[], int *digitos, int *mayusculas, int *minusculas, int *espacios){
/*	int i,cont=0;
	for(i=0;cadena[i]!='\0';i++){
		if(isdigit(cadena[i])){
			cont++;
		}
	}
	*digitos=cont;
	cont=0;

	for(i=0;cadena[i]!='\0';i++){
		if(isupper(cadena[i])){
			cont++;
		}
	}
	*mayusculas=cont;
	cont=0;

	for(i=0;cadena[i]!='\0';i++){
		if(islower(cadena[i])){
			cont++;
		}
	}
	*minusculas=cont;
	cont=0;

	for(i=0;cadena[i]!='\0';i++){
		if(isspace(cadena[i])){
			cont++;
		}
	}
	*espacios=cont;
*/
	int i;
	
	*digitos=0;
	*mayusculas=0;
	*minusculas=0;
	*espacios=0;

	for(i=0;cadena[i]!='\0';i++){
		if(isdigit(cadena[i])){
			(*digitos)++;
		}
		if(isupper(cadena[i])){
			(*mayusculas)++;
		}
		if(islower(cadena[i])){
			(*minusculas)++;
		}
		if(isspace(cadena[i])){
			(*espacios)++;
		}
	}
}

