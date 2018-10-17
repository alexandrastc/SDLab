CC=gcc
CFLAGS= -c -std=c99 -Wall

all: cyphers

cyphers: main.o
	$(CC) -o cyphers main.o

main.o: main.c
	$(CC) $(CFLAGS) main.c

clean:
	rm -rf *.o