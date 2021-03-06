CC=gcc
CFLAGS= -c -std=c99 -Wall

all: cyphers

cyphers: main.o caesar.o letterFreq.o vigenere.o
	$(CC) main.o caesar.o letterFreq.o vigenere.o -o cyphers 

playfair: playfair.o
	$(CC) playfair.o -o playfair

playfair.o: playfair.c
	$(CC) $(CFLAGS) playfair.c

beaufort: beaufort.o
	$(CC) beaufort.o -o beaufort

beaufort.o: beaufort.c
	$(CC) $(CFLAGS) beaufort.c

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