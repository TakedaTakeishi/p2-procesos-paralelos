#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Error en fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        /* El hijo reemplaza su imagen con ls */
        printf("Hijo [PID %d]: Ejecutando ls...\n", getpid());
        execlp("ls", "ls", "-l", "/tmp", NULL);
        /* Si execlp retorna, hubo un error */
        perror("Error en exec");
        exit(EXIT_FAILURE);
    } else {
        /* El padre espera y analiza el estado */
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
            printf("Padre: Hijo termino con codigo %d\n",
                   WEXITSTATUS(status));
    }
    return 0;
}
