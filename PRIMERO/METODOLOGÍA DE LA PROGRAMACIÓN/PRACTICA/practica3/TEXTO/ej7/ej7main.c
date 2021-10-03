#include "ej7.h"

int main(int argc, char **argv){

char nombre[256];
int elementos,elsuperior,elinferior;

printf("Introduce el nobre del fichero a crear: ");
scanf("%s",nombre);

printf("Introduce el numero de elementos aleatorios que tendra: ");
scanf("%d",&elementos);

printf("Introduce el extremo inferior del intervalo: ");
scanf("%d",&elinferior);

printf("Introduce el extremo superior del intervalo: ");
scanf("%d",&elsuperior);

creaFicheroAleatorio(nombre,elementos,elsuperior,elinferior);

printf("La media de los numeros pares del fichero %s es %f",argv[1],mediapares(argv[1]));
	return 0;
}
