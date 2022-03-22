//Average.cpp - calculating averages with a lambda function

#include <iostream>
#include <vector>

using namespace std;

int main() {
	const int NUM = 3;
	struct Person {//the blueprint for a person
		int age;
		int height;//cm's
	};
	vector<Person> basketballPlayers;//a vector of objects of type Person
	vector<Person> hockeyPlayers;//a vector of objects of type Person

	cout << "Enter data for basketball players." << endl;
	for (int i = 0; i < NUM; ++i) {
		Person aPerson;
		cout << "Enter person " << (i + 1) << "'s age: ";
		cin >> aPerson.age;
		cout << "Enter person " << (i + 1) << "'s height: ";
		cin >> aPerson.height;
		basketballPlayers.push_back(aPerson);
		cout << endl;
	}

	cout << "Enter data for hockey players." << endl;
	for (int i = 0; i < NUM; ++i) {
		Person aPerson;
		cout << "Enter person " << (i + 1) << "'s age: ";
		cin >> aPerson.age;
		cout << "Enter person " << (i + 1) << "'s height: ";
		cin >> aPerson.height;
		hockeyPlayers.push_back(aPerson);
		cout << endl;
	}

	//double average(const vector<Person>& person){...} 
	auto average = [](const vector<Person>& person) -> double
	{
		double runningTotal = 0;
		for (const auto& p : person) {//foreach format 
			runningTotal += (double)p.height;
		}
		return runningTotal / person.size();
	};

	cout << "The average height of the basketball players is " << average(basketballPlayers) << " cm's." << endl;
	cout << "The average height of the hockey players is " << average(hockeyPlayers) << " cm's." << endl;
	return 0;
}