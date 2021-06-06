CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES1=client.cpp
FILES2=server.cpp
LIBS=-lpthread

client: $(FILES1)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

server: $(FILES2)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f *.o client server

all: client server
