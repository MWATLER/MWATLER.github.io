CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES1=fork1.cpp
FILES2=fork2.cpp
FILES3=search.cpp
FILES4=search1.cpp

fork1: $(FILES1)
	$(CC) $(CFLAGS) -o fork1 $(FILES1)

fork2: $(FILES2)
	$(CC) $(CFLAGS) -o fork2 $(FILES2)

search: $(FILES3)
	$(CC) $(CFLAGS) -o search $(FILES3)

search1: $(FILES4)
	$(CC) $(CFLAGS) -o search1 $(FILES4)

clean:
	rm -f *.o fork1 fork2 search search1

all: fork1 fork2 search search1
