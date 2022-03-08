//AssociationMain.cpp - main program for demonstrating an association

#include "Course.h"
#include "Room.h"

void book(Course& c, Room& r) {
    c.book(r);
    r.book(c);
}

int main() {
    Room t2108("T2108");
    Room t2109("T2109");
    Room t2110("T2110");
    Course btp105("Intro to Programming", 105);
    Course btp205("Intro to O-O Prg", 205);
    Course btp305("O-O Programming", 305);
	//We've created three rooms and three courses
    btp105.display();
    btp205.display();
    btp305.display();
    t2108.display();
    t2109.display();
    t2110.display();
    book(btp205, t2110);
    book(btp305, t2108);
/*	void book(Course & c, Room & r) {
		c.book(r);
		r.book(c);
	}*/
    btp105.display();
    btp205.display();
    btp305.display();
    t2108.display();
    t2109.display();
    t2110.display();
    book(btp205, t2108);
    book(btp305, t2109);
    btp105.display();
    btp205.display();
    btp305.display();
    t2108.display();
    t2109.display();
    t2110.display();
}