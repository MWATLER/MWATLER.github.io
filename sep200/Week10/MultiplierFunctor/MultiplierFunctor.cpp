//MultiplierFunctor.cpp - main function to demonstrate functors

#include <iostream>

using namespace std;

class Multiply {
	double val1;//retains state 
	double val2;//retains state
public:
	Multiply() { val1 = val2 = 0.0; }
	Multiply(double _val1, double _val2) {
		val1 = _val1;
		val2 = _val2;
	}
	//To make Multiply look like a function to the outside world,
	//we override the () operator
	double operator()(double _val1, double _val2) {//overloads operator() with parameters
		val1 = _val1;
		val2 = _val2;
		return val1 * val2;//note that val1 and val2 retain state after the function has exited
	}
	double operator()() {//overloads operator() without parameters
		return val1 * val2;
	}
};

int main() {
	Multiply mul1(4.4, 5.2);//created with the two-parameter constructor
	Multiply mul2;//created with the default constructor

	cout << mul1() << endl;//mul1() looks like a function to the outside world
	cout << mul2(2.2, 5.0) << endl;//mul2() looks like a function to the outside world

	return 0;
}