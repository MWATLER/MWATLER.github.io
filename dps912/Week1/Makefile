CC=g++#specifies the compiler
CFLAGS=-I#the include path
CFLAGS+=-Wall#enable all warnings
FILES=Math.cpp#source code
FILES+=Conversions.cpp#source code
FILES+=General.cpp#source code
FILES+=Geometry.cpp#source code

#Math: clean: and all: are "rules"
Math: $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o Math

clean:
	rm -f *.o Math

all: Math
