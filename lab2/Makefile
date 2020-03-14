# Name: Neal Layumas
# Project: Lab 2

CC=gcc
CFLAGS=-g -Wall -Wextra

all: launch tube

launch: launch.c
	$(CC) $(CFLAGS) -c launch.c
	$(CC) $(CFLAGS) -o launch launch.o -lm
	
tube: tube.c
	$(CC) $(CFLAGS) -c tube.c
	$(CC) $(CFLAGS) -o tube tube.o -lm
	
clean:
	rm -f launch tube launch.o tube.o *~