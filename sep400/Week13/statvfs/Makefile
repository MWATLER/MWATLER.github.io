CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES3=MountStatvfs.cpp
FILES4=MultipleUMount.cpp

mountStat: $(FILES3)
	$(CC) $(CFLAGS) $^ -o $@

mumount: $(FILES4)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o mountStat mumount

all: mountStat mumount
