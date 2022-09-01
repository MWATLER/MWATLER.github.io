//Expressions.c - A simple program to demonstrate expressions

#include <stdio.h>

int main(void)
{

	// Demonstrates the order of operations in maths
	int answer = 4 * 6 + 6 / 3;// Reduces to 24 + 2
	printf("4 * 6 + 6 / 3 is %d\n", answer);
	answer = (4 * 6 + 6) / 3;// Reduces to 30 / 3
	printf("(4 * 6 + 6) / 3 is %d\n", answer);

	// Demonstrates relational expressions
	int i, j, res;
	printf("Enter an integer: ");
	scanf("%d", &i);
	printf("Enter another integer: ");
	scanf("%d", &j);
	res = i < j;
	printf("%d < %d yields %d\n", i, j, res);

	int k;
	printf("Enter a third integer: ");
	scanf("%d", &k);
	res = i < j && j < k;
	printf("%d < %d and %d < %d yields %d\n", i, j, j, k, res);
	res = i < j || j < k;
	printf("%d < %d or %d < %d yields %d\n", i, j, j, k, res);

	// Demonstrates shorthand assignments;
	int runningSum = 0;//The running sum of marks
	int numMarks = 0;//The number of marks
	int mark;//The current mark
	//We are going to enter three marks and then calculate the average of them.
	++numMarks;//increment numMarks by one
	printf("Enter mark %d: ", numMarks);
	scanf("%d", &mark);
	runningSum += mark;//runningSum = runningSum + mark;
	++numMarks;//increment numMarks by one again (should be 2)
	printf("Enter mark %d: ", numMarks);
	scanf("%d", &mark);
	runningSum += mark;//runningSum = runningSum + mark;
	printf("Enter mark %d: ", ++numMarks);//Evaluate numMarks before use
//	printf("Enter mark %d: ", numMarks++);//Evaluate numMarks after use
	scanf("%d", &mark);
	runningSum += mark;
	float floatAverage = (float)runningSum / numMarks;
	printf("The average of %d marks is %f\n", numMarks, floatAverage);

	int average = floatAverage;//average is the truncated value of floatAverage
 	printf("The integer average is %d\n", average);

	// Exercises with pre and post increment
	int var = 0;
	printf("var=%d\n", var++);//This will print var then increment it.
                              //You should see var=0

	printf("var=%d\n", var);//You should see var=1

	printf("var=%d\n", ++var);//This will increment var then print it.
	                          //You should see var=2

	printf("var=%d\n", var);//You should see var=2

    printf("DONE\n");

	return 0;
}