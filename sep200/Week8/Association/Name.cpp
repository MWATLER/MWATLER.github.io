//Name.cpp - function definitions for name

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Name.h"

Name::Name(const char* n) {
    int len = std::strlen(n);
    name = new char[len + 1];
    std::strcpy(name, n);
}

Name::Name(const Name& src) {
    *this = src;
}

Name& Name::operator=(const Name& src) {
    if (this != &src) {
        delete[] name;
        int len = std::strlen(src.name);
        name = new char[len + 1];
        std::strcpy(name, src.name);
    }
    return *this;
}

Name& Name::operator=(const char* n) {
    delete[] name;
    int len = std::strlen(n);
    name = new char[len + 1];
    std::strcpy(name, n);
    return *this;
}

Name::~Name() { 
    delete[] name; 
}

const char* Name::get() const {
    return name;
}

void Name::set(const char* n) {
    delete[] name;
    int len = std::strlen(n);
    name = new char[len + 1];
    std::strcpy(name, n);
}