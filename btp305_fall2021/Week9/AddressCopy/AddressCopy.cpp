//AddressCopy.cpp - main function for swapping addresses

#include <iostream>

void swap(char*& a, char*& b) {
    char* t = a;
    a = b;
    b = t;
}

int main() {
    const int SIZE = 19;
    char* p = new char[SIZE];
    strcpy_s(p, SIZE, "May be overwritten");
    char* s = new char[SIZE];
    s[0] = '\0';
    std::cout << std::hex;
    std::cout << "*p: " << p << std::endl;
    std::cout << "*s: " << s << std::endl;
    std::cout << " p = " << (int*)p << std::endl;
    std::cout << " s = " << (int*)s << std::endl << std::endl;

    swap(s, p);

    s[0] = 'm';  // OK
    std::cout << std::hex;
    std::cout << "*p: " << p << std::endl;
    std::cout << "*s: " << s << std::endl;
    std::cout << " p = " << (int*)p << std::endl;
    std::cout << " s = " << (int*)s << std::endl;

    delete[] p;
    delete[] s;

    return 0;
}