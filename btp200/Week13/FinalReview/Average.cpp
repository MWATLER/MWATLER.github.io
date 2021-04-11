#include <iostream>
using namespace std;

template <class T, class U, int N>
class Average {
	T result;
	U runningTotal;
	U Marks[N];
public:
	void AddMarks(U* marks, int N) {
		for (int i = 0; i < N; ++i) {
			Marks[i] = marks[i];
		}
	}
	double GetAverage() {
		runningTotal = 0;
		for (int i = 0; i < N; ++i) {
			runningTotal += Marks[i];
		}
		result = static_cast<T>(runningTotal) / N;
		return result;
	}
};

int main(void) {
	const int size = 5;
	int mark[] = { 77,66,77,78,76 };
	Average<double, int, size> a;
	a.AddMarks(mark, size);
	double result = a.GetAverage();
	cout << "result is " << result << endl;

	return 0;
}