//StudentMain.c - main function for student marks

#define _CRT_SECURE_NO_WARNINGS
#define NUM_STUDENTS 3
#include <stdio.h>
#include "Student.h"

int main(void) {
	struct Student student[NUM_STUDENTS];

	//gather information
	for (int i = 0; i < NUM_STUDENTS; ++i) {
		printf("Student's name: ");
		scanf("%[^\n]s", student[i].name);
		printf("Student's year: ");
		scanf("%d", &student[i].year);
		printf("Number of courses: ");
		scanf("%d", &student[i].numMarks);
		for (int j = 0; j < student[i].numMarks; ++j) {
			printf("Enter the mark for course %d : ", j+1);
			scanf("%d", &student[i].mark[j]);
		}
		CalculateAveragePassByAddress(&student[i]);
		printf("\n");
		while (getchar() != '\n');//clear the input buffer
	}

	//Calculate the average of the third student
	double average = CalculateAveragePassByValue(&student[2]);
	//The above function did not update average in the structure Student
	printf("The average for %s in year %d is %.2lf\n", student[2].name, student[2].year, average);

	//Calculate the average of the second student
	bool ret = CalculateAveragePassByAddress(&student[1]);
	if (ret) {
		//The above function updated average in the structure Student
		printf("The average for %s in year %d is %.2lf\n", student[1].name, student[1].year, student[1].average);
		printf("\n");

		//Calculate the average for all students
		double cumulativeAverage;
		ret = CalculateAverages(student, NUM_STUDENTS, &cumulativeAverage);//struct Student student[NUM_STUDENTS];
		if (ret) {
			printf("The average for all students is %.2lf\n", cumulativeAverage);
		}
	}

	if (ret) return 0;
	return -1;
}
