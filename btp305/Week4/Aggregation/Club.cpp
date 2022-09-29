//Club.cpp - function definitions for club

#include <iostream>
#include <cstring>
#include "Club.h"
#include "Name.h"

//Name jane("Jane");
//Name john("John");
//Name alice("Alice");
//Name frank("Frank");
//Name stanley("Stanley");
//Club gameClub;
//gameClub += jane;//name[0] will point to jane
//gameClub += john;//name[1] will point to john
//gameClub += alice;//name[2] will point to alice
//gameClub += frank;//name[3] will point to frank
Club& Club::operator+=(const Name& n) {
    if (num < M) {
        name[num++] = &n;//name[] is an array of pointers
    }
    return *this;
}
//gameClub += jane;//name[0] will point to jane
//gameClub += john;//name[1] will point to john
//gameClub += alice;//name[2] will point to alice
//gameClub += frank;//name[3] will point to frank
Club& Club::operator-=(const Name& t) {//t->get() equals "Alice"
    bool found = false;
    int i;
    for (i = 0; i < num && !found; i++) {
        if (std::strcmp( name[i]->get(), t.get() )==0) {//name[2] has name "Alice", and t has name "Alice"
            found = true;
        }
    }
    if (found) {//i=3
        for (; i < num; i++)
            //name[2] will point to frank
            name[i - 1] = name[i];//shift the name over so "Alice" is removed from the array of pointers
        if (num) {
            //name[3] will point to nullptr
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