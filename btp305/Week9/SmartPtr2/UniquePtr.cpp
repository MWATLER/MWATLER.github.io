// UniquePtr.cpp - Unique Ownership

#include <iostream>
#include <memory>
#include "Title.h"
/*
void display(const char* s)
{
    Title* t = new Title(s);
    t->display(); // may throw an exception!
    delete t;
}
*/
void display(const char* s) {
    std::unique_ptr<Title> t(new Title(s));
    t->display();
}

int main() {
    const char* s[] = { "Mr.", "Ms.", "", "Dr." };

    for (auto x : s) {
        try {
            display(x);
        }
        catch (const char* msg) {
            std::cerr << msg << std::endl;
        }
    }
}