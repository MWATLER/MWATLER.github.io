//BoyScout.h - header file for boy scouts

#define MAX_STR 64

struct BoyScout {
	char name[MAX_STR];//holds up to 63 characters plus the null terminator
	int age;
	int number;
};