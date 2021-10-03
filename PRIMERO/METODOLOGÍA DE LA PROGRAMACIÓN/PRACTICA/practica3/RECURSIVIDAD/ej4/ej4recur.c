#include "ej4recur.h"

int sumadigitos(int numero){
	if(numero<10){
		return numero;
	}
	else{
		return numero%10+sumadigitos(numero/10);
	}

}
