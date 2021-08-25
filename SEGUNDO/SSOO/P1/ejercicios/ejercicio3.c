#include <sys/wait.h>
#include <sys/types.h>  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if(argc == 1 || argc < 5)
    {
        printf("./ejecutable gnome-calculator gedit fichero1.txt fichero2.txt ficheroN.txt.\n");
        exit(EXIT_FAILURE);
    }

    pid_t pid, hijopid;

    int status;

    for(int i=0;i<2;i++)
    {
        pid=fork();


        switch (pid)
        {
        case -1:
            printf("Erro en el fork\n");
            perror("fork error");
            exit(EXIT_FAILURE);
            break;
            
        case 0:
            if(i==0)
            {
                printf("Soy el HIJO %d con Padre %d y abro la calculadora\n",getpid(),getppid());
                execlp(argv[1], argv[1], NULL); //La p permite buscar la ruta asi que habria que usar los exec con p de path
                //Repetimos el argv ya que uno es la ruta y el otro el ejecutable
                exit(EXIT_SUCCESS);            
            }          
            else
            {
                printf("Soy el HIJO %d con Padre %d y voy a abrir el editor de texto.\n",getpid(),getppid());
                execvp(argv[2],argv+2); //argv+2 es para pasarle los argumentos a gedit
                exit(EXIT_SUCCESS);
            }
            break;

        default:
            printf("Soy el PADRE %d\n",getpid());

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