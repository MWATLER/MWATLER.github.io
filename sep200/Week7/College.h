//College.h - class declaration for a college

#include <iostream>

const int NUM = 4;

struct Student {
	std::string name;
	int year = 0;
	std::string program;
};

class College {
	Student student[NUM]; 
	std::string address;
public:
	College(Student* st, std::string addr) {
		for (int i = 0; i < NUM; ++i) {
			student[i] = st[i];
		}
		address = addr;
	}
	Student& operator[](int i) {
		return student[i];
	}
};