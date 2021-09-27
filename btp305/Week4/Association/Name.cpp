//Name.cpp - function definitions for name

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Name.h"

Name::Name(const char* n) : name{ new char[std::strlen(n) + 1] } {
    std::strcpy(name, n);
}
Name::Name(const Name& src) {
    *this = src;
}
Name& Name::operator=(const Name& src) {
    if (this != &src) {
        if(name!=nullptr) delete[] name;
        name = new char[std::strlen(src.name) + 1];
        std::strcpy(name, src.name);
    }
    return *this;
}
Name::~Name() { 
	if(name!=nullptr) delete[] name; 
}

const char* Name::get() const {
    return name;
}
void Name::set(const char* n) {
    if(name!=nullptr) delete[] name;
    name = new char[std::strlen(n) + 1];
    std::strcpy(name, n);
}