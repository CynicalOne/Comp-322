#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

static int count = 0;
static int term = 0;

//list of 27 signals used according to slack list
	static char* signals[] = {
	"HUP", "INT", "QUIT", "ILL", "TRAP", "ABRT", "IOT", "BUS", 
	"FPE", "USR1", "SEGV", "USR2", "PIPE", "ALRM", "TERM", "STKFL",
	"CHLD", "CONT", "TSTP", "TTIN", "TTOU", "URG", "XCPU", "XFSZ",
	"VTALRM", "PROF", "WINCH"};
	
	static int sigvalue[] = {
	SIGHUP, SIGINT, SIGQUIT, SIGILL, SIGTRAP, SIGABRT, SIGIOT, SIGBUS, 
	SIGFPE, SIGUSR1, SIGSEGV, SIGUSR2, SIGPIPE, SIGALRM, SIGTERM, SIGSTKFLT, 
	SIGCHLD, SIGCONT, SIGTSTP, SIGTTIN, SIGTTOU, SIGURG, SIGXCPU, SIGXFSZ, 
	SIGVTALRM, SIGPROF, SIGWINCH};

void sighandler(int signum);	

int main(int argc, char *argv[])
{
	//prints PID to stderr
	pid_t processid = getpid();
	fprintf(stderr, "catcher: $$ = %d\n", processid);
	
	//register a handler for each argument
	
	for(int i = 1; i < argc; i++){
		for(int j = 0; j < 27; j++){
			if(strcmp(argv[i], signals[j]) == 0){
				signal(sigvalue[j], sighandler);
			}
		}
	}
	
	
	while(1){
		pause();
	}
}
	
void sighandler(int signum) 
{
	count++;
	
	// increments term if a SIGTERM is found
	if(signum == 15){
		term++;
	}
	else{	//if the next signal is not a SIGTERM, count goes back to 0
		term = 0;
	}
	
	if(signum == 7 || signum == 8){
		printf("SIG%s caught at %ld\n", signals[signum], time(NULL));
	}
	else if(signum < 19){
		printf("SIG%s caught at %ld\n", signals[signum - 1], time(NULL));
	}
	else{
		printf("SIG%s caught at %ld\n", signals[signum - 2], time(NULL));
	}
	
	if(term == 3){
		fprintf(stderr, "catcher: Total signals count = %d\n", count);
		exit(EXIT_SUCCESS);
	}
}