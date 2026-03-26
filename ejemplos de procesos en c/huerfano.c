#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        /* Proceso padre: termina inmediatamente */
        printf("Padre [PID %d]: Terminando.\n", getpid());
        exit(EXIT_SUCCESS);
    } else if (pid == 0) {
        /* Proceso hijo: sigue ejecutandose */
        printf("Hijo [PID %d]: PPID = %d\n", getpid(), getppid());
        sleep(5); /* Espera para que el padre termine primero */
        printf("Hijo [PID %d]: PPID = %d (adoptado por init)\n",
               getpid(), getppid());
    } else {
        perror("Error en fork");
        exit(EXIT_FAILURE);
    }
    return 0;
}
