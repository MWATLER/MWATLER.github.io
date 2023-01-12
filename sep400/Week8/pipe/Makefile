CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES1=pipe.cpp
FILES2=pipe2.cpp
FILES3=pipe3.cpp
FILES4=pipeout.cpp

pipe: $(FILES1)
	$(CC) $(CFLAGS) $^ -o $@

pipe2: $(FILES2)
	$(CC) $(CFLAGS) $^ -o $@

pipe3: $(FILES3)
	$(CC) $(CFLAGS) $^ -o $@

pipeout: $(FILES4)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o pipe pipe2 pipe3 pipeout

all: pipe pipe2 pipe3 pipeout
