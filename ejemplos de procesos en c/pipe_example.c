#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fd[2];       /* fd[0]=lectura, fd[1]=escritura */
    char buffer[100];
    pipe(fd);        /* Crear la tuberia */

    pid_t pid = fork();
    if (pid == 0) {
        /* Hijo: lee del pipe */
        close(fd[1]); /* Cerrar extremo de escritura */
        read(fd[0], buffer, sizeof(buffer));
        printf("Hijo recibio: %s\n", buffer);
        close(fd[0]);
        exit(EXIT_SUCCESS);
    } else {
        /* Padre: escribe en el pipe */
        close(fd[0]); /* Cerrar extremo de lectura */
        char *msg = "Hola desde el proceso padre";
        write(fd[1], msg, strlen(msg) + 1);
        printf("Padre envio: %s\n", msg);
        close(fd[1]);
        wait(NULL);
    }
    return 0;
}
