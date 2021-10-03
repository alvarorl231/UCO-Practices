#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("./ejecutable numero numero\n");
        exit(EXIT_FAILURE);
    }

    int status;

    pid_t pid,hijopid;

    for(int i=0;i<2;i++)
    {
        pid=fork();

        switch (pid)
        {
        case -1:
            printf("Error en el fork.\n");
            perror("fork error");
            exit(EXIT_FAILURE);
            break;

        case 0:
            if (i==0)
            {
                printf("Soy el HIJO %d con Padre %d y voy a calcular el factorial de %d\n",getpid(),getppid(),atoi(argv[1]));
                execlp("./factorial","./factorial",argv[1],NULL);
                exit(EXIT_SUCCESS);
            }
            else
            {
                printf("Soy el HIJO %d con Padre %d y voy a calcular el factorial de %d\n",getpid(),getppid(),atoi(argv[2]));
                execlp("./factorial","./factorial",argv[2],NULL);
                exit(EXIT_SUCCESS);
            }
            break;         
        
        default:
            printf("Soy el PADRE %d\n",getpid());

            hijopid=wait(&status);

            if(WIFEXITED(status))
            {
                printf("Hijo %d recogido, status = %d\n",pid,WEXITSTATUS(status));
            }
            else if (WIFSIGNALED(status))
            {
                printf("Hijo %d matado, signal = %d\n",pid,WTERMSIG(status));
            }
            break;
        }
    }
    exit(EXIT_SUCCESS);
}