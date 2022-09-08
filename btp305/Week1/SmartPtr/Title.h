// Title.h - Smart Pointers

#include <iostream>

class Title {
    const char* title;
public:
    Title(const char* s) : title(s) {}
    void display() const {
        if (!title[0]) {
            std::cout << "Invalid title!!" << std::endl;
        }
        else {
            std::cout << title << std::endl;
        }
    }
    ~Title() {
        std::cout << "~Title: destroying Title" << std::endl;
    }
};