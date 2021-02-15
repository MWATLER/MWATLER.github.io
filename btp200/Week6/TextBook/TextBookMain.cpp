//TextBookMain.cpp - main program for the text book

// 15-Feb-21  M. Watler         Created.
#include <iostream>
#include "TextBook.h"

using namespace std;

int main(void) {
	TextBook book1("Book1");
	TextBook book2("Book2");

	book1.ImportBookByString("CheeseShop.txt");
	book1.ExportBook("CheeseShop2.txt");
	book2.ImportBookByLine("CheeseShop.txt");
	book2.ExportBook("CheeseShop3.txt");

	book1.DisplayBook();
	book2.DisplayBook();

	return 0;
}