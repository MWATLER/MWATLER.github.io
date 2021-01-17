//dataParser.cpp - parses a data stream

#include<iostream>

using namespace std;

const int BUF_LEN = 32;

int main(void) {
	//A data stream where the first character represents
	//the length of the data to be copied
	char* data=(char *)"9introducingBTP200";
	char* dataPtr = data;
	char  destPtr[BUF_LEN];

	int len = dataPtr[0]-'0';//extract the length
	int i;
	for (i = 0; i < len && i<(BUF_LEN-1) && dataPtr[i]!='\0'; ++i) {
		destPtr[i] = dataPtr[i + 1];
	}
	destPtr[i] = '\0';
	cout << destPtr << endl;

	return 0;
}