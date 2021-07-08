CC=g++
CFLAGS=-I
CFLAGS+=-Wall
CFLAGS+=-c#create object files
FILES+=Conversions.cpp
FILES+=General.cpp
FILES+=Geometry.cpp
OBJFILES+=Conversions.o
OBJFILES+=General.o
OBJFILES+=Geometry.o
AR=ar
ARFLAGS=rcs#c-create archive,
           #r-insert the file members into archive with replacement,
	   #s-write an object file index into the archive or update an existing one

Math: $(FILES)
	$(CC) $(CFLAGS) $(FILES)
#g++ -I -Wall -c Conversions.cpp General.cpp Geometry.cpp

lib: $(OBJFILES)
	$(AR) $(ARFLAGS) libMath.a $(OBJFILES)
#ar rcs libMath.a Conversions.o General.o Geometry.o

install:
	cp libMath.a ../MathRepository
	cp *.h ../MathRepository

clean:
	rm -f *.o *.a

all: Math lib
