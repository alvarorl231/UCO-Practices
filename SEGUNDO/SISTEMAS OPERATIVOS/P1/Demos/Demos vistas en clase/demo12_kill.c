#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Uso incorrecto del programa.\nUso correcto: %s <pid>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    pid_t pid = (pid_t) atoi(argv[1]);
    
    printf("Enviando señal SIGKILL al proceso %d\n", pid);
    
    if (kill(pid, SIGKILL) == -1) {
        printf("Error al enviar señal: %s\n", strerror(errno));
    }

    return EXIT_SUCCESS;
}
