//StudentGradeAdapter.h - Adapter for student grades
//
// 06-Jun-22  M. Watler         Created

#ifndef _STUDENTGRADEADAPTER_H_
#define _STUDENTGRADEADAPTER_H_

enum class GradeMode {
	letterGrade,
	numberGrade
};

class StudentGradeAdapter {
public:
	virtual void run() = 0;
	virtual ~StudentGradeAdapter() {};
};


#endif _STUDENTGRADEADAPTER_H_