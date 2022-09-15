//Scholarship.cpp - simple program to demonstrate unions with enumerations

//History:
//15-Sep-22  M. Watler          Created.

#include "Scholarship.h"

using namespace std;
/*
enum MarkType {
	MarkPercent,
	MarkLetterGrade
};

union Mark {
	int percent;
	char letterGrade;
};

struct Student {
	std::string name;
	double scholarship;
	MarkType type;
	Mark mark;
};

double Scholarship(Mark mark, MarkType type);
*/
int main(void) {
	//(in)famous British people
	Student student[] = {
		{"William Shakespeare", 0.0, MarkType::MarkLetterGrade, 'A'},
		{"King Henry VIII", 0.0, MarkType::MarkPercent, 57},
		{"Winston Churchill", 0.0, MarkType::MarkPercent, 75},
		{"Prince Harry", 0.0, MarkType::MarkLetterGrade, 'C'}
	};

	for (auto& s : student) {
		s.scholarship = Scholarship(s.mark, s.type);
		if (s.scholarship > 0.0) cout << s.name << " won a scholarship of $" << s.scholarship << "." << endl;
		else cout << s.name << " won nothing." << endl;
	}

	return 0;
}

double Scholarship(Mark mark, MarkType type) {
	double amount = 0.0;
	switch (type) {
	case MarkType::MarkPercent:
		if (mark.percent >= 80) {
			amount = 5000.00;
		}
		else if (mark.percent >= 70) {
			amount = 2000.00;
		}
		break;
	case MarkType::MarkLetterGrade:
		if (mark.letterGrade=='A') {
			amount = 5000.00;
		}
		else if (mark.letterGrade == 'B') {
			amount = 2000.00;
		}
		break;
	}

	return amount;
}