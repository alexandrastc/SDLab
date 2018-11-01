CC=gcc
CFLAGS= -c -std=c99 -Wall

all: cyphers

cyphers: main.o caesar.o letterFreq.o
	$(CC) main.o caesar.o letterFreq.o -o cyphers 

main.o: main.c
	$(CC) $(CFLAGS) main.c

caesar.o: caesar.c
	$(CC) $(CFLAGS) caesar.c

letterFreq.o: letterFreq.c
	$(CC) $(CFLAGS) letterFreq.c

clean:
	rm -rf *.o