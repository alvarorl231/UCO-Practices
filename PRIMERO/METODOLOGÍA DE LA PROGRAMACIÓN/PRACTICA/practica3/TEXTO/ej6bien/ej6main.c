#include "ej6.h"

int main(int argc, char **argv){
	if(argc<5){
		printf("DEBES ESCRIBIR EL NOMBRE, NUMERO DE ELENTOS, RANGO SUPERIOR Y EL INFERIOR DE TUS NUMEROS ALEATORIOS");
		exit(-1);
	}

	CreaFichero(argv);


	return 0;
}