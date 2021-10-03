#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
    int status;

    pid_t pid, hijopid;

    pid= fork();

    switch (pid)
    {
    case -1:
        printf("Error en el fork\n");
        perror("fork error");
        exit(EXIT_FAILURE);

        break;

    case 0:
        printf("Soy el HIJO: %d\n", getpid());
        exit(EXIT_SUCCESS);

        break;

    default:
        printf("Soy el PADRE: %d\n", getpid());

        sleep(10);

        exit(EXIT_SUCCESS);

        break;
    }
}