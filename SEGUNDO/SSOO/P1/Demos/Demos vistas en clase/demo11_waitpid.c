#include <stdio.h>
#include <unistd.h> // fork, pid_t, getpid
#include <errno.h> // errno
#include <string.h> // strerror
#include <stdlib.h> // EXIT_SUCCESS
#include <sys/wait.h> // wait

void interpretar_wait(pid_t hijo_esperado, int status);

int main () {
    pid_t pid;

    printf("Soy el proceso padre con PID %d\n", getpid());
    pid = fork();

    if (pid == -1) {
        printf("Error al hacer fork: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    else if (pid == 0) {
        printf("Soy el proceso hijo con PID %d y mi padre %d\n", getpid(), getppid());
        sleep(5);
        printf("Hijo terminado\n");
        return EXIT_SUCCESS;
    }
    else {
        printf("Proceso padre: generado hijo con PID %d\n", pid);
    }

    pid_t hijo_esperado;
    int status;
    
    // Comprobaré periódicamente si el hijo ha terminado
    // pero mientras realizaré otro trabajo
    while ((hijo_esperado = waitpid((pid_t) -1, &status, WNOHANG)) == 0) {
        printf("Padre: Hijo no terminado, continúo trabajando\n");
        sleep(1); // <-- "simulación" de trabajo
    }

    if (hijo_esperado == -1) {
        printf("Error al sincronizar proceso: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    
    interpretar_wait(hijo_esperado, status);
    printf("Hijo esperado\n");

    return EXIT_SUCCESS;
}

void interpretar_wait(pid_t hijo_esperado, int status) {
    if (WIFEXITED(status)) {
            int codigo_salida_hijo = WEXITSTATUS(status);
            printf("El hijo con PID %d ha terminado normalmente con código %d\n",
                   hijo_esperado, codigo_salida_hijo);
    }

    if (WIFSIGNALED(status)) {
        int senal_terminacion = WTERMSIG(status);
        printf("El hijo con PID %d ha terminado debido a la senal %s",
                hijo_esperado, strsignal(senal_terminacion));
    }

    // Esto no ocurrirá nunca.
    // Para captar procesos que han sido detenidos, es necesario
    // usar waitpid (en lugar de wait) con ciertos parámetros.
    if (WIFSTOPPED(status)) {
        int senal_terminacion = WSTOPSIG(status);
        printf("El hijo con PID %d fue detenido debido a la senal %s",
                hijo_esperado, strsignal(senal_terminacion));
    }
}
