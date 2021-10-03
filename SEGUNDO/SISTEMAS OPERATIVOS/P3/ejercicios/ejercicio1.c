#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <time.h>

int *buffer;

pthread_mutex_t semClient;
pthread_mutex_t semProv;


void rellenaBuffer (int n)
{
    buffer = (int *)malloc(n*sizeof(int)); //IMPORTANTE
    if(buffer == NULL)
    {
        printf("ERROR. Problemas en la reserva de la memoria del buffer. errno value = %d\n",errno);
        perror("malloc error");
        exit(EXIT_FAILURE);
    }

    for(int i=0; i<n; i++)
    {
        buffer[i]=rand()%99+1;
    }
}

void imprimeBuffer (int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ",buffer[i]);
    }
    printf("\n");
}


void * clientes (void * arg)
{
    int buffsize = atoi((char *) arg);

    int modelo = rand()%(buffsize-1)+1;

    int compra = rand()%9+1;

    if((pthread_mutex_lock(&semClient)) != 0)
    {
        printf("ERROR al bloquear el semaforo. Errno value = %d\n",errno);
        perror("Mutex lock error");
    }

    if(buffer[modelo-1] <= 0) // SI [X] <= 0 , NO PUEDES COMPRAR POR QUE NO QUEDAN MODELOS
    {
        printf("\t<-- Cliente %lu, NO se puede comprar ninguna unidad de la camiseta %d.\n",pthread_self(),modelo);
    }
    else if((buffer[modelo-1]-compra) < 0) // SI LA COMPRA SUPERA EL STOCK LOS MODELOS, SOLO PODRÁS COMPRAR HASTA LLEGAR A 0
    {
        int cont=0;
        for(int i=0; i<100; i++)
        {
            if(buffer[modelo-1] == 0)
            {
                printf("\t<-- Cliente %lu, solo puedo comprar %d unidades de la camiseta %d.\n",pthread_self(),cont,modelo);
                break;
            }
            buffer[modelo-1]=buffer[modelo-1]-1;
            cont++;
        }
    }
    else
    {
        for(int i=0; i<compra; i++)
        {
            buffer[modelo-1]=buffer[modelo-1]-1;
        }
        printf("<-- Cliente %lu, compro %d unidades de la camiseta %d.\n",pthread_self(),compra,modelo);
    }

    if((pthread_mutex_unlock(&semClient)) != 0)
    {
        printf("ERROR al desbloquear el semaforo. Errno value = %d\n",errno);
        perror("Mutex unlock error");
    }

    pthread_exit(NULL);
}

void * proveedores (void * arg)
{
    int buffsize = atoi((char *) arg);

    int modelo = rand()%(buffsize-1)+1;

    int reposicion = rand()%9+1;

    if((pthread_mutex_lock(&semProv)) != 0)
    {
        printf("ERROR al bloquear el semaforo. Errno value = %d\n",errno);
        perror("Mutex lock error");
    }

    if(buffer[modelo-1] == 100) // SI [X] == 100 , NO PUEDES SUMINISTRAR MAS MODELOS
    {
        printf("\t--> Proveedor %lu, NO se pueden suministrar mas unidades de la camiseta %d.\n",pthread_self(),modelo);
    }
    else if((buffer[modelo-1]+reposicion) > 100) // SI LA REPOSICION SUPERA EL STOCK LOS MODELOS, SOLO PODRÁS SUMINISTRAR HASTA LLEGAR A 100
    {
        int cont=0;
        for(int i=0; i<100; i++)
        {
            if(buffer[modelo-1] == 100)
            {
                printf("\t--> Proveedor %lu, solo puedo suministrar %d unidades de la camiseta %d.\n",pthread_self(),cont,modelo);
                break;
            }
            buffer[modelo-1]=buffer[modelo-1]+1;
            cont++;
        }
    }
    else
    {
        for(int i=0; i<reposicion; i++)
        {
            buffer[modelo-1]=buffer[modelo-1]+1;
        }
        printf("--> Proveedor %lu, suministro %d unidades de la camiseta %d.\n",pthread_self(),reposicion,modelo);
    }

    if((pthread_mutex_unlock(&semProv)) != 0)
    {
        printf("ERROR al desbloquear el semaforo. Errno value = %d\n",errno);
        perror("Mutex unlock error");
    }

    pthread_exit(NULL);

}



int main(int argc, char **argv)
{
    if(argc != 3)
    {
        printf("ERROR. Deber ser: %s nºclientes nºproveedores\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    int nClient = atoi(argv[1]);
    int nProv = atoi(argv[2]);

    pthread_t hiloClient[nClient];
    pthread_t hiloProv[nProv];

    if(pthread_mutex_init(&semClient,NULL) != 0)
    {
        printf("ERROR al crear el semaforo. Errno value = %d\n",errno);
        perror("Mutex create error");
        exit(EXIT_FAILURE);
    }

    if(pthread_mutex_init(&semProv,NULL) != 0)
    {
        printf("ERROR al crear el semaforo. Errno value = %d\n",errno);
        perror("Mutex create error");
        exit(EXIT_FAILURE);
    }

    rellenaBuffer(nProv);

    printf("Stock de %d tipos de camisetas antes de abrir la tienda:\n",nProv);
    imprimeBuffer(nProv);
    printf("\n");

    for(int i=0; i<nClient; i++)
    {
        if((pthread_create(&hiloClient[i],NULL,(void *)clientes, argv[2])) != 0)
        {
            printf("ERROR al crear las hebras. Errno value = %d\n",errno);
            perror("Pthread create error");
            exit(EXIT_FAILURE);
        }
    }

    for(int i=0; i<nProv; i++)
    {
        if((pthread_create(&hiloProv[i],NULL, (void *) proveedores, argv[2])) != 0)
        {
            printf("ERROR al crear las hebras. Errno value = %d\n",errno);
            perror("Pthread create error");
            exit(EXIT_FAILURE);
        }
    }

    printf("MAIN - Esperado a las hebras cientes y proveedores creadas...\n");

    for(int i=0; i<nClient; i++)
    {
        if((pthread_join(hiloClient[i],NULL)) != 0)
        {
            printf("ERROR al joinear las hebras. Errno value = %d\n",errno);
            perror("Pthread join error");
            exit(EXIT_FAILURE);
        }
    }

    for(int i=0; i<nProv; i++)
    {
        if((pthread_join(hiloProv[i],NULL)) != 0)
        {
            printf("ERROR al joinear las hebras. Errno value = %d\n",errno);
            perror("Pthread join error");
            exit(EXIT_FAILURE);
        }
    }

    printf("\nStock de %d tipos de camisetas al cerrar la tienda:\n",nProv);
    imprimeBuffer(nProv);


exit(EXIT_SUCCESS);
}