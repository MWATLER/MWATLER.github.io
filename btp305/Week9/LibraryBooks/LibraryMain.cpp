//LibraryMain.cpp - main function for the library of books

#include "LibraryBooks.h"

using namespace std;

int main() {
	const int NUM = 5;
	Book books[NUM] = {
		{"Marcel Proust", "In Search of Lost Time", 468, 14.29},
		{"Ulysses", "James Joyce", 736, 21.95},
		{"Don Quixote", "Miguel de Cervantes", 1072, 10.99},
		{"One Hundred Years of Solitude", "Gabriel Garcia Marquez", 417, 14.49},
		{"The Great Gatsby", "F. Scott Fitzgerald", 180, 8.41},
	};
	LibraryBooks library(books, NUM);
	bool ret = true;
	int retVal = 0;
	cout << "THE LIBRARY (US DOLLARS)" << endl;
	library.display(cout);
	cout << endl;

	const double USToCanadian = 1.2;
	ret = library.ConvertPrice(USToCanadian);
	if (ret) {
		cout << "THE LIBRARY (CAN DOLLARS)" << endl;
		library.display(cout);
		cout << "This library has books which total " << library.TotalPages() << " pages." << endl;
	}
	else {
		cout << "Cannot convert the price" << endl;
		retVal = -1;
	}
	cout << endl;

	ret = library.sort("pages");
	if (ret) {
		cout << "THE LIBRARY (CAN DOLLARS) SORTED BY PAGES" << endl;
		library.display(cout);
	}
	else {
		cout << "Cannot sort by pages" << endl;
		retVal = -2;
	}
	cout << endl;

	ret = library.sort("price");
	if (ret) {
		cout << "THE LIBRARY (CAN DOLLARS) SORTED BY PRICE" << endl;
		library.display(cout);
	}
	else {
		cout << "Cannot sort by price" << endl;
		retVal = -3;
	}
	cout << endl;

	return retVal;
}