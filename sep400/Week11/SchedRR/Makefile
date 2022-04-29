CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES=nestedLoop.cpp
FILES2=nestedLoop2.cpp

nLoop: $(FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

nLoop2: $(FILES2)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f *.o nLoop nLoop2

all: nLoop nLoop2
