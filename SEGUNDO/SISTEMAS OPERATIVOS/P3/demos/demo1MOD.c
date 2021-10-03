#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>

int global = 0; // variable global

pthread_mutex_t semaforo = PTHREAD_MUTEX_INITIALIZER; // semáforo binario

void * loops (void * nloops)
{
    int * n = (int *) nloops;

    int local;

    if((pthread_mutex_lock(&semaforo)) != 0)
    {
        printf("Error al cerrar el semáforo. Errno value = %d\n",errno);
        perror("Mutex lock error");
    }

    for(int i=0; i<*n; i++)
    {
        printf("Hebra [%lu], incrementando...\n",pthread_self());
        local = global;
        local++;
        global = local;
    }
    
    if((pthread_mutex_unlock(&semaforo)) != 0)
    {
        printf("Error al abrir el semáforo. Errno value = %d\n",errno);
        perror("Mutex unlock error");
    }
    
    pthread_exit(NULL);
}

int main(int argc, char ** argv)
{
    if(argc != 2)
    {
        printf("ERROR. %s numero de loops\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    int nloops = atoi(argv[1]);

    pthread_t hilo[2];

    for(int i=0; i<2; i++)
    {
        if(pthread_create(&hilo[i],NULL,(void *)loops, &nloops) != 0)
        {
            printf("Error al crear las hebras. errno value = %d\n",errno);
            perror("Thread creating error");
            exit(EXIT_FAILURE);
        }
    }

    printf("MAIN Thread, arriving to the join call...\n"); 

    for(int i=0; i<2; i++)
    {
        if(pthread_join(hilo[i],NULL) != 0)
        {
            printf("Error al joinear las hebras. errno value = %d\n",errno);
            perror("Thread joining error");
            exit(EXIT_FAILURE);
        }
    }

    printf("MAIN Thread leaves join calls.\n");

    printf("La variable global =  %d\n",global);

    exit(EXIT_SUCCESS);
}