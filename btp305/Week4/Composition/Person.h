//Person.h - class declaration for a person

#ifndef _PERSON_H_
#define _PERSON_H_

#include "Name.h"
class Person {
    Name* name = nullptr; //Composition. class Person is responsible for creating and destroying name
    int age;//this is also composition
public:
    Person(const char*, int);
    Person(const Person&);
    Person& operator=(const Person&);
    ~Person();
    void display() const;
    void set(const char*);
    //...
};

#endif// _PERSON_H_
