#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int global=0;

int main()
{
    int status;

    pid_t pid,hijopid;

    for(int i=0; i<5; i++)
    {
        pid=fork();

        switch (pid)
        {
        case -1:
            printf("Fork error\n");
            exit(EXIT_SUCCESS);
            break;

        case 0:
            printf("Soy el HIJO %d y mi padre es %d\n",getpid(),getppid());
            global=global+100;
            printf("Aumento la variable global +100, global = %d\n",global);
            exit(EXIT_SUCCESS);

        break;
        
        default:
            printf("Soy el PADRE %d\n",getpid());
            
            hijopid=wait(&status);

            if (WIFEXITED(status))
            {
                printf("HIjo %d recogido, status = %d\n\n",pid, WEXITSTATUS(status));
            }
            else if(WIFSIGNALED(status))
            {
                printf("Hijo %d matado, signal = %d\n\n",pid, WTERMSIG(status));
            }

            if(i==4)
            {
                printf("El valor de la variable global es = %d\n",global);
            }

            break;
        }
    }
    exit(EXIT_SUCCESS);
}