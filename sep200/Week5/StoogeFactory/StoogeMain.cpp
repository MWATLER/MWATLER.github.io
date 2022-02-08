//StoogeMain.cpp - main program for the three stooges

#include "Curly.h"
#include "Moe.h"
#include "Larry.h"

using namespace std;

int main() {
	const int NUM = 3;
	Stooge* roles[NUM];
	int choice = -1;

	for (int i = 0; i < NUM && choice != 0; ++i) {
		cout << "Larry(1) Moe(2) Curly(3) Go(0): ";
		cin >> choice;
		if (choice > 0 && choice < 4) {
			roles[i] = Stooge::make_stooge(choice);
		}
	}

	for (int i = 0; i < NUM; i++) {
		roles[i]->slap_stick();
	}

	for (int i = 0; i < NUM; i++)
		delete roles[i];

	return 0;
}