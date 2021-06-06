CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES1=race1.cpp
FILES2=race2.cpp
FILES3=fcntl.cpp

race1: $(FILES1)
	$(CC) $(CFLAGS) -o race1 $(FILES1)

race2: $(FILES2)
	$(CC) $(CFLAGS) -o race2 $(FILES2)

fcntl: $(FILES3)
	$(CC) $(CFLAGS) -o fcntl $(FILES3)

clean:
	rm -f *.o race1 race2 fcntl

all: race1 race2 fcntl
