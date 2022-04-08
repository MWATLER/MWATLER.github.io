// Input Manipulators
 // manipulator.cpp

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int sel;
    int length, height;

    do {
        system("CLS");//clears the screen
        cout << "1. Rectangle" << endl;
        cout << "2. Square" << endl;
        cout << "0. Exit" << endl;
        cin >> sel;
    } while (sel < 0 || sel>2);

    cout << endl;
    if (sel == 1) {//rectangle
        cout << "Enter the length of the rectangle: ";
        cin >> length;
        cout << "Enter the height of the rectangle: ";
        cin >> height;
    }
    else if (sel == 2) {//square
        cout << "Enter the length of one side of the square: ";
        cin >> length;
        height = length;
    }

    cout << endl;
    cout << "+" << setw(length - 1) << setfill('-') << '+' << endl;
    for (int i = 0; i < height - 2; ++i) {
        cout << "|" << setw(length - 1) << setfill(' ') << '|' << endl;
    }
    cout << "+" << setw(length - 1) << setfill('-') << '+' << endl;

    return 0;
}