CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES1=drawRect.cpp
LIBS=-lSDL2 -lpthread#-lSDL2 expands to libSDL2.a or libSDL2.so

drawRect: $(FILES1)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f *.o drawRect

all: drawRect
