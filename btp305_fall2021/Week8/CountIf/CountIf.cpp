//CountIf.cpp - demo code for count_if

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int a[] = { 1, 2, 4, 5, 8, 9, 12, 13, 16, 18, 22 };
	//https://www.cplusplus.com/reference/algorithm/count_if/
	int n = count_if(a, a + 6, [](int i) {//go through the first 6 numbers
		return !(i & 1);
		});
	cout << "Even Numbers = " << n << endl;
}
