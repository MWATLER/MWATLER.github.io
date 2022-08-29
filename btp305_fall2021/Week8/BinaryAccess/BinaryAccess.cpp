#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

    unsigned n, s;
    unsigned char c[16];
    unsigned short v, val[] = { 1, 2, 3, 258 };
    fstream fi(argv[1], ios::in | ios::out | ios::binary | ios::trunc);
    fstream fo(argv[2], ios::in | ios::out | ios::binary | ios::trunc);

    s = sizeof v;
    n = sizeof val / sizeof v;
    for (int k = 0; k < n; k++)
        fi.write((char*)(val + k), s);
    fi.seekg(0);
    for (int k = 0; k < n; k++) {
        fi.read((char*)&v, s);
        cout << setw(4) << v;
    }
    cout << endl;

    fi.seekg(0);
    fo.seekp(0);
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < s; i++) {
            fi.read((char*)&c[i], sizeof(char));
            cout << setw(4) << (int)c[i];
        }
        cout << endl;
        for (int j = s - 1; j >= 0; j--) {
            fo.write((char*)&c[j], sizeof(char));
            cout << setw(4) << (int)c[j];
        }
        cout << endl;
    }

    fo.seekg(0);
    fi.seekp(0);
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < s; i++) {
            fo.read((char*)&c[i], sizeof(char));
            cout << setw(4) << (int)c[i];
        }
        cout << endl;
        for (int j = s - 1; j >= 0; j--) {
            fi.write((char*)&c[j], sizeof(char));
            cout << setw(4) << (int)c[j];
        }
        cout << endl;
    }

    fi.seekg(0);
    for (int k = 0; k < n; k++) {
        fi.read((char*)&v, s);
        cout << setw(4) << v;
    }
    cout << endl;
    fo.seekg(0);
    for (int k = 0; k < n; k++) {
        fo.read((char*)&v, s);
        cout << setw(4) << v;
    }
    cout << endl;
}