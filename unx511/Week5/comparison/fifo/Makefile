CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES1=fifo1.cpp
FILES2=fifo2.cpp

fifo1: $(FILES1)
	$(CC) $(CFLAGS) $^ -o $@

fifo2: $(FILES2)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o fifo1 fifo2

all: fifo1 fifo2
