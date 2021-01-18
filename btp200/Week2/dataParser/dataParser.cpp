//dataParser.cpp - parses a data stream

#include<iostream>

using namespace std;

const int BUF_LEN = 32;

int main(void) {
	//A data stream where the first character represents
	//the length of the data to be copied
	const char* data="9introducingBTP200";//9 is metadata, it represents the length
	                                      //of data to be copied
	const char* dataPtr = data;//dataPtr[0]='9'
	char  dest[BUF_LEN];

	int len = dataPtr[0] - '0';//extract the length
//	int len = *dataPtr - '0';//extract the length
	int i;
	for (i = 0; i < len && i<(BUF_LEN-1) && dataPtr[i]!='\0'; ++i) {
		dest[i] = dataPtr[i + 1];//Why i+1 ? Because we skip the first character
		//dest[0] = dataPtr[1] = 'i'
		//dest[1] = dataPtr[2] = 'n'
		//dest[2] = dataPtr[3] = 't'
		//dest[3] = dataPtr[4] = 'r'
		//dest[4] = dataPtr[5] = 'o'
		//dest[5] = dataPtr[6] = 'd'
		//dest[6] = dataPtr[7] = 'u'
		//dest[7] = dataPtr[8] = 'c'
		//dest[8] = dataPtr[9] = 'i'
	}
	dest[i] = '\0';//If len is 9, what is "i" here? i is 9
	cout << dest << endl;//dest="introduci"

	return 0;
}