//SeriesCircuit.cpp - Simulator for a series electrical circuit
//
// 15-Feb-21  M. Watler         Created.
#include<iostream>
#include "iComponent.h"

using namespace std;

int main(void) {
	const int NUM = 8;
	iComponent *component[NUM];
	component[0] = CreateComponent();
	component[1] = CreateComponent();
	component[2] = CreateComponent();
	component[3] = CreateComponent();
	component[4] = CreateComponent();
	component[5] = CreateComponent();
	component[6] = CreateComponent();
	component[7] = CreateComponent();

	for (double current = 0; current < 1; current += 0.1) {
		cout << "Current:" << current << endl;
		for (int i = 0; i < NUM; ++i) {
			component[i]->SetCurrent(current);
			component[i]->PrintReport();
		}
	}

	for (int i = 0; i < NUM; ++i) {
		delete component[i];
	}

	return 0;
}