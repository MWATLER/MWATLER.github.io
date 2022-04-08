//Extraction.cpp - Extracting data from a stream

#include <iostream>
using namespace std;

int main() {
    int i;
    char c;
    double x;
    char s[8];
    cout << "Enter an integer,\n"
        "a character,\n"
        "a floating-point number and\n"
        "a string : \n";
    cin >> i >> c >> x >> s;
    cout << "Entered " << endl;
    cout << i << ' ' << c << ' ' << x << ' ' << s << endl;

    cout << endl;
    cout << "Press the 'c' key to continue: ";
    while (getchar()!='c');//this while loop keeps "spinning" until 'c' is entered
    cout << endl;

    char d, t[8], u[8], v;

    cin.ignore(2000, '\n'); // extracts the newline from getchar()
    c = cin.get();          // extracts a single character
    cin.get(d);             // extracts a single character
    cin.get(t, 8);          // newline delimiter - accepts up to 7 chars 
                            //    and adds a null byte
    cin.ignore(2000, '\n'); // extracts the newline
    cin.get(u, 8, '\t');    // tab delimiter - accepts up to 7 chars and
                            //    adds a null byte
    cin.ignore();           // extracts the tab
    cin.get(v);             // extracts a single character

    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
    cout << "t = " << t << endl;
    cout << "u = " << u << endl;
    cout << "v = " << v << endl;
	return 0;
}