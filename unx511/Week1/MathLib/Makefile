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

lib: $(OBJFILES)
	$(AR) $(ARFLAGS) libMath.a $(OBJFILES)

install:
	cp libMath.a /home/miguelwatler/src/Week1/Maths
	cp *.h /home/miguelwatler/src/Week1/Maths

clean:
	rm -f *.o *.a

all: Math lib
