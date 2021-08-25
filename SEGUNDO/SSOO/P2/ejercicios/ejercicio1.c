#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

void * aleatorios(void * nada)
{
    printf("Soy la hebra [%lu] y voy a crear 2 num. aleatorios.\n",pthread_self());

    float rand1 = drand48()*100;
    float rand2 = drand48()*100;

    printf("Primer numero aleatorio = %0.2f\n",rand1);
    printf("Segundo numero aleatorio = %0.2f\n",rand2);

    float *suma = malloc(sizeof(float));

    *suma = rand1+rand2;

    printf("%0.2f + %0.2f = %0.2f\n",rand1,rand2,*suma);

    pthread_exit((void *) suma);
}


int main(int argc, char **argv)
{

    srand48(time(NULL));

    if(argc != 2)
    {
        printf("Error. Debe ser: %s nºhilos\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);

    pthread_t hilos[n];

    for(int i=0; i<n; i++)
    {
        if(pthread_create( &hilos[i], NULL, (void*) aleatorios, NULL) != 0)
        {
            printf("Error al crear el hilo, errno value = %d\n",errno);
            perror("Thread error");
            exit(EXIT_FAILURE);
        }
        
        usleep(75); //Para una salida por pantalla limpia, ya que al ser
        // procesos tan rápidos, se solapan al imprimir por pantalla.
        // NO es necesario, funciona igualmente.
        // usleep = sleep, pero en microsegundos.
    }

    float * subtotal;
    float total = 0;

    for(int i=0; i<n; i++)
    {
        if(pthread_join(hilos[i], (void **)&subtotal) != 0)
        {
            printf("Error al crear el hilo, errno value = %d\n",errno);
            perror("Thread error");
            exit(EXIT_FAILURE);
        }
        printf("Valor recibido %0.2f\n",*subtotal);
        total += *subtotal;
    }

    printf("La suma total es: %0.2f\n",total);

    exit(EXIT_SUCCESS);
}