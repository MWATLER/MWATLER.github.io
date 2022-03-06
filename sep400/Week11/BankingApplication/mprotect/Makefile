CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES=BankApplication.cpp

bank: $(FILES)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o bank

all: bank
