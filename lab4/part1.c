#include <stdio.h>
#include <stdlib.h>


void eat(int philNum)
{
	int random = rand() % 1000000;	//usleep can't use anything over 1000000
	printf("Philosopher %d is eating", philNum);
	usleep(random);
}

void think(int philNum)
{
	int random = rand() % 1000000;
	printf("Philosopher %d is thinking", philNum);
	usleep(random);
}


int main(int argc, char *argv[])
{
	int count = 0;
	int seat = argv[2];
	
	do{
		wait(chopstick[i]);
		wait(chopstick[i + 1])
		
		eat(seat);
		
		signal(chopstick[i]);
		signal(chopstick[i + 1]);
		
		think(seat);
		count ++;
	}while(true);
	
}
	