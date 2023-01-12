//PersonnelMain.cpp - main program for Seneca personnel

#include <iostream>
#include "Faculty.h"
#include "Student.h"

using namespace std;

int main() {
	const int NUM = 4;
	string name = "";
	string address = "";
	Personnel::Role role;
	int number;

	vector<unique_ptr<Personnel>> personnel;

	name = "Harold Ballard";
	address = "1 Yonge Street Toronto";
	role = Personnel::Role::Faculty;
	number = 111111;
	Faculty *faculty=new Faculty(name, role, address, number);
	personnel.push_back(make_unique<Faculty>(*faculty));

	name = "Mo Salah";
	address = "34 Liverpool Avenue Oakville";
	role = Personnel::Role::Faculty;
	number = 111112;
	faculty = new Faculty(name, role, address, number);
	personnel.push_back(make_unique<Faculty>(*faculty));

	name = "Kylian MBappe";
	address = "15 Saint-Germain Boulevard Vaughan";
	role = Personnel::Role::Student;
	number = 211111;
	Student* student = new Student(name, role, address, number);
	personnel.push_back(make_unique<Student>(*student));

	name = "Ferenc Puskas";
	address = "95 Budapest Crescent Toronto";
	role = Personnel::Role::Student;
	number = 211112;
	student = new Student(name, role, address, number);
	personnel.push_back(make_unique<Student>(*student));

	for (int i = 0; i < NUM; ++i){
		cout << personnel[i]->GetInfo();
	}



	return 0;
}