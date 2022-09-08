//HelloWorld.c - A simple hello world application

//History:
// 14-Jan-22  M. Watler         Created.
// 16-Jan-22  T. Student        Added return statement
// ...

/* This is documentation */

#include <stdio.h>//Include the standard input-output library

int main()//All programs start from main()
{
	printf("Hello World.\n");//Prints to the screen
	// \n means carriage return
	// \t means tab
	// \" means "
	printf("Hello \\World\".\n");
	printf("Hello \"World\".\n");
	printf("Hello \"World\".\n\n");
	printf("The world is 60%% healthy.\n");
	int result = 16 + 22;
	printf("result is %d\n", result);

	/*	//The below will cause the program to crash
		//Your CPU halts the execution of your program because it is doing things it shouldn't
		int a = 6;
		int b = 0;
		int c = a / b;
		printf("a=%d b=%d c=%d\n", a, b, c);


		int a[3];//puts aside memory for three integers
		a[0] = 5;//integer 1
		a[1] = 10;//integer 2
		a[2] = 15;//integer 3
		a[3] = 20;//integer 4? No! The CPU halts your program. We are trying to access memory that
				  //               we have no business accessing.
	*/

	return 0;//main() returns 0, this means no error
}
