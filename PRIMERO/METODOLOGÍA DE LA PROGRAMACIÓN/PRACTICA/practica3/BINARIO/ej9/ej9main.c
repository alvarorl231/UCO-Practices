#include "ej9.h"

int main(){
/*
int argc,char** argv

char *nombre=argv[1];
int *vector;

if(argc<5){
	printf("\nError en los parametros");
	exit(-1);
}

int elementos=atoi(argv[2]),superior=atoi(argv[3]),inferior=atoi(argv[4]);

vector=reservaVector(elementos);
generarAleatorios(vector,elementos,inferior,superior);
for(int i=0;i<elementos;i++){
	printf("Vector[%d]=%d\n",i,vector[i]);
}
creaFicheroAleatorio(nombre,vector,elementos);
free(vector);

*/
int elementos,inferior,superior;
char nombre[256];

printf("\nIntroduce el nombre de tu fichero: ");
scanf("%s",nombre);

printf("\nIntroduce el numero de elementos para tu fichero: ");
scanf("%d",&elementos);

printf("\nIntroduce el EXTREMO INFERIOR de numeros aleatorios para tu fichero: ");
scanf("%d",&inferior);

printf("\nIntroduce el EXTREMO SUPERIOR de numeros aleatorios para tu fichero: ");
scanf("%d",&superior);

int *vector;
vector=reservaVector(elementos);

generarAleatorios(vector,elementos,inferior,superior);
creaFicheroAleatorio(nombre,vector,elementos);

	return 0;
}