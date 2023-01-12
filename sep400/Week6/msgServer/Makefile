CC=g++
CFLAGS=-I
CFLAGS+=-Wall
CFLAGS+=-DDEBUG
FILES1=msgClient.cpp
FILES2=msgServer.cpp
LIBS=-lpthread

msgClient: $(FILES1)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

msgServer: $(FILES2)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f *.o msgClient msgServer

all: msgClient msgServer
