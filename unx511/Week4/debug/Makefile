CC=g++
CFLAGS=-I
CFLAGS+=-Wall
CFLAGS+=-ggdb
CFLAGS+=-DCRASH
CFLAGS+=-DDEBUG
FILES=Math.cpp
FILES+=Conversions.cpp
FILES+=General.cpp
FILES+=Geometry.cpp

Math: $(FILES)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o Math

all: Math
