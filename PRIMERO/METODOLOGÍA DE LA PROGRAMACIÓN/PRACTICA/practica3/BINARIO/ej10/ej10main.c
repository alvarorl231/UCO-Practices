#include "ej10.h"

int main(int argc, char **argv){
	
	if(argc<2){
		printf("ERROR TIENES QUE ESCRIBIR EL NOMBRE DEL ARCHIVO ALEATORIO.\n");
		exit(-1);
	}

int numeros;
int *vector;
numeros=cuentanumeros(argv[1]);
vector=reservavector(numeros);

mediapares(argv[1],numeros,vector);

free(vector);

	return 0;
}