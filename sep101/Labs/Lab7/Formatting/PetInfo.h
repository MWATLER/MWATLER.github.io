//PetInfo.h - class declaration for a pet

#include <iostream>

//using namespace std;//never put using namespace anything inside a header file. The header file might be included
                      //by many other files which may not wish to use the namespace.

class PetInfo {
	std::string name;
	std::string type;
	int age;
public:
	std::string GetName() const;
	std::string GetType() const;
	int GetAge() const;
	bool SetName(std::string _name);
	bool SetType(std::string _type);
	bool SetAge(int _age);
};