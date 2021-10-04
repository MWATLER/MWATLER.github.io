//Exception2.cpp - main function for exceptions

#include <iostream>

using namespace std;

class Base { virtual void member() {} };
class Derived :Base {};

int main() {
	//Bad allocation exception
	char* ptr = nullptr;
	bool success = true;
	do {
		try {
			long long int size;
			cout << "How big do you want your array: ";
			cin >> size;//try 1 with twelve 0's
			cout << "Attempting array char with size " << size << endl;
			ptr = new char[size];
			success = true;
		}
		catch (std::bad_alloc) {
			cout << "Allocation error" << endl;
			success = false;
		}
		catch (std::exception &e) {
			cout << "Standard Exception " << e.what() << endl;
			success = false;
		}
	} while (success == false);

	if (ptr != nullptr) {
		delete[] ptr;
		ptr = nullptr;
	}
	cout << "Success!!" << endl << endl;


	//Dynamic cast exception
	try {
		Base b;
		Derived& rd = dynamic_cast<Derived&>(b);
//		Derived* rd = dynamic_cast<Derived*>(&b);//OK
		cout << "Success" << endl;
	}
	catch (std::bad_cast& bc) {
		cout << "bad_cast caught: " << bc.what() << endl;
	}
	
	return 0;//This means no error in main()
}
