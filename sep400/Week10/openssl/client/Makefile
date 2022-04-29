CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES=client.cpp
LIBS=-lssl
LIBS+=-lcrypto
LIBDIR=-L/usr/lib

client: $(FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS) $(LIBDIR)

clean:
	rm -f *.o client

all: client
