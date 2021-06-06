CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES=server.cpp
FILES1+=client1.cpp
LIBS=-lpthread

server: .
	$(CC) $(CFLAGS) -o server $(FILES) $(LIBS)

client1: .
	$(CC) $(CFLAGS) -o client1 $(FILES1) $(LIBS)

clean:
	rm -f *.o server client1

all: server client1
