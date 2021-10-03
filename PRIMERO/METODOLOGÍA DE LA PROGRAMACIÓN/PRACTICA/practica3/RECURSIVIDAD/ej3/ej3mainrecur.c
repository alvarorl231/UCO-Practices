#include "ej3recur.h"

void main(){
char cadena[100],letra[10];
int resultado;

printf("Introduce una cadena: ");
fgets(cadena,100,stdin);
printf("\nIntroduce una palabra a buscar: ");
scanf("%s",letra);

int tam=strlen(cadena);

resultado=cuentaX(cadena,letra,tam);
printf("\nSe ha encontado %s, %d veces.\n",letra,resultado);



}