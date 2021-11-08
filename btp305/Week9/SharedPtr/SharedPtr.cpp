//SharedPtr.cpp - sample code to demonstrate a shared pointer

#include <iostream>
#include <memory>
#include "Title.h"

void display(const char* s) {
    std::shared_ptr<Title> t1(new Title(s));//what is the value of the reference counter? 1
    t1->display();
    std::shared_ptr<Title> t2(t1);//what is the value of the reference counter? 2
    t2->display();
    std::cout << std::hex;
    std::cout << "&t1=" << (int*)&t1 << " &t2=" << (int*)&t2 << std::endl;
}//How many times is the Title object destroyed? Once

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