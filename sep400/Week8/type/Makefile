CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES3=client3.cpp
FILES4=client4.cpp
LIBS=-lpthread

client3: $(FILES3)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

client4: $(FILES4)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f *.o client3 client4

all: client3 client4
