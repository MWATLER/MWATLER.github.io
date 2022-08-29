//StaticCast.cpp - main function to demonstrate static_cast in C++

#include <iostream>

using namespace std;

class Employee {
public:
	string name{ "Smitty Werbenmanjensen" };
	int number{ 1000123 };
};

class Player : public Employee {
public:
	int points{ 48 };
};

class Shape {
public:
	int length{ 10 };
	int width{ 5 };
};

int main()
{
	Employee employee;
	Player player;

	// #1: valid upcast
	Employee* pEmployee = static_cast<Employee*>(&player);

	// #2: valid downcast
	Player* pPlayer = static_cast<Player*> (&employee);

	// #3: invalid, between unrelated classes
//	Shape* pShape = static_cast<Shape*> (&player);

	cout << "pEmployee: " << pEmployee->name << " " << pEmployee->number << " " /* << pEmployee->points */ << endl;
	cout << "pPlayer: " << pPlayer->name << " " << pPlayer->number << " " << pPlayer->points << endl;

	return 0;
}