#include <stdio.h>
#include <stdlib.h>
#include "ej2.h"


int main(){
	int *v;
	v=reservaVector(4);
	v[0]=1;
	v[1]=10;
	v[2]=2;
	v[3]=9;

	imprimeVector(v,4);

	int *vmenor, *vmayor;
	int tam1,tam2;

	separarVector(v, 4 , 6, &vmenor, &vmayor, &tam1, &tam2);

	imprimeVector(vmenor,tam2);
	imprimeVector(vmayor,tam1);


}