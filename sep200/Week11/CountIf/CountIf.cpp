//CountIf.cpp - demo code for count_if

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int a[] = { 1, 2, 4, 5, 8, 9, 12, 13, 16, 18, 22 };
	int n = count_if(a, a + 6, [](int i) {//go through the first 6 numbers
		return !(i & 1);//true - even, false - odd
		//1 in binary is 0000 0001
		//8 in binary is 0001 0000
		//9 in binary is 0001 0001
		//3 in binary is 0000 0011
		//in pseudo-code, we would writen b7 b6 b5 b4 b3 b2 b1 b0
		//any odd  number will have the least significant bit set to 1
		//any even number will have the least significant bit set to 0
		});
	cout << "Even Numbers = " << n << endl;
}
