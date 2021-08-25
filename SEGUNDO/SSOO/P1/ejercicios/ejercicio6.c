#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>


void sig_alarm (int n)
{
    printf("RING\n");
    return;         // no hace nada, solo despierta la pausa
}

void timer (int sec)
{
    alarm(sec);     // empieza el contador
    pause();        // suspende el hilo hasta que la señal es recibida
}

int main()
{
    if(signal(SIGALRM,sig_alarm) == SIG_ERR)
    {
        perror("Signal error");
        printf("errno value = %d\n",errno);
        exit(EXIT_FAILURE);
    }

    timer(5);
    timer(3);

    int i=2;

    while(1) // bucle infinito
    {
        if(i == 4)
        {
            kill(getpid(),SIGKILL);
        }
        timer(1);
        i++;
    }


    exit(EXIT_SUCCESS);
}