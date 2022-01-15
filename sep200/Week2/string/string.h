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
		string& operator=(const string& aString) {
			delete[] theString;
			len = aString.size();
			theString = new char[len + 1];//include space for the null terminator
			for (int i = 0; i < len; ++i) {
				theString[i] = aString[i];
			}
			theString[len] = '\0';
			return *this;
		}
		char operator[](int i) const {
			if (i < len) return theString[i];
			else return '\0';
		}
		char* operator*() const {
			return theString;
		}
		string& operator+=(const string& aString) {
			int newLen = len + aString.size();
			char* temp = new char[newLen + 1];
			for (int i = 0; i < len; ++i) {
				temp[i] = theString[i];
			}
			for (int i = len; i < newLen; ++i) {
				temp[i] = aString[i - len];
			}
			temp[newLen] = '\0';
			delete[] theString;
			theString = temp;
			len = newLen;
			return *this;
		}
	};
}

#endif// _STRING_H_
