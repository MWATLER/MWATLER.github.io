CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES1=openTest.cpp
FILES2=fopenTest.cpp

OpenTest: .
	$(CC) $(CFLAGS) $(FILES1) -o openTest

FOpenTest: .
	$(CC) $(CFLAGS) $(FILES2) -o fopenTest

clean:
	rm -f *.o openTest fopenTest

all: OpenTest FOpenTest
