//CopyIf.cpp - demo code for copy_if

#include <vector>
#include <algorithm>
#include <iostream>

int main() {
	std::vector<int> v = { 1, 2, 4, 5, 7, 8, 10, 13, 17, 21, 43 };
	std::vector<int> c(15);//allocated for a vector of 15 integers
	std::copy_if(v.begin(), v.begin() + 10, c.begin(), [](int i) -> bool {
		return i % 2; });//the criteria is: true - odd number, false - even number
	for (auto e : c)
		if (e) std::cout << e << std::endl;
}
