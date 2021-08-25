#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("./ej8B PID\n");
        exit(EXIT_FAILURE);
    }

    int pid = atoi(argv[1]);
    if(pid <= 0)
    {
        printf("PID invalido %d\n",pid);
        exit(EXIT_FAILURE);
    }

    int status;

    status=kill(pid,SIGUSR1);

    if (!status)//Comprobamos que la señal se haya enviado correctamente
    {
        printf("La señal fue enviada.\n");  
    }
    else
    {
        printf("Error al enviar la señal. Valor de erno: %d, definido como: %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    sleep(1);

    status=kill(pid,SIGKILL);

    if (!status)//Comprobamos que la señal se haya enviado correctamente
    {
        printf("La señal fue enviada.\n");  
    }
    else
    {
        printf("Error al enviar la señal. Valor de erno: %d, definido como: %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }


    exit(EXIT_SUCCESS);
}