CC=g++
CFLAGS=-I
CFLAGS+=-Wall
CFLAGS+=-DDEBUG
FILES1=msgClient.cpp
FILES2=msgServer.cpp

msgClient: $(FILES1)
	$(CC) $(CFLAGS) $^ -o $@

msgServer: $(FILES2)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o msgClient msgServer

all: msgClient msgServer
