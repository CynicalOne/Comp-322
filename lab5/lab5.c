#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
	char *ptr;
	unsigned long address;
	unsigned long pageNumber;
	unsigned long offset;
	
	
	//error checking
	if(argc > 2 || argc == 1){
		printf("Missing or invalid memory address provided.");
		exit(EXIT_SUCCESS);
	}
	
	//converts string to unsigned long
	address = strtoul(argv[1], &ptr, 10);
	
	
	pageNumber = address / 4096;
	offset = address % 4096;
	printf("the address %ld contains: \npage number = %ld \noffset = %ld\n", address, pageNumber, offset);
}

