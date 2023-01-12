// Title.h - Smart Pointers

#include <iostream>

class Title {
    const char* title;
public:
    Title(const char* s) : title(s) {}
    bool display() const {
        bool ret = true;
        if (!title[0]) {
            std::cout << "Invalid title!!" << std::endl;
            ret = false;
        }
        else {
            std::cout << title << std::endl;
        }
        return ret;
    }
    ~Title() {
        std::cout << "~Title: destroying Title" << std::endl;
    }
};