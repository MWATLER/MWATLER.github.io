//Room.h - class declaration for a room

#ifndef _ROOM_H_
#define _ROOM_H_

#include "Name.h"
class Course;

class Room {
    Name name;//composition
    Course* course{ nullptr };//a room is associated with a certain course
public:
    Room(const char*);
    void book(Course&);
    void release();
    const char* get() const;
    void display() const;
    //...
};

#endif// _ROOM_H_
