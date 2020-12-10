CC=g++
CFLAGS=-I../kernel
CFLAGS+=-Wall
FILES1=user_file.cpp

user_file: $(FILES1)
	$(CC) $(CFLAGS) $(FILES1) -o user_file

clean:
	rm -f *.o user_file

all: user_file
