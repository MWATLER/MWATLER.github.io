// SmartPtr.cpp - Smart Pointer for title

#include <iostream>
#include "Title.h"
#include "SmartPtr.h"

void display(const char* s) {
	SmartPtr<Title> t(new Title(s));//The SmartPtr is removed once the function is out of scope

//	int i;//i is removed once the function is out of scope
    //In the below scenario, if an exception is thrown, 
    // display() does not have the ability to delete t.
//  Title* t = new Title(s);
    t->display();
//  delete t;//if an exception is thrown, we do not get to this line!!
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