CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES=Mount.cpp
FILES2=UMount.cpp
FILES3=MultipleMount.cpp
FILES4=MultipleUMount.cpp

mount: $(FILES)
	$(CC) $(CFLAGS) $^ -o $@

umount: $(FILES2)
	$(CC) $(CFLAGS) $^ -o $@

mmount: $(FILES3)
	$(CC) $(CFLAGS) $^ -o $@

mumount: $(FILES4)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o mount umount mmount mumount

all: mount umount mmount mumount
