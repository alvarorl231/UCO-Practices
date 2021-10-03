#include "funciones.h"

int main(){

	int filas,columnas;
	
	printf("Introduzca el numero de filas:");
	scanf("%d",&filas);
	printf("Ahora, introduzca el numero de columnas:");
	scanf("%d",&columnas);

	int **m;
	m=reservarMemoria(filas,columnas);
	printf("Tu matriz de %dx%d ha sido reservada con exito",filas,columnas);

	rellenaMatriz(m,filas,columnas);
	imprimeMatriz(m,filas,columnas);
	printf("\n");

	int div;
	int sumadiv;

	divisiblestres(m,filas,columnas,&div,&sumadiv);
	printf("\nLos elementos divisibles entre 3 de la matriz son: %d\n",div);
	printf("Los suma de los elementos divisibles entre 3 de la matriz es: %d\n",sumadiv);

	liberarMemoria(&m,filas);


	return 0;
}

;