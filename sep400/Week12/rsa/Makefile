CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES=rsa.cpp

rsa: $(FILES)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o rsa

all: rsa
