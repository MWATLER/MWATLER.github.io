// Default Parameter Values
// default.cpp

#include <iostream>
using namespace std;

void display(int, int = 5, int = 0);

int main() {

    display(6, 7, 8);
    display(6);
    display(3, 4);
}

void display(int a, int b, int c) {
        cout << a << ", " << b << ", " << c << endl;
}