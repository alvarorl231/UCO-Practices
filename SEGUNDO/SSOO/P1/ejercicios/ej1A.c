#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("./ejecutable y num.procesos\n");
        exit(EXIT_FAILURE);
    }

    pid_t pid, hijopid;
    int status;
    int num=atoi(argv[1]);

    for (int i=0; i<num; i++)
    {
        pid=fork();

        switch (pid)
        {
        case -1:
            printf("Error en el fork\n");
            perror("Fork error");
            exit(EXIT_FAILURE);

            break;
        
        case 0:
            printf("Soy el HIJO: %d, mi Padre: %d\n",getpid(),getppid());
            
            break;

        default:
            printf("Soy el PADRE: %d\n", getpid());

            hijopid=wait(&status);

            if(i=(num-1)) //Con esto controlo que recojo a los hijos solo cuando se haya acabado el bucle
            {
                if(WIFEXITED(status))
                {
                    printf("Hijo con PID: %d recogido, status = %d\n",pid,WEXITSTATUS(status));
                }
                else if (WIFSIGNALED(status)) 
                {
                    printf("Hijo con PID: %d matado (signal %d)\n", pid, WTERMSIG(status));
                }
            }
                
            break;
        }
    }

exit(EXIT_SUCCESS);
}