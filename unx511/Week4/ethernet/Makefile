CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES=etherCtrl.cpp
FILES2=etherCtrl2.cpp

etherCtrl: $(FILES)
	$(CC) $(CFLAGS) -o etherCtrl $(FILES)

etherCtrl2: $(FILES2)
	$(CC) $(CFLAGS) -o etherCtrl2 $(FILES2)

clean:
	rm -f *.o etherCtrl etherCtrl2

all: etherCtrl etherCtrl2
