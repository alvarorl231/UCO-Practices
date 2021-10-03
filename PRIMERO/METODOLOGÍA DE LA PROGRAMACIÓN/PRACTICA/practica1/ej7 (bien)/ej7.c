#include "EJ7.h"

void estadisticasVector(int v[],int n,float *media,float *varianza,float *desvtipica){
	int i;
	float suma=0;
//MEDIA
	for(i=0;i<n;i++){
		suma+=v[i];
	}
	*media=suma/n;
	suma=0;
//VARIANZA
	for(i=0;i<n;i++){
		suma+=pow((v[i]-*media),2);
	}
	*varianza=suma/n;
//DESVIACIÓN TIPICA
	*desvtipica=sqrt(*varianza);


}