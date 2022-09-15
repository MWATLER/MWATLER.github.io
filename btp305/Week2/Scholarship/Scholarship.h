//Scholarship.h - header file for Scholarship.cpp

//History:
//15-Sep-22  M. Watler          Created.

#include <iostream>

enum class MarkType {
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