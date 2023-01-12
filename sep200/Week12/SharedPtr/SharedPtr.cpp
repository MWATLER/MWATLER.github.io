//SharedPtr.cpp - sample code to demonstrate a shared pointer

#include <iostream>
#include <memory>//std::shared_ptr
#include "Title.h"

void display(const char* s) {
    std::shared_ptr<Title> t1(new Title(s));
    t1->display();
    std::shared_ptr<Title> t2(t1);//copy constructor of the shared_ptr
    t2->display();
    std::cout << std::hex;
    std::cout << "&t1=" << (int*)&t1 << " &t2=" << (int*)&t2 << std::endl;
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