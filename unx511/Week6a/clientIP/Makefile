CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES1=clientIP.cpp
LIBS=-lpthread

clientIP: $(FILES1)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clientRogue: $(FILES1)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f *.o clientIP clientRogue

all: clientIP clientRogue
