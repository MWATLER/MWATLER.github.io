//Patron.cpp - definition for patrons
#include <chrono>
#include <iostream>
#include <sstream>
#include "DVD.h"
#include "ElectronicBook.h"
#include "MusicalInstrument.h"
#include "StandardPaperBook.h"
#include "Patron.h"

using namespace std;

Patron::Patron(int id, string name)
{
	patronID = id;
	fullName = name;
	numResources = 0;
	lateFees = 0;
}

void Patron::BorrowResources(void)
{
	int sel, sel2;
	string title, author, name;
	int year, id;
	bool isDone = false;
	const int maxResources = 5;

	do {
		do {
			cout << "Which resource do you want to borrow (1.Book, 2.DVD, 3.Musical Instrument, 0.Quit): ";
			cin >> sel;
		} while (sel < 0 || sel > 3);
		// discards the input buffer 
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (sel) {
		case 1:
			cout << "Enter the title: ";
			getline(cin, title);
			cout << "Enter the author: ";
			getline(cin, author);
			cout << "Enter the year of publication: ";
			cin >> year;
			cout << "Enter the ID number: ";
			cin >> id;
			do {
				cout << "What type of book (1.eBook, 2.Paper Book): ";
				cin >> sel2;
			} while (sel2 < 1 || sel2>2);
			if (sel2 == 1) {
				resource.push_back(new ElectronicBook(title, author, year, id));
			}
			else if (sel2 == 2) {
				resource.push_back(new StandardPaperBook(title, author, year, id));
			}
			break;
		case 2:
			cout << "Enter the title: ";
			getline(cin, title);
			cout << "Enter the release year: ";
			cin >> year;
			cout << "Enter the ID number: ";
			cin >> id;
			resource.push_back(new DVD(title, year, id));
			break;
		case 3:
			cout << "Enter the name: ";
			getline(cin, name);
			cout << "Enter the ID number: ";
			cin >> id;
			resource.push_back(new MusicalInstrument(name, id));
			break;
		case 0:
			isDone = true;
			break;
		}
		if (isDone == false) {
			auto start = std::chrono::system_clock::now();
			time_t date = std::chrono::system_clock::to_time_t(start);
			resource[numResources]->CheckOut(date);
			++numResources;
			if (numResources >= maxResources) {
				cout << "You have borrowed the maximum number of resources." << endl;
				isDone = true;
			}
		}
	} while (isDone==false);
}

void Patron::ReturnResources(void)
{
	lateFees = 0;
	for (int i = numResources - 1; i >= 0; --i) {
		auto end = std::chrono::system_clock::now();
		time_t date = std::chrono::system_clock::to_time_t(end);
		resource[i]->CheckIn(date);

		lateFees += resource[i]->CalculateFees();

		resource.pop_back();
	}
}

void Patron::ReportResources(void)
{
	for (int i = 0; i < numResources; ++i) {
		cout << fullName << " with patron ID " << patronID << " has borrowed " << resource[i]->GetTitle() << " with catalog ID " << resource[i]->GetCatalogID() << "." << endl;
	}
}

void Patron::ReportFees(void)
{
	cout.precision(2);
	cout << fullName << " with id " << patronID << " has " << lateFees << " in late fees." << endl;
}

