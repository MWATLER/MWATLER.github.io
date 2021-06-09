CC=g++
CFLAGS=-I
CFLAGS+=-Wall
CFLAGS+=-DDEBUG
FILES=deadlock.cpp
LIBS=-lpthread

deadlock: $(FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f *.o deadlock

all: deadlock
