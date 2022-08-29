//ConstCast.cpp - main code to demonstrate the const_cast in C++

#include <iostream>
#include <cstring>

using namespace std;

int main() {
	string str = "A123456789";
	const char* cstr = str.c_str();
//	char* nonconst_cstr = cstr;//assignment not allowed
	char* nonconst_cstr = const_cast<char*> (cstr);
	nonconst_cstr[0] = 'B';
	cout << cstr << endl;
	cout << nonconst_cstr << endl;
	return 0;
}