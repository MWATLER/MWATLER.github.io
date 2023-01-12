CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES1=sendsig.cpp
FILES2=recvsig.cpp
FILES3=recvsig2.cpp

sendsig: $(FILES1)
	$(CC) $(CFLAGS) -o sendsig $(FILES1)

recvsig: $(FILES2)
	$(CC) $(CFLAGS) -o recvsig $(FILES2)

recvsig2: $(FILES3)
	$(CC) $(CFLAGS) -o recvsig2 $(FILES3)

clean:
	rm -f *.o sendsig recvsig recvsig2

all: sendsig recvsig recvsig2
