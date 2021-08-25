#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <time.h>

void * vector (void * nada)
{}

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("ERROR. Debe ser: %s 2 o 5.\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    int n;
    n = atoi(argv[1]);

    if(n == 2 || n == 5){}
    else 
    {
        printf("ERROR. Solo se admite el numero 2 o el 5.\n");
        exit(EXIT_FAILURE);
    }

    srand48(time(NULL));

    float vec[10];

    for(int i=0; i<10; i++)
    {
        vec[i]=drand48()*9+1;

        printf("[%0.2f] ",vec[i]);
        if(i == 9){printf("\n");}
    }


    /*pthread_t hilos[n];

    for(int i=0; i<n; i++)
    {
        if((pthread_create(&hilos[i], NULL, (void *) vector, NULL)) != 0)
        {
            printf("Error al crear la hebra, errno value = %d\n",errno);
            perror("THread create error");
            exit(EXIT_FAILURE);
        }
    }
*/

}