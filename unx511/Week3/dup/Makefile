CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES1=exercise.cpp
FILES2=fileDup.cpp

exercise: $(FILES1)
	$(CC) $(CFLAGS) -o exercise $(FILES1)

fileDup: $(FILES2)
	$(CC) $(CFLAGS) -o fileDup $(FILES2)

clean:
	rm -f *.o exercise fileDup

all: exercise fileDup
