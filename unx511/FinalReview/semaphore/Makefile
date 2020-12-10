CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES1=client1.cpp
FILES2=client2.cpp
FILES3=client3.cpp
LIBS=-lpthread

client1: $(FILES1)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

client2: $(FILES2)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

client3: $(FILES3)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f *.o client1 client2 client3

all: client1 client2 client3
