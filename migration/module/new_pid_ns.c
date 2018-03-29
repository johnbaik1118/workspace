#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int new_pid_ns(void *data)
{
	execlp("bash", NULL, NULL);
	return -1;
}

int main(void)
{
	int status;
	long stack[4096];
	
	if (clone(new_pid_ns, &stack[4095], SIGCHLD | CLONE_NEWNS | CLONE_NEWPID, NULL) == -1) {
		perror("clone");
		return -1;
	}
	wait(&status);
}
