CC=g++
CFLAGS=-I
CFLAGS+=-fPIC
CFLAGS+=-Wall
CFLAGS+=-c
LIBFLAGS=-shared
LIBFLAGS+=-o
FILES=Conversions.cpp
FILES+=General.cpp
FILES+=Geometry.cpp
OBJFILES=Conversions.o
OBJFILES+=General.o
OBJFILES+=Geometry.o

Math: $(FILES)
	$(CC) $(CFLAGS) $(FILES)

lib: $(OBJFILES)
	$(CC) $(LIBFLAGS) libMath.so $(OBJFILES)

install:
	cp libMath.so /home/miguelwatler/src/Week1/Maths/shared
	cp libMath.so /usr/lib
	cp *.h /home/miguelwatler/src/Week1/Maths/shared

clean:
	rm -f *.o *.so

all: Math lib
