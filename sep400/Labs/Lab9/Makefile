CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES=hack.cpp
FILES2=nestedLoop2.cpp

hack: $(FILES)
	$(CC) $(CFLAGS) $^ -o $@

nLoop2: $(FILES2)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o hack nLoop2

all: hack nLoop2
