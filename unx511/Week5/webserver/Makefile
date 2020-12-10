CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES1=client.cpp
FILES2=server.cpp

client: $(FILES1)
	$(CC) $(CFLAGS) $(FILES1) -o $@

server: $(FILES2)
	$(CC) $(CFLAGS) $(FILES2) -o $@

clean:
	rm -f *.o client server

all: client server
