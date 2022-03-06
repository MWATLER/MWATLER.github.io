CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES=Transaction.cpp
LIBS=-lpthread

trans: $(FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f *.o trans

all: trans
