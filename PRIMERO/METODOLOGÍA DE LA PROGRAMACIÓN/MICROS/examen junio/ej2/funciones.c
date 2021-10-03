/*------------------------------------------------------------------*/
/* NOMBRE Y APELLIDOS: �lvaro Rold�n Lucena                         */
/* DNI: 31023651D                                                   */
/*------------------------------------------------------------------*/
#include "funciones.h"

//HAZ AQUI LOS INCLUDE QUE SEAN NECESARIOS
#include <stdio.h>
/*------------------------------------------------------------------*/
/*Ejercicio 2: Recursividad
    -nEle: n�mero de elementos de V1 y V2.
    -V1, V2, VR: Los dos vectores a mezclar y el vector resultado, 
         respectivamente. Estos vectores ya est�n reservados en el main.

/*------------------------------------------------------------------*/

void ejercicio2(int nEle, int* V1, int* V2, int* VR){
   //INCLUYE AQUI LA LLAMADA A TU FUNCI�N RECURSIVA 
  VR=recursiva(nEle,V1,V2,VR);
}

//ESCRIBE AQU� TU FUNCION RECURSIVA Y TODAS LAS FUNCIONES QUE CONSIDERES NECESARIAS

int *recursiva(int n,int *v1, int *v2, int *vres){
	for(int i=0;i<n/2;i++){
		if(n%2==0){
 		vres[i]=v1[i];
 		vres[i+1]=v2[i];
			return vres;
		}
		else{
			return recursiva(n-1,v1,v2,vres);
		}
	}
}