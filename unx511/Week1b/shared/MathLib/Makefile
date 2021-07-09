CC=g++
CFLAGS=-I
CFLAGS+=-fPIC#Position Independent Code. This allows the code to be located at any
             #virtual address at run time. This is necessary for shared libraries,
	     #since there is no way of knowing at link time where the shared library
	     #code will be located in memory.
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
LIBDIR=/usr/local/lib

Math: $(FILES)
	$(CC) $(CFLAGS) $(FILES)
#g++ -I -fPIC -Wall -c Conversions.cpp General.cpp Geometry.cpp

lib: $(OBJFILES)
	$(CC) $(LIBFLAGS) libMath.so $(OBJFILES)
#g++ -shared -o libMath.so Conversions.o General.o Geometry.o

install:
	cp -n libMath.so $(LIBDIR)
	cp *.h ../MathRepository

clean:
	rm -f *.o *.so

all: Math lib
