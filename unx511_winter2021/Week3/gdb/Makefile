CC=g++
CFLAGS=-I
CFLAGS+=-Wall
CFLAGS+=-ggdb
CFLAGS+=-DCRASH
FILES=Math.cpp
FILES+=Conversions.cpp
FILES+=General.cpp
FILES+=Geometry.cpp

Math: $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o Math

clean:
	rm -f *.o Math

all: Math
