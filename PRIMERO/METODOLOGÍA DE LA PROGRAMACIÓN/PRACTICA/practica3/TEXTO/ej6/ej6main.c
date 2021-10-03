#include "ej6.h"

int main(){

char nombre[256];
int elementos,elsuperior,elinferior;

printf("Introduce el nobre del fichero a crear: ");
scanf("%s",nombre);

printf("Introduce el numero de elementos aleatorios que tendra: ");
scanf("%d",&elementos);

printf("Introduce el extremo superior del intervalo: ");
scanf("%d",&elsuperior);

printf("Introduce el extremo inferior del intervalo: ");
scanf("%d",&elinferior);

creaFicheroAleatorio(nombre,elementos,elsuperior,elinferior);

	return 0;
}