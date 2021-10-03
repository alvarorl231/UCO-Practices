#include "ej4.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int fil=4;
	int col=4;
	int **matriz;
	matriz=reservarMemoria(fil,col);

	rellenaMatriz(matriz,fil,col);
	imprimeMatriz(matriz,fil,col);

	int *v;
	v=minCol(matriz,fil,col);

	liberarMemoria(&matriz,fil);

return 0;
}