CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES1=Lab1.cpp
FILES2=MemMonitor.cpp

Lab1: $(FILES1)
	$(CC) $(CFLAGS) $(FILES1) -o Lab1

MemMonitor: $(FILES2)
	$(CC) $(CFLAGS) $(FILES2) -o MemMonitor

clean:
	rm -f *.o Lab1 MemMonitor

all: Lab1 MemMonitor
