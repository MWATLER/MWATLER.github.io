//DynamicCast - main function to demonstrate dynamic_cast in C++

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

int main()
{
	Employee employee;
	Player player;
	employee.PrintInfo();        // Employee::PrintInfo()
	cout << endl;
	player.PrintInfo();        // Player::PrintInfo()
	cout << endl << endl;

	Employee* pEmployee = &employee;
	Player* pPlayer = &player;//Player is derived from Employee
	pEmployee->PrintInfo();      // Employee::PrintInfo()
	cout << endl;
	pPlayer->PrintInfo();      // Player::PrintInfo()
	cout << endl << endl;

//	pEmployee = &player;        // allowed
	pEmployee = dynamic_cast<Employee*> (&player);//Employee acts like a player
	pEmployee->PrintInfo();
	cout << endl;
	//	pPlayer = &employee;      // not allowed
	pPlayer = dynamic_cast<Player*>(&employee); // allowed but it returns NULL, Player cannot act like an employee
	if(pPlayer)	
		pPlayer->PrintInfo();

	return 0;
}