CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES=hellomake.c
FILES+=hellofunc.c

hellomake: $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o hellomake

clean:
	rm -f *.o hellomake

all: hellomake
