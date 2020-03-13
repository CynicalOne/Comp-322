#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	pid_t child1;
	pid_t child2;
	int fd[2];
	
	pipe(fd);
	
	child1 = fork();	//parent creates first child
	
	
	if(child1 > 0) {	//parent process
		child2 = fork();	//parent creates second child
		
		if(child2 > 0) {	//parent process
			fprintf(stderr,"CPID1: %d\nCPID2:  %d\n", child1, child2);	//prints PID of both children on stderr
			close(fd);	//closes access to pipe
		}
		else if(child2 == 0) {	//child 2 process
			dup2(
		}
		else {
			printf("Error, second child not created."
		}
	}
	else if(child1 == 0) {	//child 1 process
	
	}
	else {
		printf("Error, first child not created.");
	}
	
	return 0;
}
	