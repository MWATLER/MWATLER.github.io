#define _CRT_SECURE_NO_WARNINGS
#define CURVE_RATIO 1.2
#define NUM 5
#define NUM_MARKS 5
#include <stdio.h>

struct Student {
	char name[31];
	int marks[NUM_MARKS];
	int studentNumber;
};

void CurveMarks(struct Student st[]);

int main(void) {
	struct Student student[NUM] = { "Bill", 45, 57, 78, 62, 56, 10000,
									"Tomasz", 66,67,78,44,59, 10001,
									"Anusha", 72, 76, 74, 81, 69, 10002,
									"Peng", 61, 62, 47, 56, 59, 10003,
									"Erika", 77, 72, 42, 66, 79, 10004 };

	CurveMarks(student);
	for (int i = 0; i < NUM; ++i) {
		printf("%s's marks are now", student[i].name);
		for (int j = 0; j < NUM_MARKS; ++j) printf(" %d", student[i].marks[j]);
		printf("\n");
	}
	return 0;
}

//Write a function called CurveMarks that takes the array of students
//and multiplies each mark by CURVE_RATIO.
//If a mark is over 100, set the mark to 100
void CurveMarks(struct Student st[]) {
	for (int i = 0; i < NUM; ++i) {
		for (int j = 0; j < NUM_MARKS; ++j) {
			int newMark = st[i].marks[j] * CURVE_RATIO;
			if (newMark > 100) newMark = 100;
			st[i].marks[j] = newMark;
		}
	}
}