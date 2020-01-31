#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    
    int fd;
    char *filename;
    char ch;
	char str[8];
	int amtread;
    
    //if no file in the command, open stdin
    if(argc < 2) {
        printf("Enter binary value");
        gets(str);
    }
    //file is specified as an argument
    else {
        filename = argv[1];
        fd = open(filename, O_RDONLY);        //read only mode
		
        if (fd > 0) {
			while(amtread = read(fd, &str, 8)) {
				if (amtread != 8) {
					printf("%d\n", strlen(str));
					for(int i = 0; i < (8 - amtread); i++){	//appends 0 in case of incomplete binary
						strcat(str,"0");
					}
					str[8] = 0;
				}
				
				//run calculations
				printf("%s\n", str);
				memset(str, 0, 8*sizeof(str[0]));
			}	
        }
    }
    
    //use values in str to make calculations
  
    //print calculated values
    
	close(fd);
    return 0;
}   