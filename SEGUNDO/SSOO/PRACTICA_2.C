//                                                              PRACTICA 2
//                                                             Hebras/Hilos

//INCLUDES BASICOS

#include <unistd.h>         //Básica
#include <pthread.h>        //Para las funciones de pthread.

#include <stdlib.h>         //Para exit()

#include <errno.h>          //CONTROL DE ERRORES. printf("errno value %d",errno);
#include <stdio.h>          //perror("fork error"); 
#include <string.h>         //Para perror

//__________________________________________________________________________________________________________________________________________________________*/

//pthread_create() y pthread_join()
//Ejemplo:
int main(){

pthread_t hilos[NHEBRAS];               //Declaración de hilos. Si es más de uno como en este caso, hacemos un vector.

for(int i=0;i<NHEBRAS;i++)
{
    if(pthread_create(&hilos[i],NULL,(void*)aleatorios,NULL)!=0) //Creación y Control de errores.
                    //(&hilo, NULL, función con (void *), NULL ó Argumentos para la función)
    {
        perror("pthread_create error\n");
        printf("Error, errno value %d\n",errno);
        exit(EXIT_FAILURE);
    }
}

    float * subtotal; //Lo que recogemos de join, debe ser puntero.

for(int i=0; i<NHEBRAS; i++)
{
    if(pthread_join(hilos[i],(void **) &subtotal)!=0)  //Recogida de hilos y valores. Y control de errores.
                //(hilo, NULL, lo que recogemos de la función con(void **)y &)
    {
        perror("pthread_join error");
        exit(EXIT_FAILURE);
    }
    printf("Valor recibido: %0.2f\n",*subtotal);
    total+=*subtotal;
}
}

//Funciones para los hilos, ejemplo:
void *aleatorios(void *nada)
{
    printf("Soy la hebra [%lu] hija ....\n",pthread_self());    //Función que te dice el id de la hebra que ha entrado a la función.
    .
    .
    float *suma = malloc(sizeof(float));                        //El valor que necistemos devolver deberá ser creado con puntero y con malloc.
    .
    .
    pthread_exit((void *)suma);                                 /*Para finalizar una hebra/hilo ha de ser de esta forma, pasamos como parametro
}                                                                aquello que queremos devolver, en caso de que no queramos devolver nada, NULL
.                                                                pthread_exit(NULL);*/


//__________________________________________________________________________________________________________________________________________________________*/

//PTHREAD_DETACH
//Sirve para eliminar todos los elementos del hilo, si se usa detach, no se usará join ¡¡¡¡(MUY POCO USADO EN LAS PRACTICAS)!!!!
void *thread(void *vargp) 
{ 
    int error = 0; 

   error = pthread_detach(pthread_self());    /*En cuanto se haga el pthread_detach() se eliminará el estado de esta hebra. 
 .                                              Hacer un join() de esta hebra puede  provocar estados impredecibles*/ 
   /* Manejar el error */ 

   pthread_exit(NULL); 
} 

int main() 
{ 
   pthread_t tid; 

   pthread_create(&tid, NULL, thread, NULL); 
   
   pthread_exit(NULL);                           //Finaliza aquí el hilo principal.
}
