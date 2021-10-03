//VA EN RELACION AL EJERCICIO 2. POR ESO NO HAY .H Y EL MAIN NO ESTA COMPLETO.
#include <stdio.h>
#include <stdlib.h>      //aqui existe la funcion qsort que usamos en el main
#include <string.h>

//POR NOMBRE:

int nombre(const void *e1,const void *e2){
     struct alumnado *a,*b;
     a=(struct alumnado*)e1;
     b=(struct alumnado*)e2;
     if(strlen(a->nombre)>strlen(b->nombre)){
          return 1;
     }
     else if(strlen(a->nombre)<strlen(b->nombre)){
          return -1;
     }
     else{
          return 0;
     }
}

//POR NOTA

int nota(const void *e1,const void *e2){
     struct alumno *a,*b;
     a=(struct alumnado*)e1;
     b=(struct alumnado*)e2;
     if(strlen(a->nota)>strlen(b->nota)){
          return 1;
     }
     else if(strlen(a->nota)<strlen(b->nota)){
          return -1;
     }
     else{
          return 0;
     }

}