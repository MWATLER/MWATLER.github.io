CC=g++
CFLAGS=-I
CFLAGS+=-Wall
LIBS=-lpthread
FILES=counter.cpp

counter: $(FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f *.o counter

all: counter
