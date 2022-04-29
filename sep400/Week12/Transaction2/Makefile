CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES=Parent.cpp
FILES2=Child.cpp
LIBS=-lpthread

parent: $(FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

child: $(FILES2)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f *.o parent child

all: parent child
