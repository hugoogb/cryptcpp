SHELL=/bin/bash
CC=g++
CFLAGS=-Wall

main: main.o menu.o struct.o transform.o alphabet.o cipher.o encoding.o
	$(CC) $(CFLAGS) main.o menu.o struct.o transform.o alphabet.o cipher.o encoding.o -o main

main.o: main.cpp menu.h struct.h transform.h alphabet.h cipher.h encoding.h
	$(CC) $(CFLAGS) -c main.cpp -o main.o

transform.o: transform.cpp transform.h
	$(CC) $(CFLAGS) -c transform.cpp -o transform.o

alphabet.o: alphabet.cpp alphabet.h
	$(CC) $(CFLAGS) -c alphabet.cpp -o alphabet.o

cipher.o: cipher.cpp cipher.h
	$(CC) $(CFLAGS) -c cipher.cpp -o cipher.o

encoding.o: encoding.cpp encoding.h
	$(CC) $(CFLAGS) -c encoding.cpp -o encoding.o

menu.o: menu.cpp menu.h
	$(CC) $(CFLAGS) -c menu.cpp -o menu.o

struct.o: struct.cpp struct.h
	$(CC) $(CFLAGS) -c struct.cpp -o struct.o

clean:
	rm -f main *.o
