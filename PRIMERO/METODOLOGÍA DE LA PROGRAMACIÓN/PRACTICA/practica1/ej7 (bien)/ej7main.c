#include "EJ7.h"

int main(){

int n=6;
int vec[n];
float med,var,dt;
printf("Introduzca los valores de un vector de 6 elementos: ");
for(int i=0;i<n;i++){
	printf("v[%d]= ",i);
	scanf("%d",&vec[i]);
	printf("\n");
}
printf("El vector es:");
for(int j=0;j<n;j++){
	printf(" %d ",vec[j]);
}


estadisticasVector(vec,n,&med,&var,&dt);
printf("La media de los elementos del vector es: %f\n",med);
printf("La varianza de los elementos del vector es: %f\n",var);
printf("La desviacion tipica de los elementos del vector es: %f\n",dt);


return 0;
}