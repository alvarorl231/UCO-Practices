/*------------------------------------------------------------------*/
/* NOMBRE Y APELLIDOS: Álvaro Roldán Lucena                         */
/* DNI: 31023651D                                                   */
/*------------------------------------------------------------------*/
#include "funciones.h"

//HAZ AQUI LOS INCLUDE QUE SEAN NECESARIOS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*------------------------------------------------------------------*/
/*Ejercicio 3: Listas
  -nEle1, nEle2: El número de elementos de los vectores C1 y C2 respectivamente
  -C1 y C2: Vectores con los alumnos presentados en primera y segunda convocatoria. Ya se han reservado y rellenado en el main.
  -LP: Lista de alumnos presentados a alguna de las convocatorias.
  -VALOR DEVUELTO: La función devolverá el número de alumnos de la lista LP.

/*------------------------------------------------------------------*/

int ejercicio3(int nEle1, int nEle2, struct datos* C1, struct datos* C2, struct lista ** LP)
{


  //INCLUYE AQUI EL CODIGO NECESARIO PARA RESOLVER EL EJERCICIO
int cont;
cont=introducirNuevo(LP,C1,C2);
  //RECUERDA HACER EL RETURN
 return cont;
}

Lista *NuevoElemento(){
	return ((Lista*)malloc(sizeof(Lista)));
}

int introducirNuevo(Lista **cabeza,struct datos *c1,struct datos *c2){
	Lista *aux=NULL;
	aux=NuevoElemento();
	int cont=0;
	if(aux==NULL){
		printf("ERROR EN LA RESERVA DE MEMORIA\n");
		exit(-1);
	}
	int cod1,cod2;
	char nom1[LENGTH],nom2[LENGTH];

	
	int i=0;
while(aux!=NULL){

	cod1=c1->codigo;
	cod2=c2->codigo;
	strcpy(nom1,c1->nombre);
	strcpy(nom2,c2->nombre);

	if(cod1!=cod2){
		aux->codigo=cod1;
		strcpy(nom1,aux->nombre);
		aux->sig=*cabeza;
		*cabeza=aux;
		aux->codigo=cod2;
		strcpy(nom2,aux->nombre);
		aux->sig=*cabeza;
		*cabeza=aux;
		cont++;
		}
		i++;
	}
	return cont;
}

