//dataLength.cpp - Determines how many characters between a start character and an end
//                 character in a data stream. This is to practice working with pointers.

#include<iostream>

#define METHOD1
//#define METHOD2

using namespace std;

int main(void) {
	//Let us say we want to parse a data stream, extracting everything between a
	//"begin" character and an "end" character. Let the "begin" character be the
	//number 0 and the "end" character be the number 1.
	//Let us extract all characters between 0 and 1 into a destination buffer,
	//and let us count the number of characters that have been extracted.
	const char* dataStream = "abcdef0ghijklmnopqrs1tuvwxyz";
	const char  beginChar = '0';
	const char  endChar = '1';
	const int BUFLEN = 32;
	char destBuf[BUFLEN];
	int count = 0;

	const char* dataStreamPtr = dataStream;

#ifdef METHOD1
	//Find the begin character
	while (*dataStreamPtr != '0') ++dataStreamPtr;
	++dataStreamPtr;//skip over the '0'
	while (*dataStreamPtr != '1') {//Find the end character
		destBuf[count] = *dataStreamPtr;
		++dataStreamPtr;
		++count;
	}
#endif

#ifdef METHOD2
	//Find the begin character
	int index = 0;
	while (dataStreamPtr[index] != '0') ++index;
	++index;//skip over the '0'
	while (dataStreamPtr[index] != '1') {//Find the end character
		destBuf[count] = dataStreamPtr[index];
		++index;
		++count;
	}
#endif
	//Null terminate the destination buffer
	destBuf[count] = '\0';

	//Print the results
	cout << "The destination buffer is " << destBuf << endl;
	cout << "It has " << count << " characters" << endl;

	return 0;
}