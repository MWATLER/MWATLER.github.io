#include <iostream>

using namespace std;

template <typename T, typename U>
void Min(T a, U b)
{
	return a < static_cast<T>(b) ? a : static_cast<T>(b);
}

int main()
{
	int num1 = 10, num2 = 5;
	double num3 = 11.1, num4 = 2.2, num5 = 255.0;
	char char1 = 'e', char2 = 102;

	cout << "The smaller value between " << num1 << " and " << num3 << " is " << Min(num1, num3) << endl;
	cout << "The smaller value between " << num4 << " and " << num2 << " is " << Min(num4, num2) << endl;
	cout << "The smaller value between " << char1 << " and " << char2 << " is " << Min(char1, char2) << endl;
	cout << "The smaller value between " << char2 << " and " << num5 << " is " << Min(char2, num5) << endl;

	return 0;
}






























/* ANSWER */
/* Min should have a return type, preferably U or T. */
/* The last comparison compares two variables who are too different in type for a reasonable comparison. */