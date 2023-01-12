//CurveMarks.cpp - demonstrates STL's transform algorithm

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<double> marks = { 80, 90, 70 };
	transform(marks.begin(), marks.end(), marks.begin(), [](double& m) {
		m += 15.0;
		if (m > 100.0) m = 100.0;
		return m;
		});
	for (auto m : marks) {
		cout << m << endl;
	}
	return 0;
}