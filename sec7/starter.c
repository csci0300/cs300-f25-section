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
	// As child process, how to send x via the pipe?
	int x[2] = {42, 125};

	exit(0);
    } else { // parent

	int status;
	waitpid(pid, &status, 0);
	printf("[parent] Child exited with status %d\n", WEXITSTATUS(status));
    }


    return 0;
}
