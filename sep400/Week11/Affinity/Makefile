CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES=nestedLoop.cpp

nLoop: $(FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f *.o nLoop

all: nLoop
