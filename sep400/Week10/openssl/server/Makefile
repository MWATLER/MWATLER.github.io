CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES=server.cpp
LIBS=-lssl
LIBS+=-lcrypto
LIBDIR=-L/usr/lib

server: $(FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS) $(LIBDIR)

clean:
	rm -f *.o server

all: server
