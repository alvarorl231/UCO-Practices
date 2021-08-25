#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int main() {
    //execl("/usr/bin/nano", "nano", "fichero.txt", (char *) NULL);

    char *const args[] = {"nano", "fichero.txt", (char *) NULL};
    execvp("noexiste", args);

    printf("Error al ejecutar programa: %s\n", strerror(errno));
    return EXIT_FAILURE;
}
