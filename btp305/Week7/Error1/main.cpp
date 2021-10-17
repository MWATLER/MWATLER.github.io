// main.cpp
#include <iostream>
#include "A.h"
using namespace std;

int main()
{
//	int arrI[5]{ 0, 1, 2, 3, 4, 5 };//MW: six elements
	int arrI[6]{ 0, 1, 2, 3, 4, 5 };
//	cout << process(arrI) << endl;//MW: pass through the type
	cout << process<int, 6>(arrI) << endl;
//	A arrA[5]{ {1.2}, {2.3}, {3.4}, {4.5} };//MW: four elements
	A arrA[4]{ {1.2}, {2.3}, {3.4}, {4.5} };
//	cout << process(arrA) << endl;//MW: pass through the type
	cout << process<A, 4>(arrA).getValue() << endl;
}