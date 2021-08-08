CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES1=client.cpp
FILES2=radioApplication.cpp
LIBS=-lpthread

client: $(FILES1)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

radioApplication: $(FILES2)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f *.o client radioApplication

all: client radioApplication
