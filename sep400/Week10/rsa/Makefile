CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES=rsa.cpp
FILES2=rsa2.cpp

rsa: $(FILES)
	$(CC) $(CFLAGS) $^ -o $@

rsa2: $(FILES2)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o rsa rsa2

all: rsa rsa2
