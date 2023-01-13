// UniquePtr.cpp - Unique Ownership

#include <iostream>
#include <memory>//std::unique_ptr
#include "Title.h"

void display(const char* s) {
    std::cout << "Entering display()" << std::endl;
    std::unique_ptr<Title> t(new Title(s));
    if (!t->display()) return;
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