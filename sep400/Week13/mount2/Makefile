CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES3=BindMount.cpp
FILES4=MultipleUMount.cpp

bmount: $(FILES3)
	$(CC) $(CFLAGS) $^ -o $@

mumount: $(FILES4)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o bmount mumount

all: bmount mumount
