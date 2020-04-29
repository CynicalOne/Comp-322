#include <stdio.h>
#include <stdlib.h>


void eat(int)
void think(int)
void sighandler(int signum);

int main(int argc, char *argv[])
{
	int count = 0;
	int seat = argv[2];
	
	do{
		wait(chopstick[i]);
		wait(chopstick[(i+1)%5])
		
		eat(seat);
		
		signal(chopstick[i]);
		signal(chopstick[(i+1)%5]);
		signal(SIGTERM, sighandler);
		
		think(seat);
		count ++;
	}while(true);
	
}
	
	
void eat(int philNum)
{
	printf("Philosopher %d is eating", philNum);
	usleep(rand() % 1000000);	//usleep can't use anything over 1000000
}

void think(int philNum)
{
	int random = rand() % 1000000;
	printf("Philosopher %d is thinking", philNum);
	usleep(rand() % 1000000);
}

void sighandler(int signum) {
	
	sem_close(chopstick1);
	sem_close(chopstick2);
	sem_unlink(chopstick1);
	sem_unlink(chopstick2);
	
	printf("");
}