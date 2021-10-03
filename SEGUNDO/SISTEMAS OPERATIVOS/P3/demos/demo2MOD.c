#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


typedef enum {FALSE = 0, TRUE = 1} booleano; //Para salir del 2º bucle for del main()
int avail = 0; //Sección crítica
pthread_mutex_t semaforo; //Semaforo



void produccion (void * arg)
{
    int items = atoi((char *) arg); 
    int aux;

    for(int i=0; i<items; i++)
    {
        if((pthread_mutex_lock(&semaforo)) != 0) // Cierra semáforo
        {
            printf("Error al bloquear el semáforo, errno value = %d\n",errno);
            perror("Mutex lock error");
        }

        aux=avail;
        aux++;
        avail=aux;

        printf("Soy [%lu] incremento avail. Avail = %d\n", pthread_self(), avail);

        if((pthread_mutex_unlock(&semaforo)) != 0) // Abre semáforo
        {
            printf("Error al desbloquear el semáforo, errno value = %d\n",errno);
            perror("Mutex unlock error");
        }

        pthread_exit(NULL);
    }
}


int main(int argc, char **argv)
{
    if(argc<3) 
	 {
        printf("Ussage: ./a.out Number_of_increasing_for_thread1 Number_of_increasing_for_thread2 Number_of_increasing_for_threadN\n");
        exit(EXIT_FAILURE); 
    }

    if((pthread_mutex_init(&semaforo, NULL)) != 0)
    {
        printf("Error al inicializar el semáforo, errno value = %d\n",errno);
        perror("Mutex init error");
        exit(EXIT_FAILURE);
    }

    // El numero de hebras a crear sera el numero de argumentos menos uno
    int nhilos = argc-1;

    /* Creación de un Array de hebras. 
    En este caso se usara malloc() para la cantidad de hebras a crear*/ 
    pthread_t *hilos;

    hilos= (pthread_t *) malloc ((nhilos)*sizeof(pthread_t));

    int totProd = 0; // Numero total de unidades que las hebras producen
    int totCons = 0; //Total de unidades que se consumen

    for(int i=0; i<nhilos; i++)
    {
        totProd += atoi(argv[i+1]); //Suma lo que se escribe por linea de argumentos

        /* Se pasa a cada hebra el numero de incrementos asignados a la misma sobre 
        la variable compartida avail OJO!!!!, 
        se esta pasando la dirección de una cadena (aunque sea un numero). 
        Habra que reconvertir en la hebra con la funcion atoi() */

        if((pthread_create(&hilos[i],NULL,(void *)produccion, argv[i+1])) != 0)
        {
            printf("Error al crear la hebra, errno value = %d\n",errno);
            perror("Thread creation error");
            exit(EXIT_FAILURE);
        }
        
    }

    booleano done;
    done = FALSE;

    if(avail >= 0)
    {
        for(;;)
        {
            if((pthread_mutex_lock(&semaforo)) != 0) // Cierra semáforo
            {
                printf("Error al bloquear el semáforo, errno value = %d\n",errno);
                perror("Mutex lock error");
            }

            /*Critical section*/
            while (avail > 0) /* Consume all available units */ 
            {
                /* Do something with produced unit */
                totCons ++;
                avail--;
                printf("Main thread, decreasing avail=%d, numConsumed=%d\n", avail, totCons);
                
                if((totCons >= totProd))
                {
                    done=TRUE; //enumeracion definida en la zona de variables globales
                } 
                else
                {
                    done=FALSE; 
                } 
            }

            if((pthread_mutex_unlock(&semaforo)) != 0) // Abre semáforo
            {
                printf("Error al desbloquear el semáforo, errno value = %d\n",errno);
                perror("Mutex unlock error");
            }

            if (done)
            {
                printf("Main thread. Exiting...The %d items produced have been consumed\n", totCons); 
                break;
            }
            else
            {
                printf("Main thread. Unproductive time..., avail is <= 0\n");
            }
        }
    }

    for(int i=0; i<nhilos; i++)
    {
        if((pthread_join(hilos[i],NULL)) != 0)
        {
            printf("Error al joinear la hebra, errno value = %d\n",errno);
            perror("Thread joining error");
            exit(EXIT_FAILURE);
        }
        
    }

exit(EXIT_SUCCESS);
}