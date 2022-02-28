//Cast.cpp - a test for casting

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

    Player* b1 = f;                              // (1)
    Player* b2 = static_cast<Player*>(f);           // (2)
    Player* b3 = dynamic_cast<Player*>(f);          // (3)
    //Only reinterpret_cast can be used to convert a pointer to an object to a pointer to an unrelated object type.
    Player* b4 = reinterpret_cast<Player*>(f);      // (4)
    Player* b5 = const_cast<Player*>(f);            // (5)

    return 0;
}