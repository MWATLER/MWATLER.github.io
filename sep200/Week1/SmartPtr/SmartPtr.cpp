// SmartPtr.cpp - Smart Pointer for title

#include <iostream>
#include "Title.h"
#include "SmartPtr.h"

void display(const char* s) {
    std::cout << "Entering display()" << std::endl;
//  Title* t = new Title(s);
    SmartPtr<Title> t(new Title(s));//The SmartPtr is removed once the function is out of scope

    if (!t->display()) 
        return;
//  delete t;
    std::cout << "Leaving display()" << std::endl;
}

int main() {
    const int SIZE = 4;
    const char* s[SIZE] = { "Mr.", "Ms.", "", "Dr." };

    for (int i = 0; i < SIZE; ++i) {
        display(s[i]);
        std::cout << std::endl;
    }
}