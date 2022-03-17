//PetInfo.h - class declaration for a pet

#include <iostream>//the input/output stream library of C++

//using namespace std;//never put using namespace anything inside a header file. The header file might be included
                      //by many other files which may not wish to use the namespace.

class PetInfo {//variables and functions are private by default with classes
private:
	std::string name;//the string data type is basically a character array. It has many features
	                 //that make char arrays easy to use.
	std::string type;
	int age;
public:
	//getter functions
	std::string GetName() const;
	std::string GetType() const;
	int GetAge() const;
	//the following functions protect our class variables. They perform validation before
	//the class variables are set.
	//setter functions
	bool SetName(std::string _name);//SetName tests _name against an empty string
	bool SetType(std::string _type);
	bool SetAge(int _age);//SetAge tests _age against a negative number
};