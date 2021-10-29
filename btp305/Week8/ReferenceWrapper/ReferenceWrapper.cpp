// ReferenceWrapper.cpp - sample code to demonstrate reference wrappers

#include <iostream>
#include <functional>

using namespace std;

void increment(int& x, int& y) { ++x, ++y; }

int main() {
    int a = 10, b = 20;
    auto inc = bind(increment, std::ref(a), b);
    inc();
    cout << "a = " << a << std::endl;
    cout << "b = " << b << std::endl;
}
