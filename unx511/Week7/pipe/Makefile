CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES1=pipe.cpp
FILES2=pipe2.cpp
FILES3=pipeline.c
FILES4=pipeline2.c
FILES5=pipeout.cpp

pipe: $(FILES1)
	$(CC) $(CFLAGS) $^ -o $@

pipe2: $(FILES2)
	$(CC) $(CFLAGS) $^ -o $@

pipeline: $(FILES3)
	$(CC) $(CFLAGS) $^ -o $@

pipeline2: $(FILES4)
	$(CC) $(CFLAGS) $^ -o $@

pipeout: $(FILES5)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o pipe pipe2 pipeline pipeline2 pipeout

all: pipe pipe2 pipeline pipeline2 pipeout
