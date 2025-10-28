CC = g++
CFLAGS = -g -Wall

TARGET = two

main: main.o split.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o split.o

split.o: split.cpp
	$(CC) $(CFLAGS) -c split.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm *.o $(TARGET)
