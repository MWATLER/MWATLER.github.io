// Title.h - Smart Pointers

#include <iostream>

class Title {
    const char* title;
    const char* validTitle() const {
        if (!title[0]) throw "invalid title";
        return title;
    }
public:
    Title(const char* s) : title(s) {}
    void display() const {
        std::cout << validTitle() << std::endl;
    }
    ~Title() {
        std::cout << "~Title: destroying Title" << std::endl;
    }
};