#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork(); /* Crear proceso hijo */

    if (pid < 0) {
        perror("Error en fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        /* Bloque del proceso hijo */
        printf("Hijo: Mi PID es %d\n", getpid());
        printf("Hijo: PID de mi padre es %d\n", getppid());
        printf("Hijo: Terminando...\n");
        exit(EXIT_SUCCESS);
    } else {
        /* Bloque del proceso padre */
        printf("Padre: Mi PID es %d\n", getpid());
        printf("Padre: PID de mi hijo es %d\n", pid);
        wait(NULL); /* Esperar a que el hijo termine */
        printf("Padre: Hijo terminado correctamente.\n");
    }
    return 0;
}
