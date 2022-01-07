CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES1=fork1.cpp
FILES2=fork2.cpp

fork1: $(FILES1)
	$(CC) $(CFLAGS) -o fork1 $(FILES1)

fork2: $(FILES2)
	$(CC) $(CFLAGS) -o fork2 $(FILES2)

clean:
	rm -f *.o fork1 fork2

all: fork1 fork2
