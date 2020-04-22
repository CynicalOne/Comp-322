# Name: Neal Layumas
# Project: Lab 3

CC=gcc
CFLAGS=-g -Wall -Wextra

all: catcher

catcher: lab3.c
	$(CC) $(CFLAGS) -c lab3.c
	$(CC) $(CFLAGS) -o catcher lab3.o -lm
	
clean:
	rm -f catcher lab3.o *~