SHELL=/bin/bash
CC=g++
CFLAGS=-Wall

main: main.o functions.o
	$(CC) $(CFLAGS) main.o functions.o -o main

main.o: main.cpp functions.h
	$(CC) $(CFLAGS) -c main.cpp -o main.o

functions.o: functions.cpp functions.h
	$(CC) $(CFLAGS) -c functions.cpp -o functions.o

clean:
	rm -f main *.o
