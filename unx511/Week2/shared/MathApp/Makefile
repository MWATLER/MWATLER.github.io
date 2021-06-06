CC=g++
CFLAGS=-I../MathRepository
CFLAGS+=-Wall
FILES=MathTest.cpp
LIBS = -L/usr/lib -lMath

MathTest: $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o MathTest $(LIBS)

clean:
	rm -f *.o MathTest

all: MathTest
