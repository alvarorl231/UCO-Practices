#include <sys/types.h> //Varias estructuras de datos.
#include <sys/wait.h>
#include <unistd.h> //API de POSIX y creación de un proceso.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("./ejecutable y num. procesos\n");
        exit(EXIT_FAILURE);
    }

    int status;

    pid_t pid,hijopid;

    int num=atoi(argv[1]);

    for (int i=0; i<num; i++)
    {
        pid = fork();

        switch (pid)
        {
        case -1:
            printf("Error en el fork\n");
            perror("fork failure");
            exit(EXIT_FAILURE);

            break;
        
        case 0:
            printf("Soy el HIJO: %d, y mi Padre: %d\n",getpid(),getppid());
            exit(EXIT_SUCCESS); // Salgo en cada hijo, así los recojo en cada iteración del bucle.

            break;

        default:

            printf("Soy el PADRE: %d\n",getpid());

            hijopid=wait(&status);

                if(WIFEXITED(status))
                {
                    printf("Hijo con PID: %d recogido, status = %d\n",pid,WEXITSTATUS(status));
                }
                else if (WIFSIGNALED(status)) 
                {
                    printf("Hijo con PID: %d matado (signal %d)\n", pid, WTERMSIG(status));
                }

            break;
        }
    }

exit(EXIT_SUCCESS);
}