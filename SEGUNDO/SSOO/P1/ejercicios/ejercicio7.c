#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void tratarSennal(int n)
{
    printf("[%d] Hola que tal soy SIGUSR1, %s\n",getpid(),strsignal(n));
    return;
}


int main()
{
    pid_t pid, hijopid;
    int status;
    int cont = 0;

    pid=fork();

    switch (pid)
    {
    case -1:
        printf("Error en el fork, errno value = %d\n",errno);
        perror("Fork error");
        exit(EXIT_FAILURE);
    break;
    
    case 0: // HIJO
        printf("Soy el HIJO %d, con Padre %d.\n",getpid(),getppid());

        if(signal(SIGUSR1,tratarSennal) == SIG_ERR) // CONTROL DE ERRORES + RECEPTOR DE SEÑAL
        {
            printf("Error al recoger la señal, errno value = %d\n", errno);
            perror("Signal error");
            exit(EXIT_FAILURE);
        }

        while(1) // BUCLE INFINITO EN EL QUE ESPERA POR CADA SEÑAL
        { 
            if(cont ==  5)
            {
                exit(EXIT_SUCCESS);
            }
            pause(); 
            cont++;
        }

    break;

    default: // PADRE
        printf("Soy el PADRE %d\n",getpid());

            for(int i=0; i<5; i++) // ENVÍA 5 SEÑALES DEL TIPO SIGURS1
            {
                sleep(1);
                kill(pid,SIGUSR1);
            }            
        

        hijopid = wait(&status);

        if(WIFEXITED(status))
        {
            printf("Hijo %d recogido, status = %d\n",pid, WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status))
        {
            printf("Hijo %d matado por la señal %d\n",pid,WTERMSIG(status));
        }
    break;
    }

    exit(EXIT_SUCCESS);
}