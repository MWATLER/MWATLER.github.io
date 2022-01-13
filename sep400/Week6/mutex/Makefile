CC=g++
CFLAGS=-I
CFLAGS+=-Wall
CFLAGS+=-DDEBUG
FILES1=counterNoMutex.cpp
FILES2=counterMutex.cpp
LIBS=-lpthread

counterNoMutex: $(FILES1)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

counterMutex: $(FILES2)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f *.o counterNoMutex counterMutex

all: counterNoMutex counterMutex
