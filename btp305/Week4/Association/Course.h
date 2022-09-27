//Course.h - class declaration for a course

#ifndef _COURSE_H_
#define _COURSE_H_

#include "Name.h"
class Room;

class Course {
    Name name;//composition
    int code;
    Room* room{ nullptr };//a course is associated with a certain room
public:
    Course(const char*, int);
    void book(Room&);
    void release();
    const char* get() const;
    void display() const;
    //...
};

#endif// _COURSE_H_
