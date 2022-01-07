CC=g++
CFLAGS=-I../kernel#Use headers from the kernel
CFLAGS+=-Wall
FILES1=userWriter.cpp

userWriter: $(FILES1)
	$(CC) $(CFLAGS) $(FILES1) -o userWriter

clean:
	rm -f *.o userWriter

all: userWriter

