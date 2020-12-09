SHELL=/bin/bash

CC=g++
CFLAGS=-Wall

METHODS_PATH=src/methods/
UTIL_PATH=src/util/

main: main.o menu.o struct.o transform.o alphabet.o cipher.o encoding.o
	$(CC) $(CFLAGS) main.o menu.o struct.o transform.o alphabet.o cipher.o encoding.o -o main

main.o: main.cpp $(UTIL_PATH)menu.h $(UTIL_PATH)struct.h $(METHODS_PATH)transform.h $(METHODS_PATH)alphabet.h $(METHODS_PATH)cipher.h $(METHODS_PATH)encoding.h
	$(CC) $(CFLAGS) -I $(METHODS_PATH) $(UTIL_PATH) -c main.cpp -o main.o

transform.o: $(METHODS_PATH)transform.cpp $(METHODS_PATH)transform.h
	$(CC) $(CFLAGS) -I $(METHODS_PATH) -c $(METHODS_PATH)transform.cpp -o transform.o

alphabet.o: $(METHODS_PATH)alphabet.cpp $(METHODS_PATH)alphabet.h
	$(CC) $(CFLAGS) -I $(METHODS_PATH) -c $(METHODS_PATH)alphabet.cpp -o alphabet.o

cipher.o: $(METHODS_PATH)cipher.cpp $(METHODS_PATH)cipher.h
	$(CC) $(CFLAGS) -I $(METHODS_PATH) -c $(METHODS_PATH)cipher.cpp -o cipher.o

encoding.o: $(METHODS_PATH)encoding.cpp $(METHODS_PATH)encoding.h
	$(CC) $(CFLAGS) -I $(METHODS_PATH) -c $(METHODS_PATH)encoding.cpp -o encoding.o

menu.o: $(UTIL_PATH)menu.cpp $(UTIL_PATH)menu.h
	$(CC) $(CFLAGS) -I $(UTIL_PATH) -c $(UTIL_PATH)menu.cpp -o menu.o

struct.o: $(UTIL_PATH)struct.cpp $(UTIL_PATH)struct.h
	$(CC) $(CFLAGS) -I $(UTIL_PATH) -c $(UTIL_PATH)struct.cpp -o struct.o

clean:
	rm -f main *.o
