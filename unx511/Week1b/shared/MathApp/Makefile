CC=g++
CFLAGS=-I../MathRepository
CFLAGS+=-Wall
FILES=MathTest.cpp
LIBS = -L/usr/local/lib -lMath
#-L/usr/local/lib -llibMath.so

MathTest: $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o MathTest $(LIBS)
#g++ -I../MathRepository -Wall MathTest.cpp -o MathTest -L/usr/local/lib -lMath

clean:
	rm -f *.o MathTest

all: MathTest
