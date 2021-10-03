#include "EJ10.h"

int main(){
	
	int n=5;
	double v[n];
	double suma;

	leeVector(v,n);
	escribeVector(v,n);
	sumapositivos(v,n,&suma);
	printf("La suma de los datos positivos de tu vector es :%lf\n",suma);



	return 0;
}