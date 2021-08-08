CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES1=dataAcquisition.cpp
LIBS=-lpthread

dataAcquisition: $(FILES1)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f *.o dataAcquisition

all: dataAcquisition
