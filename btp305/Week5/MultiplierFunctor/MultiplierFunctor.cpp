//MultiplierFunctor.cpp - main function to demonstrate functors

#include <iostream>

using namespace std;

class Multiply {
	double val1;
	double val2;
public:
	Multiply() { val1 = val2 = 0.0; }
	Multiply(double _val1, double _val2) {
		val1 = _val1;
		val2 = _val2;
	}
	double operator()(double _val1, double _val2) {
		return _val1 * _val2;
	}
	double operator()(void) {
		return val1 * val2;
	}
};

int main() {
	Multiply mul1(4.5, 2.0);
	Multiply mul2;

	cout << mul1() << endl;
	cout << mul2(2.2, 5.0) << endl;

	return 0;
}