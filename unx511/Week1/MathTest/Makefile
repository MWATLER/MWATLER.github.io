CC=g++#compiler
CFLAGS=-I/home/miguelwatler/src/Week1/Maths#path to the header files
CFLAGS+=-Wall
FILES=MathTest.cpp#source code
LIBS = -L/home/miguelwatler/src/Week1/Maths -lMath#path to the library and the library itself
#-lMath is shorthand notation that actually expands to libMath.a

MathTest: $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o MathTest $(LIBS)

clean:
	rm -f *.o MathTest

all: MathTest
