CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES=server.cpp
FILES1+=client1.cpp
LIBS=-lpthread

server: $(FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

client1: $(FILES1)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f *.o server client1

all: server client1
