CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES3=MountExt4.cpp
FILES4=MultipleUMount.cpp

mount4: $(FILES3)
	$(CC) $(CFLAGS) $^ -o $@

mumount: $(FILES4)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o mount4 mumount

all: mount4 mumount
