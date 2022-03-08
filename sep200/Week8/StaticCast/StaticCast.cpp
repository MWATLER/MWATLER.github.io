//StaticCast.cpp - main function to demonstrate static_cast in C++

#include <iostream>

using namespace std;

class Employee {
	string name{ "Smitty Werbenmanjensen" };
	int number{ 1000123 };
public:
	virtual void PrintInfo() {
		cout << "Employee:" << name << " " << number;
	}
};

class Player : public Employee {
	int points{ 48 };
public:
	void PrintInfo() {
		Employee::PrintInfo();
		cout << " " << points;
	}
};

class Shape {
public:
	int length{ 10 };
	int width{ 5 };
};

int main()
{
	Employee employee;
	Player player;//Player is derived from Employee

	// #1: valid upcast
	Employee* pEmployee = static_cast<Employee*>(&player);//Employee acts like a player
	pEmployee->PrintInfo();

	// #2: valid downcast
	Player* pPlayer = static_cast<Player*> (&employee);//Player acts like an employee
	pPlayer->PrintInfo();

	// #3: invalid, between unrelated classes
//	Shape* pShape = static_cast<Shape*> (&player);

//	cout << "pEmployee: " << pEmployee->name << " " << pEmployee->number << " "  << /*pEmployee->points <<*/ endl;
//  cout << "pPlayer: " << pPlayer->name << " " << pPlayer->number << " " << pPlayer->points << endl;

	return 0;
}