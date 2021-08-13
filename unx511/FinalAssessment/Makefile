CC=g++
CFLAGS=-I
CFLAGS+=-Wall
#Question: If I wanted to enable the DEBUG3 flag in my code, how would I do it?
FILES1=AudioGenerator.cpp
FILES2=Encoder.cpp
FILES3=Decoder.cpp
LIBS=-lpthread

AudioGenerator: $(FILES1)
#Question: What does the following line expand to?
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

Encoder: $(FILES2)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

Decoder: $(FILES3)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f *.o AudioGenerator Encoder Decoder

all: AudioGenerator Encoder Decoder
