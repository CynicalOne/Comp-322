#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

int main(int argc, char *argv[]) {
    
    int fd;
	int decequiv;
	int c;
	int counter;
    char *filename;
	char *str1;
	str1 = (char*)malloc(100);
	char *str;
	str = (char*)malloc(9);
	char *token;
	char ascii[4] = "0";
	char parity[5];
	char *unprintables[] = {
    "NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL",
    " BS", " HT", " LF", " VT", " FF", " CR", " SO", " SI",
    "DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB",
    "CAN", " EM", "SUB", "ESC", " FS", " GS", " RS", " US",
    "DEL"};
    
    //if no file in the command, open stdin
	if(argc < 2 || argv[1] == "-.txt") {
		printf("Enter binary value: ");
		gets(str1);	//takes string from stdin into str1
		printf("Original\tASCII\t\tDecimal\t\tParity\n");
		printf("--------\t--------\t--------\t--------\n");
		
		token = strtok(str1, " ");		//tokenizes str1
		
		
		while(token != NULL) {
			while(strlen(token) > 0) {
				if(strlen(token) > 8){
					strncpy(str, token, 8);
				}
				else{
					strncpy(str, token, strlen(token));
				}
				
				if(strlen(str) < 8) {	//end case where token not divisible by 8
					for(int i = 0; i < (8 - strlen(token)); i++){
						strcat(str,"0");
					}
				}
				*(str +8) = 0;	//null pointer
				
				//calculations
				for(c = 0, decequiv = 0, counter = 0; c < strlen(str); c++){	//calculates binary to decimal
					if (str[strlen(str) - (c + 1)] == 49) {	//check in reverse
						decequiv += 1*(pow(2,c));
						counter++;
					}
				}
				
				if(decequiv > 128){	//sets ascii and decimal to nonextended
					decequiv = decequiv - 128;
				}
				
				if (decequiv == 127) {
					strncpy(ascii, unprintables[32], 4);
				}
				else if(decequiv < 32) {
					strncpy(ascii, unprintables[decequiv], 4);
				}
				else{
					ascii[0] = decequiv;
				}
				
				if(counter % 2 == 0) {	//sets parity 
					strncpy(parity, "EVEN", 5);
				}
				else{
					strncpy(parity, "ODD", 4);
				}
				
				
				
				printf("%s\t%s\t\t%d\t\t%s\n", str,ascii,decequiv,parity);
				
				
				if(strlen(token) > 8){		//iterates through current token 
					token = token + 8;
				}
				else {
					token = token + strlen(token);
					}
				memset(str, 0, 8*sizeof(str[0]));
			}
			
			
			token = strtok(NULL, " ");	//iterate the token
		}
	}
	else{	//file as an argument
		filename = argv[1];
		fd = open(filename, O_RDONLY);

		if(fd > 0){
			read(fd, str1, 100);
			token = strtok(str1, " ");
			
			printf("Original\tASCII\t\tDecimal\t\tParity\n");
			printf("--------\t--------\t--------\t--------\n");
			while(token != NULL) {
				while(strlen(token) > 0) {
					if(strlen(token) > 8){
						strncpy(str, token, 8);
					}
					else{
						strncpy(str, token, strlen(token));
					}
					
					if(strlen(str) < 8) {	//end case where token not divisible by 8
						for(int i = 0; i < (8 - strlen(token)); i++){
							strcat(str,"0");
						}
					}
					*(str +8) = 0;	//null pointer
					
					//calculations
					for(c = 0, decequiv = 0, counter = 0; c < strlen(str); c++){	//calculates binary to decimal
						if (str[strlen(str) - (c + 1)] == 49) {	//check in reverse
							decequiv += 1*(pow(2,c));
							counter++;
						}
					}
					
					if(decequiv > 128){	//sets ascii and decimal to nonextended
						decequiv = decequiv - 128;
					}
					
					if (decequiv == 127) {
						strncpy(ascii, unprintables[32], 4);
					}
					else if(decequiv < 32) {
						strncpy(ascii, unprintables[decequiv], 4);
					}
					else{
						ascii[0] = decequiv;
					}
					
					if(counter % 2 == 0) {	//sets parity 
						strncpy(parity, "EVEN", 5);
					}
					else{
						strncpy(parity, "ODD", 4);
					}
					
					
					
					printf("%s\t%s\t\t%d\t\t%s\n", str,ascii,decequiv,parity);
					
					
					if(strlen(token) > 8){		//iterates through current token 
						token = token + 8;
					}
					else {
						token = token + strlen(token);
						}
					memset(str, 0, 8*sizeof(str[0]));
				}
				
				
				token = strtok(NULL, " ");	//iterate the token
			}
		}
	}
			

	free(str1);
	free(str);
	return 0;
}