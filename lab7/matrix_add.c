#include <stdio.h>


matrix_add(int block, int size, int scalar);

int main(int argc, char *argv[])
{
	time_t start_time = time(NULL);
	int scalar = rand();
	
}

matrix_add(int block[][], int size, int scalar){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			block[i][j] += scalar;
		}
	}
}