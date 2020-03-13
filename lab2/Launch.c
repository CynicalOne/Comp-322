#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	pid_t child;
	int status;
	char* filelocation;
	
	filelocation = argv[1];
	
	
	// memory allocation
	char **args = (char**) calloc(argc - 1, sizeof(char*));

	for (int i = 0; i < argc - 1; i++ ){
	args[i] = (char*) calloc(50, sizeof(char));
	}
	

	if(argc > 2){
		// copies all the commandline args
		for(int i = 1; i < argc; i++){	
			strcpy(args[i - 1], argv[i]);
		}
	}
	
	
	child = fork();	//forks child process
	
	if(child > 0) {	//parent process
		fprintf(stderr, "CPID: %d\n", child);	//parent process prints PID of child to stderr
		waitpid(child, &status, 0);
		fprintf(stderr, "RETVAL: %d\n", status);	//prints retval of child to stderr
		
		
		for (int i = 0; i < argc - 2; i++ ){//frees the array
			free(args[i]);
		}
		free(args);
	}
	else if(child == 0) {	//child process
		if(argc < 2) {
			printf("Error, No filename inputted.\n");
		}
		else{
			execve(filelocation, args, NULL);
		}
	}
	else{
		printf("Error, child not created.");
	}
	
	return 0;
}