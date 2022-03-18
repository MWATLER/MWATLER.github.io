//ToolIf.cpp - factory pattern for the tool box

#include "Screwdriver.h"
#include "Hammer.h"

using namespace std;

ToolIf* CreateTool() {//factory pattern, no tool objects are created until the program runs
	ToolIf* tool = nullptr;
	int select = 0;
	string name;
	double cost;
//	tool = new ToolIf("Miguel", 10.0);//I never create an object of type ToolIf in this example, 
	                                  //because it is simply not possible and I don't want to.
	do {
		cout << endl;
		cout << "Enter 1 for a hammer, or" << endl;
		cout << "Enter 2 for a screwdriver." << endl;
		cout << "Selection: ";
		cin >> select;
		cin.ignore(1000, '\n');
		switch (select) {
		case 1:
			cout << "What is the hammer's name? ";
			cin >> name;
			cout << "How much does this hammer cost? $";
			cin >> cost;
			tool = new Hammer(name, cost);
			break;
		case 2:
			cout << "What is the screwdriver's name? ";
			cin >> name;
			cout << "How much does this screwdriver cost? $";
			cin >> cost;
			tool = new Screwdriver(name, cost);
			break;
		default:
			cout << "Invalid selection, try again!" << endl;
		}
	} while (select < 1 || select>2);//repeat for an invalid selection

	return tool;
}