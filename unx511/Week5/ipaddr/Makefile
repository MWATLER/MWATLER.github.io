CC=gcc
CFLAGS=-I
CFLAGS+=-Wall
FILES1=client.c
FILES2=server.c

client: $(FILES1)
	$(CC) $(CFLAGS) $(FILES1) -o $@

server: $(FILES2)
	$(CC) $(CFLAGS) $(FILES2) -o $@

clean:
	rm -f *.o client server

all: client server
