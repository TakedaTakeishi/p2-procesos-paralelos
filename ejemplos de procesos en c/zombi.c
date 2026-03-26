#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        /* Proceso padre: NO llama a wait() */
        printf("Padre [PID %d]: Durmiendo 30 seg...\n", getpid());
        printf("Padre: El hijo se convertira en zombi.\n");
        sleep(30); /* El hijo sera zombi durante este tiempo */
    } else if (pid == 0) {
        /* Proceso hijo: termina inmediatamente */
        printf("Hijo [PID %d]: Terminando.\n", getpid());
        exit(EXIT_SUCCESS);
    } else {
        perror("Error en fork");
        exit(EXIT_FAILURE);
    }
    return 0;
}
