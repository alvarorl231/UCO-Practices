#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int par = 0;
int impar = 0;

pthread_mutex_t sem;

void * parImpar (void * arg)
{
    int orden = * (int*)arg;
    int * suma = malloc(sizeof(int));
    int subtot;
    int aux;
    
    for(int i=0; i<5; i++)
    {
        aux=rand()%9+1;
        subtot+=aux;
    }

    *suma = subtot;

    if(pthread_mutex_lock(&sem) != 0)
    {
        printf("ERROR al bloquear el semaforo, errno value = %d\n",errno);
        perror("mutex lock error");
    }

    if((orden % 2) == 0) //Hebras pares
    {
        par=par+(*suma);
    }
    else //Hebras impares
    {
        impar=impar+(*suma);
    }

    if(pthread_mutex_unlock(&sem) != 0)
    {
        printf("ERROR al desbloquear el semaforo, errno value = %d\n",errno);
        perror("mutex unlock error");
    }


    pthread_exit((void *) suma);
}


int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("ERROR. Debe ser: %s NºHilos\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    int nhilos = atoi(argv[1]);
    int * recogida = malloc(sizeof(int));
    int totImp = 0;
    int totPar = 0;

    pthread_t hilos[nhilos];

    if(pthread_mutex_init(&sem,NULL) != 0)
    {
        printf("ERROR al iniciar el semaforo, errno value = %d\n",errno);
        perror("mutex init error");
        exit(EXIT_FAILURE);
    }

    for(int i=0; i<nhilos; i++)
    {   
        int *arg = malloc(sizeof(int));
        /*
        En cada iteración del bucle, está asignando nueva memoria, cada una con una 
        dirección diferente, entonces, lo que se pasa a pthread_create() en cada
        iteración es diferente, por lo que ninguno de sus hilos termina intentando 
        acceder a la misma memoria.
        */
        *arg = (i+1);

        if((pthread_create(&hilos[i],NULL,(void *)parImpar,(void *)arg)) != 0)
        {
            printf("ERROR al crear la hebra. errno value = %d\n",errno);
            perror("pthread_create() error");
            exit(EXIT_FAILURE);
        }
    }

    for(int i=0; i<nhilos; i++)
    {
        if(((i+1) % 2) == 0) //Pares
        {
            if(pthread_join(hilos[i],(void *)&recogida) != 0)
            {
                printf("ERROR al joinear la hebra. errno value = %d\n",errno);
                perror("pthread_join() error");
                exit(EXIT_FAILURE);
            }
            printf("Main()... La hebra de orden de cracion %d devolvio el valor de suma total: %d\n",(i+1),*recogida);
            totPar+=(*recogida);
        }
        else // Impares
        {
            if(pthread_join(hilos[i],(void *)&recogida) != 0)
            {
                printf("ERROR al joinear la hebra. errno value = %d\n",errno);
                perror("pthread_join() error");
                exit(EXIT_FAILURE);
            }
            printf("Main()... La hebra de orden de cracion %d devolvio el valor de suma total: %d\n",(i+1),*recogida);
            totImp+=(*recogida);
        }
    }

    printf("\nMain()... Valor de la variable compartida impar: %d\n",impar);
    printf("Main()... Suma de los valores devueltos por las hebras de creacion impares: %d\n\n",totImp);

    printf("Main()... Valor de la variable compartida par: %d\n",par);
    printf("Main()... Suma de los valores devueltos por las hebras de creacion pares: %d\n",totPar);

exit(EXIT_SUCCESS);
}