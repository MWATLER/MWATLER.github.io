CC=gcc
CFLAGS=-I
CFLAGS+=-Wall
FILES1=chat-client.c
FILES2=chat-server.c

chat-client: $(FILES1)
	$(CC) $(CFLAGS) $^ -o $@

chat-server: $(FILES2)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o chat-client chat-server

all: chat-client chat-server
