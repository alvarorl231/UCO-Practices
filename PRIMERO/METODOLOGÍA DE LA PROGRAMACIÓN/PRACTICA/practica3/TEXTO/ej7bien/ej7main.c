#include "ej7.h"

int main(int argc, char **argv){

	if(argc<2){
		printf("ERROR, DEBES PASAR EL NOMBRE FEL FICHERO\n");
		exit(-1);
	}

	float media;
	media=MediaPares(argv[1]);
	printf("La media de los numeros pares de tu fichero es %f",media);

	
	return 0;
}