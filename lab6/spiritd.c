#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <fcntl.h>
#include <string.h>

void sighandler(int signum);

pid_t mole;
char* moleDir;

int main()
{
	struct rlimit lim;
	pid_t child;
	
	//saves the absolute directory of moles
	char buffer[1024];
	moleDir = getcwd(buffer, 1024);
	strcat(moleDir, "/moles");
	
	//file creation mask to 0
	umask(0);
	
	child = fork();
	
	if(child > 0){	//parent process exits
		exit(EXIT_SUCCESS);
	}
	
	//create a new session
	setsid();

	//changes working directory to be "/"
	if(chdir("/") < 0) {
		exit(EXIT_FAILURE);
	}	
	
	//close all open file descriptors
	getrlimit(RLIMIT_NOFILE, &lim);
	if(lim.rlim_max == RLIM_INFINITY){
		lim.rlim_max = 1024;
	}
	for(unsigned int i = 0; i < lim.rlim_max; i++){
		close(i);
	}
	
	//reopen file descriptors to map to /dev/null
	open("/dev/null", O_RDWR);
	dup(0);
	dup(0);
	
	//handles the signals stated in the project specs
	signal(SIGTERM, sighandler);
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	
	
	while(1){
		pause();
	}
}



void sighandler(int signum)
{
	//kills child process
	if(mole != 0){
		kill(mole, SIGKILL);
	}
	
	if(signum == SIGTERM){
		exit(EXIT_SUCCESS);
	}
	if(signum == SIGUSR1 || signum == SIGUSR2){
		pid_t child1;
		child1 = fork();
		
		if(child1 == 0){	//child process
			char *moleNumber;
			int random = rand() % 2;
			if(random == 1){
				moleNumber = "mole1";
			}
			else{
				moleNumber = "mole2";
			}
			
			char *args[4];
			args[0] = moleDir;
			args[1] = moleNumber;
			args[2] = moleDir2;
			args[3] = NULL;
			execve(args[0], args, NULL);
			
		}
		else{
			mole = child1;
		}
	}
}
	