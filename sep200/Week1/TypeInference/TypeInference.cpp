// TypeInference.cpp - Range-Based for loop

#include <iostream>

int main() {
    int a[]{ 1, 2, 3, 4, 5, 6 };
	auto age = 56;//BAD: The data is an int, therefore age is inferred to be an int
	auto name = "Ted Brown";//BAD: The data is a char array, therefore name is inferred to be a char array
	//The above are BAD because their types may differ from what you think

	for (int i = 0; i < 6; ++i) {
		std::cout << a[i] << ' ';
	}
	std::cout << std::endl;

	//The below is GOOD because the type 'a' is known, therefore we know 'e' will be
	//the same type as 'a', which is int.
	for (auto& e : a) {//GOOD: a short-hand notation of the above
		std::cout << e << ' ';
	}
    std::cout << std::endl;
}