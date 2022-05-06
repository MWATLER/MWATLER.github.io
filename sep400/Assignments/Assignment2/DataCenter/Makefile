CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES1=DataCenter.cpp
FILES1+=DataCenterMain.cpp
FILES2=DataCenterRogue1.cpp
FILES2+=DataCenterRogue1Main.cpp
FILES3=DataCenterRogue2.cpp
FILES3+=DataCenterRogue2Main.cpp
LIBS=-lpthread

dataCenter: $(FILES1)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

dataRogue1: $(FILES2)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

dataRogue2: $(FILES3)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f *.o dataCenter dataRogue1 dataRogue2

all: dataCenter dataRogue1 dataRogue2
