CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES=hellomake.c
FILES+=hellofunc.c
OBJ=hellomake.o
OBJ+=hellofunc.o
DEPS=hellomake.h

# $@ is the name of the file being generated, and $< the first prerequisite (usually the source file).
# For example, consider the following declaration:
# 
# all: library.cpp main.cpp
#
# In this case:
#     $@ evaluates to all
#     $< evaluates to library.cpp
#     $^ evaluates to library.cpp main.cpp
#

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o hellomake

all: hellomake
