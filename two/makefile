CC = g++
CFLAGS = -g -Wall

TARGET = one

two: main.o pull.o game.o set.o split.o
	$(CC) $(CFLAGS) -o two main.o pull.o game.o set.o split.o

main.o pull.o game.o set.o split.o: main.cpp pull.cpp game.cpp set.cpp split.cpp
	$(CC) $(CFLAGS) -c main.cpp

pull.o: pull.cpp
	$(CC) $(CFLAGS) -c pull.cpp

game.o: game.cpp
	$(CC) $(CFLAGS) -c game.cpp

set.o: set.cpp
	$(CC) $(CLFAGS) -c set.cpp

split.o: split.cpp
	$(CC) $(CFLAGS) -c split.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm *.o two
