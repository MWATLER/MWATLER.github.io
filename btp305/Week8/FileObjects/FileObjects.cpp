#include <fstream>
#include <iostream>
using namespace std;

int main() {
    char c;
    fstream f("files.walk", ios::in | ios::out | ios::trunc);

    f << "Portable Programs" << endl;
    f.seekp(0, ios::beg);
    f << "Horrible";
    streampos pos = f.tellp();
    f.seekp(1, ios::cur);
    f << "Ana";

    f.seekg(0, ios::beg);
    while (f.get(c))
        cout << c;
    f.clear();

    f.seekg(9);
    while (f.get(c))
        cout << c;
    f.clear();
}