#include <stdio.h>
#include <unistd.h> // fork, pid_t, getpid
#include <errno.h> // errno
#include <string.h> // strerror
#include <stdlib.h> // EXIT_SUCCESS
#include <sys/wait.h> // wait
#include <unistd.h> // execlp

int main () {
    pid_t pid;
    pid = fork();

    switch (pid) {
        case -1:
            printf("Error al hacer fork: %s\n", strerror(errno));
            return EXIT_FAILURE;
        case 0:
            printf("Soy el proceso hijo con PID %d\n", getpid());
            printf("Voy a lanzar el programa\n");
            execlp("ls", "ls", "-la", "noexiste", (char *) NULL);
            printf("Error al ejecutar programa: %s\n", strerror(errno));
            return EXIT_FAILURE;
        default:
            printf("Soy el proceso padre con PID %d\n", getpid());
            // sleep(30);
            break;
    }
    
    pid_t hijo_esperado;
    int status;

    hijo_esperado = wait(&status);

    if(hijo_esperado >= 0) {
        printf("El hijo con PID %d ha terminado\n", hijo_esperado);
        if (WIFEXITED(status)) {
            printf("El proceso hijo terminó con código %d\n", WEXITSTATUS(status));
        }
    }
    else {
        printf("Error al sincronizar hijo: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    
    printf("He esperado a mi hijo\n");

    return EXIT_SUCCESS;
}
