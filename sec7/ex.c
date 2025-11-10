#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

int main() {

    int pfd[2];
    pipe(pfd);

    pid_t pid = fork();

    if (pid == 0) {
	close(pfd[0]);
	pid_t my_pid = getpid();

	int b = write(pfd[1], &my_pid, sizeof(pid_t));
	printf("[child] Child %d wrote %d bytes\n", my_pid, b);
	exit(0);
	
    } else {
	pid_t pid_received;
	int b_recvd = read(pfd[0], &pid_received, sizeof(pid_t));
	printf("[parent] Read %d bytes:  %d\n", b_recvd, pid_received);

	int status;
	waitpid(pid, &status, 0);
	printf("[parent] Child exited with status %d\n", WEXITSTATUS(status));
    }
    

    return 0;
}
