CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES1=client.cpp
FILES2=server.cpp

client1: $(FILES1)
	$(CC) $(CFLAGS) $(FILES1) -o client1

client2: $(FILES1)
	$(CC) $(CFLAGS) $(FILES1) -o client2

client3: $(FILES1)
	$(CC) $(CFLAGS) $(FILES1) -o client3

server: $(FILES2)
	$(CC) $(CFLAGS) $(FILES2) -o server

clean:
	rm -f *.o client1 client2 client3 server

all: client1 client2 client3 server
