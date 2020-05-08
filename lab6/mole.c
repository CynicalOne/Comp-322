#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(argc < 2){
		exit(EXIT_FAILURE);
	}
	
	FILE *logfile = fopen(argv[2], "a+");
	fprintf(logfile,"Pop %s\n",argv[1]);
}