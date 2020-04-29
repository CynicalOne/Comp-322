# Name: Neal Layumas
# Project: Lab 3

CC=gcc
CFLAGS=-g -Wall -Wextra

all: lab5

catcher: lab5.c
	$(CC) $(CFLAGS) -c lab5.c
	$(CC) $(CFLAGS) -o catcher lab5.o -lm
	
clean:
	rm -f lab5 lab5.o *~