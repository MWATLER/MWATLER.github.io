//CatMain.cpp - main function for cats and their toys

#include "Cat.h"
#include "CatToy.h"

using namespace std;

int main() {
	CatToy cattoy1("Mouse:Pink:13.99");
	CatToy cattoy2("Bird:Blue:5.99");
	CatToy cattoy3("Baby Rabbit:Brown:12.99");

	Cat theCat("Sylvester");

	theCat += cattoy1;
	theCat += cattoy2;

	cout << theCat;

	theCat += cattoy3;
	theCat += cattoy2;

	cout << theCat;

	return 0;
}