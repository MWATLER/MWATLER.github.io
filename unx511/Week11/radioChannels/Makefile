CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES1=client.cpp
FILES2=memoryManager.cpp
LIBS=-lpthread

client: $(FILES1)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

memoryManager: $(FILES2)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f *.o client memoryManager

all: client memoryManager
