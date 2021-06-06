CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES1=pipe.cpp
FILES2=pipe2.cpp
FILES3=pipe3.cpp
FILES4=pipeline.c
FILES5=pipeline2.c
FILES6=pipeout.cpp

pipe: $(FILES1)
	$(CC) $(CFLAGS) $^ -o $@

pipe2: $(FILES2)
	$(CC) $(CFLAGS) $^ -o $@

pipe3: $(FILES3)
	$(CC) $(CFLAGS) $^ -o $@

pipeline: $(FILES4)
	$(CC) $(CFLAGS) $^ -o $@

pipeline2: $(FILES5)
	$(CC) $(CFLAGS) $^ -o $@

pipeout: $(FILES6)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o pipe pipe2 pipe3 pipeline pipeline2 pipeout

all: pipe pipe2 pipe3 pipeline pipeline2 pipeout
