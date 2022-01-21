// StudentAverageMarkFile.c - a program to retrieve student information from a
//                            file and calculate the student's average mark.
//
#include <stdio.h>

int main(void)
{
	int student_id;
	char lastName[30];
	float mark1;
	float mark2;
	float mark3;
	double runningTotal = 0;
	double averageMark;
	int numMarks = 3;
	FILE* fp;
	fopen_s(&fp, "StudentMarks.txt", "r");
	fscanf_s(fp, "%s", lastName, 30);
	fscanf_s(fp, "%d", &student_id);
	fscanf_s(fp, "%f", &mark1);
	runningTotal += mark1;
	fscanf_s(fp, "%f", &mark2);
	runningTotal += mark2;
	fscanf_s(fp, "%f", &mark3);
	fclose(fp);
	runningTotal += mark3;

	averageMark = runningTotal / numMarks;

	fopen_s(&fp, "StudentAverageMark.txt", "w");
	fprintf(fp, "The student %s with id %d has marks of %f, %f, and %f\n", 
		lastName, student_id, mark1, mark2, mark3);
	fprintf(fp, "%s has an average mark of %lf\n", lastName, averageMark);
	fclose(fp);

	return 0;
}