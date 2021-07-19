CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES1=client2.cpp
FILES2=server2.cpp

client1: $(FILES1)
	$(CC) $(CFLAGS) $^ -o $@

client2: $(FILES1)
	$(CC) $(CFLAGS) $^ -o $@

client3: $(FILES1)
	$(CC) $(CFLAGS) $^ -o $@

server: $(FILES2)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o client1 client2 client3 server

all: client1 client2 client3 server
