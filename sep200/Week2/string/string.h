//string.h - class declaration and definition of a custom string class

#ifndef _STRING_H_
#define _STRING_H_

#include "stdio.h"//strlen

namespace bsa {
	class string {
		char* theString = nullptr;
		int len = 0;
	public:
		string() {}
		string(const char* aString) {
			len = strlen(aString);
			theString = new char[len + 1];//include space for the null terminator
			for (int i = 0; i < len; ++i) {
				theString[i] = aString[i];
			}
			theString[len] = '\0';
		}
		int size() const {
			return len;
		}
		string& operator=(const string& aString) {//string2 = string1;
			delete[] theString;
			len = aString.size();
			theString = new char[len + 1];//include space for the null terminator
			for (int i = 0; i < len; ++i) {
				theString[i] = aString[i];//these are not numbers, so what do '[' and ']' mean
			}
			theString[len] = '\0';//null terminate my character array
			return *this;//returns a reference to string2
		}
		char operator[](int i) const {
			if (i < len) return theString[i];
			else return '\0';
		}
		char* operator*() const {
			return theString;
		}
		string& operator+=(const string& aString) {//string3 += string2;
			int newLen = len + aString.size();
			char* temp = new char[newLen + 1];//plus the null terminator
			for (int i = 0; i < len; ++i) {
				temp[i] = theString[i];//copy everything from string3 into temp
			}
			for (int i = len; i < newLen; ++i) {
				temp[i] = aString[i - len];//copy everything from string2 into temp
			}
			temp[newLen] = '\0';//null terminate temp
			delete[] theString;//delete the old character array
			theString = temp;//point to the new character array
			len = newLen;//update len to newLen
			return *this;//returns the current object which is string3
		}
	};
}

#endif// _STRING_H_
