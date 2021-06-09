IDIR=../include
ODIR=../obj
CC=g++
CFLAGS=-I$(IDIR)
CFLAGS+=-Wall
FILES=hellomake.c
FILES+=hellofunc.c

# $(patsubst PATTERN,REPLACEMENT,TEXT)
#
# Finds whitespace-separated words in TEXT that match PATTERN and replaces them with REPLACEMENT.
# Here PATTERN may contain a % which acts as a wildcard, matching any number of any characters within a word.
# ...
# Whitespace between words is folded into single space characters; leading and trailing whitespace is discarded.
#
_OBJ=hellomake.o
_OBJ+=hellofunc.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))
# $OBJ now becomes ../obj/hellomake.o ../obj/hellofunc.o

_DEPS=hellomake.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))
# $DEPS now becomes ../include/hellomake.h

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

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean#The .PHONY rule keeps make from doing something with a file named clean.
	     #A phony target is one that is not really the name of a file; rather it
	     #is just a name for a recipe to be executed when you make an explicit
	     #request. This is to avoid a conflict with a file of the same name.

clean:
	rm -f $(ODIR)/*.o hellomake

all: hellomake
	@echo "object files were "$(_OBJ)" but now they became "$(OBJ)
	@echo "deps were "$(_DEPS)" but now deps became "$(DEPS)
