CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES1=ErrorMsg.cpp
FILES2=MiniMath.cpp

ErrorMsg: $(FILES1)
	$(CC) $(CFLAGS) $(FILES1) -o ErrorMsg

MiniMath: $(FILES2)
	$(CC) -D_EXTENDED_MATH $(CFLAGS) $(FILES2) -o MiniMath
#$(CC) $(CFLAGS) $(FILES2) -o MiniMath

clean:
	rm -f *.o ErrorMsg MiniMath

all: ErrorMsg MiniMath
