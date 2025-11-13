#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

int main() {
    int pfd[2];
    pipe(pfd); // create pipe

    pid_t pid = fork();

    if (pid == 0) { // Child
	close(pfd[0]);
	// As child process, how to send x via the pipe?
	int x[2] = {42, 125};

	int b = write(pfd[1], &x, sizeof(int));
	b = write(pfd[1], &x[1], sizeof(int));
	printf("[child] Wrote %d bytes\n", b);

	exit(0);
    } else { // parent
	close(pfd[1]);
	int y[2];

	// Blocks until some data is available
	int b_recvd = read(pfd[0], y, 2*sizeof(int));
	printf("[parent] read %d bytes:  [%d, %d]\n", b_recvd, y[0], y[1]);

	int status;
	waitpid(pid, &status, 0);
	printf("[parent] Child exited with status %d\n", WEXITSTATUS(status));
    }


    return 0;
}
