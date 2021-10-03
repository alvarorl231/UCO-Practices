#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void signal_handler(int code) {
    printf("%s recibido\n", strsignal(code));
}

int main() {
    signal(SIGALRM, signal_handler);

    printf("Esperando señal de alarma. Mi PID es %d\n", getpid());

	alarm(5);
	
	sleep(10);
    
    printf("Sleep terminado\n");

    return EXIT_SUCCESS;
}
