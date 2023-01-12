//AmazonMain.cpp - main function for amazon purchases

#include <iostream>
#include <string>
#include "Book.h"
#include "DVD.h"
#include "DigitalMusic.h"

using namespace std;

int main() {
	cout << "For testing purchases, please order one book, one DVD, and one digital download." << endl;
	string title;
	int numAuthors;
	double price;
	
	cout << endl << "FOR THE BOOK" << endl;
	cout << "Enter the title: ";
	getline(cin, title);
	cout << "Enter the price: ";
	cin >> price;
	cout << "Enter the number of authors: ";
	cin >> numAuthors;
	Book book(title, numAuthors, price);

	cout << endl << "FOR THE DVD" << endl;
	cout << "Enter the title: ";
	getline(cin, title);
	cout << "Enter the price: ";
	cin >> price;
	cout << "Enter the number of authors: ";
	cin >> numAuthors;
	DVD dvd(title, numAuthors, price);


	cout << endl << "FOR THE DIGITAL MUSIC DOWNLOAD" << endl;
	cout << "Enter the title: ";
	getline(cin, title);
	cout << "Enter the price: ";
	cin >> price;
	cout << "Enter the number of authors: ";
	cin >> numAuthors;
	DigitalMusic digitalMusic(title, numAuthors, price);

	cout << book;
	cout << dvd;
	cout << digitalMusic;

	double totalCost = book.CalculateCost();
	totalCost += dvd.CalculateCost();
	totalCost += digitalMusic.CalculateCost();

	cout << endl << "The total cost is $" << totalCost << endl;

	return 0;
}
