CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES1=client.cpp
FILES2=server.cpp

client: .
	$(CC) $(CFLAGS) $(FILES1) -o client

server: .
	$(CC) $(CFLAGS) $(FILES2) -o server

clean:
	rm -f *.o client server

all: client server
