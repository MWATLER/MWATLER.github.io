CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES=server.cpp
FILES1+=client1.cpp

server: $(FILES)
	$(CC) $(CFLAGS) -o server $(FILES)

client1: $(FILES1)
	$(CC) $(CFLAGS) -o client1 $(FILES1)

clean:
	rm -f *.o server client1

all: server client1
