//Room.h - class declaration for a room

#ifndef _ROOM_H_
#define _ROOM_H_

#include "Name.h"
class Course;

class Room {
    Name name;
    Course* course{ nullptr };
public:
    Room(const char*);
    void book(Course&);
    void release();
    const char* get() const;
    void display() const;
    //...
};

#endif// _ROOM_H_
