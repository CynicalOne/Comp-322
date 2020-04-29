#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
	char *ptr;
	unsigned long address;
	unsigned long pageNumber;
	unsigned long offset;
	char hex[4];
	char pnumHex[2];
	char offsetHex[4];
	
	
	//error checking
	if((argc > 2 || argc == 1) && strlen(argv[1]) != 5){
		printf("Missing or invalid memory address provided.");
		exit(EXIT_SUCCESS);
	}
	
	//converts string to unsigned long
	address = strtoul(argv[1], &ptr, 10);
	
	//turning the address into string hex
	unsigned long tempAddress = address;
	int i = 3;
	while(tempAddress != 0){
		int temp = 0;
		temp = tempAddress % 16;
		if(temp < 10){
			hex[i] = temp + 48;
			i--;
		}
		else{
			hex[i] = temp + 55;
			i--;
		}
		tempAddress = tempAddress/16;
	}
	
	//splitting the hex between the page number and the offset
	strncpy(pnumHex, hex, 1);
	strncpy(offsetHex, hex + 1, 3);
	
	//converting string hex to respective unsigned long
	pageNumber = strtoul(pnumHex, &ptr, 16);
	offset = strtoul(offsetHex, &ptr, 16);
	
	printf("the address %ld contains: \npage number = %ld \noffset = %ld\n", address, pageNumber, offset);
}

