//ReinterpretCast.cpp - main function to demonstrate the reinterpret_cast in C++

#include <iostream>

using namespace std;

struct Employee {
    string name;
    int number;
};

struct Player {
    string name;
    int points;
};

int main(int argc, char** argv)
{
    Employee* f = new Employee;
    f->name = "Smitty Werbenmanjensen";
    f->number = 1000123;

    //Only reinterpret_cast can be used to convert a pointer to an object to a pointer to an unrelated object type.
    Player* b4 = reinterpret_cast<Player*>(f);      // (4)

    cout << "f:" << f->name << " " << f->number << endl;
    cout << "b4:" << b4->name << " " << b4->points << endl;

    return 0;
}