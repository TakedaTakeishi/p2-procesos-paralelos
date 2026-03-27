#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void manejador_sigchld(int sig) {
    /* Recoger todos los hijos terminados (no bloqueante) */
    while (waitpid(-1, NULL, WNOHANG) > 0);
    printf("Senial SIGCHLD recibida: hijo terminado.\n");
}

int main() {
    /* Registrar el manejador de SIGCHLD */
    signal(SIGCHLD, manejador_sigchld);

    pid_t pid = fork();
    if (pid == 0) {
        printf("Hijo [PID %d]: Trabajando...\n", getpid());
        sleep(2);
        printf("Hijo: Terminando.\n");
        exit(EXIT_SUCCESS);
    }

    printf("Padre [PID %d]: Esperando senal...\n", getpid());
    sleep(5); /* El padre continua sin bloqueo de wait() */
    printf("Padre: Fin del programa.\n");
    return 0;
}
