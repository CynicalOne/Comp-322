#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(argc < 2){
		exit(EXIT_FAILURE);
	}
	FILE *matrix = fopen("matrix.txt", "w+");
	int size = atoi(argv[1]);
	int value;
	if(matrix != 0){
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				//generate value between -100 and 100
				value = (rand() % 200) - 100;
				fprintf(matrix, "%d ", value);
			}
			fprintf(matrix,"\n");
		}
	}
	else{
		printf("file cannot be created");
	return 0;
}