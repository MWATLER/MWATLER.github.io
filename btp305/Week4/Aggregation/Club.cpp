//Club.cpp - function definitions for club

#include <iostream>
#include <cstring>
#include "Club.h"
#include "Name.h"

Club& Club::operator+=(const Name& n) {
    if (num < M) {
        name[num++] = &n;
    }
    return *this;
}

Club& Club::operator-=(const Name& t) {//t->get() equals "Peter"
    bool found = false;
    int i;
    for (i = 0; i < num && !found; i++) {
        if (std::strcmp( name[i]->get(), t.get() )==0) {//name[3] has name "Peter", and t has name "Peter"
            found = true;
        }
    }
    if (found) {//i=4
        for (; i < num; i++)
            name[i - 1] = name[i];//shift the name over so "Peter" is removed from the array of pointers
        if (num) {
            name[num - 1] = nullptr;
            num--;
        }
    }
    return *this;
}

void Club::display() const {
    for (int i = 0; i < num; i++) {
        std::cout << name[i]->get() << std::endl;
    }
}