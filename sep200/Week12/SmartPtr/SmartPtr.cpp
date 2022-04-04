// SmartPtr.cpp - Smart Pointer for title

#include <iostream>
#include "Title.h"
#include "SmartPtr.h"

void display(const char* s) {
    SmartPtr<Title> t(new Title(s));
    //In the below scenario, if an exception is thrown, 
    // display() does not have the ability to delete t.
//  Title* t = new Title(s);
    t->display();
//  delete t;
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