CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES=server.cpp
FILES1=client1.cpp
FILES2=client2.cpp
FILES3=client3.cpp
LIBS=-lpthread

server: $(FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

client1: $(FILES1)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

client2: $(FILES2)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

client3: $(FILES3)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f *.o server client1 client2 client3

all: server client1 client2 client3
