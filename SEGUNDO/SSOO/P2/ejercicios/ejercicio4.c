#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <string.h>


int global = 0;


void * incremento (void * arg)
{
    printf("Hebra [%lu] incremento 1000000 veces global.\n",pthread_self());

    for(int i=0; i<1000000; i++)
    {
        global=global+1;
    }

    printf("Hebra [%lu] incremento finalizado. Global = %d\n",pthread_self(),global);

    pthread_exit(NULL);
}


int main()
{
    pthread_t hilo1, hilo2;

    if(pthread_create(&hilo1, NULL, (void *) incremento, NULL) != 0)
    {
        printf("Error al crear el hilo, errno value = %d\n",errno);
        perror("Thread cretaion error");
        exit(EXIT_FAILURE);
    }

    if(pthread_create(&hilo2, NULL, (void *) incremento, NULL) != 0)
    {
        printf("Error al crear el hilo, errno value = %d\n",errno);
        perror("Thread cretaion error");
        exit(EXIT_FAILURE);
    }
    

    if((pthread_join(hilo1, NULL)) != 0)
    {
        printf("Error al crear el hilo, errno value = %d\n",errno);
        perror("Thread cretaion error");
        exit(EXIT_FAILURE);
    }

    if((pthread_join(hilo2, NULL)) != 0)
    {
        printf("Error al crear el hilo, errno value = %d\n",errno);
        perror("Thread cretaion error");
        exit(EXIT_FAILURE);
    }

    printf("Proceso principal, valor de global = %d\n",global);

    exit(EXIT_SUCCESS);
}