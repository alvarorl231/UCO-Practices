#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>


void * leeficheros (void * arg)
{

    printf("Soy la hebra [%lu] y voy a abrir el fichero %s\n",pthread_self(), (char *) arg);

    FILE *f;

    if ((f=fopen((char *)arg,"r")) == NULL) 
    {
        printf("Error al abrir el fichero\n");
        perror("File error\n");
        exit(EXIT_FAILURE);
    }

    char linea[256];
    int * cont = malloc(sizeof(int));

    while(fgets(linea,256,f) != NULL) 
    {
       *cont=*cont+1;
    }

	fclose (f);

    pthread_exit((void *) cont);
}

int main(int argc, char **argv)
{
    if(argc <= 1)
    {
        printf("ERROR: Debe ser: %s fichero1.txt ..... fichero[n].txt\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    int n = (argc-1);

    pthread_t hilos[n];

    for(int i=0; i<n; i++)
    {
        if((pthread_create(&hilos[i], NULL, (void *)leeficheros, (void *) argv[(i+1)])) != 0)
        {
            printf("ERROR al crear la hebra. Errno value = %d\n", errno);
            perror("Pthread create error");
            exit(EXIT_FAILURE);
        }
    }

    int * lineas;
    int total = 0;

    for(int i=0; i<n; i++)
    {
        if(pthread_join(hilos[i], (void **) &lineas) != 0)
        {
            printf("ERROR al crear la hebra. Errno value = %d\n", errno);
            perror("Pthread create error");
            exit(EXIT_FAILURE);
        }

        printf("Se han recibido %d lineas leidas.\n", *lineas);
        total += *lineas;
    }

    printf("Las lineas totales leidas son de %d\n",total);

    exit(EXIT_SUCCESS);
}