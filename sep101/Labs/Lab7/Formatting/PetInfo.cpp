//PetInfo.cpp - function definitions for the pet

#include "PetInfo.h"

std::string PetInfo::GetName() const {
	return name;
}

std::string PetInfo::GetType() const {
	return type;
}

int PetInfo::GetAge() const {
	return age;
}

bool PetInfo::SetName(std::string _name) {
	bool retVal = true;
	if (_name.size() == 0) retVal = false;
	else name = _name;
	return retVal;
}

bool PetInfo::SetType(std::string _type) {
	bool retVal = true;
	if (_type.size() == 0) retVal = false;
	else type = _type;
	return retVal;
}

bool PetInfo::SetAge(int _age) {
	bool retVal = true;
	if (_age < 0) retVal = false;
	else age = _age;
	return retVal;
}
