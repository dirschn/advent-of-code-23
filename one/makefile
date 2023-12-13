CC = g++
CFLAGS = -g -Wall

TARGET = one

main: main.o
	$(CC) $(CFLAGS) -o one main.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm *.o one
