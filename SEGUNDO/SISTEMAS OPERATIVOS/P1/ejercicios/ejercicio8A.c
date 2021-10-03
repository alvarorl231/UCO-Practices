#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>


void tratarSennal()
{
    printf("Sennal recibida! Mi PID es %d\n",getpid());
}


int main()
{

    printf("Soy el proceso %d.\n",getpid());

    if(signal(SIGUSR1, tratarSennal) == SIG_ERR)
    {
        printf("Error al capturar la señal, errrno value = %d.\n",errno);
        perror("Signal error");
        exit(EXIT_FAILURE);
    } 

    while (1)
    {
        pause();  
    }

    exit(EXIT_SUCCESS);    
}