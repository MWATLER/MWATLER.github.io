// Input Manipulators
 // manipulator.cpp

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int sel;
    int length, height;

    do {
        system("CLS");
        cout << "1. Rectangle" << endl;
        cout << "2. Square" << endl;
        cout << "0. Exit" << endl;
        cin >> sel;
    } while (sel < 0 || sel>2);

    cout << endl;
    if (sel == 1) {
        cout << "Enter the length of the rectangle: ";
        cin >> length;
        cout << "Enter the height of the rectangle: ";
        cin >> height;
    }
    else if (sel == 2) {
        cout << "Enter the length of one side of the square: ";
        cin >> length;
        height = length;
    }

    cout << endl;
    cout << "+" << setw(length - 2) << setfill('-') << '-' << '+' << endl;
    for (int i = 0; i < height - 2; ++i) {
        cout << "|" << setw(length - 2) << setfill(' ') << ' ' << '|' << endl;
    }
    cout << "+" << setw(length - 2) << setfill('-') << '-' << '+' << endl;

    return 0;
}