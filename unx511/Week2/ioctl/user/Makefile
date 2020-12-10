CC=gcc
CFLAGS=-I
CFLAGS+=-Wall
FILES1=test_app.c
FILES2=test_file.c

test_app: $(FILES1)
	$(CC) -o test_app $(FILES1)

test_file: $(FILES2)
	$(CC) -o test_file $(FILES2)

clean:
	rm -f *.o test_app test_file

all: test_app test_file
