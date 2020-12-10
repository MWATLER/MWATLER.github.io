CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES1=pipeline.cpp

pipeline: $(FILES1)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o pipeline

all: pipeline
