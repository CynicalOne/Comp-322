#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	//storage vars
	pid_t child1;
	pid_t child2;
	int pipefd[2];
	int arg1len = 0;
	int arg2len = 0;
	int status1;
	int status2;
	
	if(pipe(pipefd) == -1){
		perror("pipe error");
		exit(1);
	}
	
	// retrieving the args for the first command
	for(int i = 1; i < argc; i++){
		if((strcmp(argv[i], ",") == 0) || (argv[i] == NULL)){
			break;
		}
		arg1len++;
	}
	// memory allocation for list of args for first command
	char** args1 = (char**) calloc(arg1len, sizeof(char*));
	for(int i = 0; i < arg1len; i++){
		args1[i] = (char*) calloc(50, sizeof(char));
	}
	// copies first set of args into args1
	for(int i = 1; i <= arg1len; i++){
		strcpy(args1[i - 1], argv[i]);
	}
	
	// retrieving args for the second command
	for(int i = arg1len + 2; i < argc; i++){
		if((strcmp(argv[i], ",") == 0) || (argv[i] == NULL)){
			break;
		}
		arg2len++;
	}
	// memory allocation for the list of args for second command
	char** args2 = (char**) calloc(arg2len, sizeof(char*));
	for(int i = 0; i < arg2len; i++){
		args2[i] = (char*) calloc(50, sizeof(char));
	}
	// copies second set of args into args2
	for(int i = arg1len + 2, j = 0; i < argc; i++){
		strcpy(args2[j], argv[i]);
		j++;
	}
	
	
	child1 = fork();
	
	if(child1 == 0 ){	//child1 process
		//take input from stdin (already done)
		//replace stdout with write part of pipe
		dup2(pipefd[1], 1);
		//close fds
		close(pipefd[0]);
		close(pipefd[1]);
		execve(args1[0], args1, NULL);
		perror("bad child1 exec:");
	}
	else if(child1 > 0){	//parent process
		//parent closes access to the pipe
		close(pipefd[0]);
		close(pipefd[1]);
		child2 = fork();
		if(child2 ==0){	//child 2 process
			//replace stdin with read part of pipe
			//output to stdout (already done)
			dup2(pipefd[0], 0);
			close(pipefd[0]);
			close(pipefd[1]);
			execve(args2[0], args2, NULL);
			perror("bad child2 exec:");
		}
		else if(child2 > 0){	//parent process
			waitpid(child1, &status1, 0);	//child1 process prints into the pipe, doesn't matter for race condition
			//order printed correctly to ensure no race condition issues
			fprintf(stderr, "CPID1: %d\n", child1);
			fprintf(stderr, "CPID2: %d\n", child2);
			waitpid(child2, &status2, 0);
			fprintf(stderr,"RETVAL1: %d\n", status1);
			fprintf(stderr, "RETVAL2: %d\n", status2);
		}
		else{
			printf("Error, second child not created");
			exit(1);
		}
	}
	else{
		printf("Error, first child not created");
		exit(1);
	}
	
	return 0;
}