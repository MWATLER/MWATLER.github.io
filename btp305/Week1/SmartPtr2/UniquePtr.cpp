// UniquePtr.cpp - Unique Ownership

#include <iostream>
#include <memory>//std::unique_ptr
#include "Title.h"

void display(const char* s) {
    std::unique_ptr<Title> t(new Title(s));
    t->display();
}

int main() {
    const int SIZE = 4;
    const char* s[SIZE] = { "Mr.", "Ms.", "", "Dr." };

    for (int i = 0; i < SIZE; ++i) {
        display(s[i]);
    }
}