# Name: Neal Layumas
# Project: Lab 6

CC=gcc
CFLAGS=-g -Wall -Wextra

all: spiritd moles

spiritd: spiritd.c
	$(CC) $(CFLAGS) -c spiritd.c
	$(CC) $(CFLAGS) -o spiritd spiritd.o -lm
	
moles: mole.c
	$(CC) $(CFLAGS) -c mole.c
	$(CC) $(CFLAGS) -o moles mole.o -lm
	
clean:
	rm -f spiritd moles spiritd.o mole.o *~