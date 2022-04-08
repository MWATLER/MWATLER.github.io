// Extraction2.cpp

#include <iostream>
using namespace std;

int main() {
    char t[8], u[64], v;

    cout << "Enter a name: ";
    cin.getline(t, 8);       // newline delimiter - accepts up to 7 chars 
                             //    and adds a null byte
	cout << "t is " << t << endl;
    cout << "Enter another name followed by a char: ";
    cin.getline(u, 64, '\t'); // tab delimiter - accepts up to 63 chars and
                             //    adds a null byte. Tab is the delimiter
    cin.get(v);              // extracts a single character after the tab

    cout << "t = " << t << endl;
    cout << "u = " << u << endl;
    cout << "v = " << v << endl;
	return 0;
}