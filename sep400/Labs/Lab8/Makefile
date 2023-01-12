CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES=client1.cpp
FILES2=client2.cpp
LIBS=-lpthread

client1: $(FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

client2: $(FILES2)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f *.o client1 client2

all: client1 client2
