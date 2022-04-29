CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES=WeightedListMainTimer.cpp
FILES2=nestedLoop2.cpp

wList: $(FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

nLoop2: $(FILES2)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f *.o wList nLoop2

all: wList nLoop2
