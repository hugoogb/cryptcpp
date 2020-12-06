SHELL=/bin/bash
CC=g++
CFLAGS=-Wall

main: main.o functions.o menu.o struct.o
	$(CC) $(CFLAGS) main.o functions.o menu.o struct.o -o main

main.o: main.cpp functions.h menu.h struct.h
	$(CC) $(CFLAGS) -c main.cpp -o main.o

functions.o: functions.cpp functions.h
	$(CC) $(CFLAGS) -c functions.cpp -o functions.o

menu.o: menu.cpp menu.h
	$(CC) $(CFLAGS) -c menu.cpp -o menu.o

struct.o: struct.cpp struct.h
	$(CC) $(CFLAGS) -c struct.cpp -o struct.o

clean:
	rm -f main *.o
