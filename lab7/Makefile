# Name: Neal Layumas
# Project: Lab 6

CC=gcc
CFLAGS=-g -Wall -Wextra

all: matrix_gen matrix_add

matrix_gen: matrix_gen.c
	$(CC) $(CFLAGS) -c matrix_gen.c
	$(CC) $(CFLAGS) -o matrix_gen matrix_gen.o -lm
	
matrix_add: matrix_add.c
	$(CC) $(CFLAGS) -c matrix_add.c
	$(CC) $(CFLAGS) -o matrix_add matrix_add.o -lm
	
clean:
	rm -f matrix_gen matrix_add matrix_gen.o matrix_add.o *~