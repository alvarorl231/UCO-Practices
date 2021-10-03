/*------------------------------------------------------------------*/
/* NOMBRE Y APELLIDOS: Álvaro Rolán Lucena                          */
/* DNI: 31023651D                                                   */
/*------------------------------------------------------------------*/

#include "funciones.h"

//HAZ AQUI LOS INCLUDE QUE SEAN NECESARIOS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*------------------------------------------------------------------*/
/*Ejercicio 1: Ordenacion y punteros a funciones
               nEle: número de elementos del vector
               Vector: el vector a ordenar
               criterio: 0-->ascendente por indice de masa corporal
                         1-->descendente por nombre 
/*------------------------------------------------------------------*/
void ejercicio1(int nEle, struct datos* Vector, int criterio){

     if(criterio==0) 
     {
         //INCLUYE AQUI LA LLAMADA A TU FUNCIÓN DE ORDENACIÓN PARA ORDEN ASCENDENTE
        ordenaBurbuja(nEle,Vector,&ascendente);
       
                       
     }
     else 
     {
         //INCLUYE AQUI LA LLAMADA A TU FUNCIÓN DE ORDENACIÓN PARA ORDEN DESCENDENTE
                     
     }
}
//ESCRIBE AQUÍ TU FUNCION DE ORDENACIÓN Y TODAS LAS FUNCIONES QUE CONSIDERES NECESARIAS

void ordenaBurbuja(int n,struct datos*Vector,float (*funaux)(float,float)){
  int posicion,aux;
  n=6;
  for(int i=0;i<n-1;i++){
    posicion=i;
    for(int j=i+1;j<n;j++){
      if((*funaux)(Vector[j].pesoKg,Vector[posicion].alturaM)){
        posicion=j;
      }
    }
    aux=Vector[posicion].alturaM;
    Vector[posicion].pesoKg=Vector[i].alturaM;
    Vector[i].pesoKg=aux;
  }
}

float ascendente(float peso,float altura){
  float res;
  res=((peso)/pow(altura,2));
  return res;
}

/*int descendente(Persona *Vector){
  
  return ;
}*/

