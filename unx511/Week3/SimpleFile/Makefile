CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES1=SimpleFile.cpp
FILES2=SeekFile.cpp

SimpleFile: .
	$(CC) $(CFLAGS) $(FILES1) -o SimpleFile

SeekFile: .
	$(CC) $(CFLAGS) $(FILES2) -o SeekFile

clean:
	rm -f *.o MathCopy.cpp SimpleFile SeekFile

all: SimpleFile SeekFile
