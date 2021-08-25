#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void signal_handler(int code) {
    printf("%s recibido\n", strsignal(code));
}

int main(int argc, char **argv) {
    signal(SIGINT, signal_handler);

    printf("Esperando señal. Mi PID es %d\n", getpid());

    while (1) {
    }

    return EXIT_SUCCESS;
}
