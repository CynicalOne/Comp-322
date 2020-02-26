#include <stdio.h>
#include <time.h>	
#include <sys/types.h>	
#include <unistd.h>
#include <sys/wait.h>	
#include <stdlib.h>
#include <sys/times.h>


int main() {
	time_t* startTime = 0;
	pid_t child;
	int status;
	struct tms timer;
	
	printf("START: %ld\n",time(startTime));
	child = fork();	//starts the fork process

	
	if(child > 0){ //parent process
		waitpid(child, &status, 0);	//waits for child to finish
		
		times(&timer);	//measures elapsed time
		
		printf("PPID: %d, PID: %d, CPID: %d, RETVAL: %d \n", getppid(), getpid(), child, status);
		
		printf("USER: %ld, SYS: %ld\n", timer.tms_utime, timer.tms_stime );
		printf("CUSER: %ld, CSYS: %ld\n", timer.tms_cutime, timer.tms_cstime );
			
		printf("STOP: %ld \n", time(startTime));
	}
	else if(child == 0) {	//child process
		printf("PPID: %d, PID: %d \n", getppid(), getpid());
		_exit(EXIT_SUCCESS);
	}
	else {
		printf("Error, child not created.");
	}
	
	return 0;
}