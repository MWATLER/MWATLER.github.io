// SmartPtr.cpp - Smart Pointer for title

#include <iostream>
#include "Title.h"
#include "SmartPtr.h"

void display(const char* s) {
//  Title* t = new Title(s);
    SmartPtr<Title> t(new Title(s));//The SmartPtr is removed once the function is out of scope

    t->display();
//  delete t;
}

int main() {
    const int SIZE = 4;
    const char* s[SIZE] = { "Mr.", "Ms.", "", "Dr." };

    for (int i = 0; i < SIZE; ++i) {
        display(s[i]);
    }
}