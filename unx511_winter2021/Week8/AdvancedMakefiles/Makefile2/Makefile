CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES=hellomake.c
FILES+=hellofunc.c
OBJ=hellomake.o
OBJ+=hellofunc.o

hellomake: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o hellomake

clean:
	rm -f *.o hellomake

all: hellomake
