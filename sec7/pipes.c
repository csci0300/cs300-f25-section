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
    int write_fd = pfd[1];

    pid_t pid = fork();

    if (pid == 0) { // Child
	int x[2] = {42, 125}; // As child process, how to send x via the pipe?


	// write(fd, void* buf, size)
	sleep(2); // Wait 2s
	int b = write(write_fd, &x, sizeof(int));
	int b = write(write_fd, &x[1], sizeof(int));

	printf("[child] Wrote %d bytes\n", b);
	exit(0);	
    } else { // parent
	int y[2];
	// Blocks until some data is available
	int b_recvd = read(pfd[0], y, 2*sizeof(int));
	printf("[parent] read %d bytes:  %d\n", b_recvd, y);
	    
	int status;
	waitpid(pid, &status, 0);
	printf("[parent] Child exited with status %d\n", WEXITSTATUS(status));
    }
    

    return 0;
}
