CC=g++#compiler
CFLAGS=-I../MathRepository#path to the header files
CFLAGS+=-Wall
FILES=MathTest.cpp#source code
LIBS = -L../MathRepository -lMath#path to the library and the library itself
#-lMath is shorthand notation that actually expands to libMath.a

MathTest: $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o MathTest $(LIBS)
#g++ -I../MathRepository -Wall MathTest.cpp -o MathTest -L../MathRepository -lMath
#                                                                             libMath.a

clean:
	rm -f *.o MathTest

all: MathTest
