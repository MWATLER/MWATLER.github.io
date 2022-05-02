CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES=WorkPackage.cpp

work: $(FILES)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o work

all: work
