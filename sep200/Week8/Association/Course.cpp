//Course.cpp - function definitions for course

#include <iostream>
#include "Course.h"
#include "Room.h"

Course::Course(const char* n, int c) {
    name = n;//overloaded operator=
    code = c;
}

void Course::book(Room& r) {
    if (room) room->release();//Say I booked room A1001, but now I want to book B1001
	                          //room A1001 will be released - its course pointer will be set to nullptr
    room = &r;
}

void Course::release() {
    room = nullptr;
}

const char* Course::get() const {
    return name.get();
}

void Course::display() const {
    std::cout << (room ? room->get() : "*****") << ' ' << code << ' ' << name.get() << std::endl;
}