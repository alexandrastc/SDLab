CC=gcc
CFLAGS= -c -std=c99 -Wall

all: cyphers

cyphers: main.o caesar.o letterFreq.o vigenere.o
	$(CC) main.o caesar.o letterFreq.o vigenere.o -o cyphers 

main.o: main.c
	$(CC) $(CFLAGS) main.c

caesar.o: caesar.c
	$(CC) $(CFLAGS) caesar.c

letterFreq.o: letterFreq.c
	$(CC) $(CFLAGS) letterFreq.c

vigenere.o: vigenere.c
	$(CC) $(CFLAGS) vigenere.c

clean:
	rm -rf *.o