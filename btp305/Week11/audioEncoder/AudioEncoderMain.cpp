//AudioEncoderMain.cpp - main function for the audio encoder

#include "AudioEncoder.h"

using namespace std;

int main() {
	const string fileName = "audioData.dat";
	AudioEncoder audioEncoder(fileName);

	audioEncoder.Encode(1);
	char* originalData = audioEncoder.GetData();
	char* encodedData = audioEncoder.GetEncodedData();
	int len = audioEncoder.GetSize();

	cout << endl;
	cout << "THE ORIGINAL DATA:";
	for (int i = 0; i < len; ++i) {
		if (i % 64 == 0) cout << endl;
		cout << originalData[i];
	}

	cout << endl << endl;
	cout << "THE ENCODED DATA:";
	for (int i = 0; i < len; ++i) {
		if (i % 64 == 0) cout << endl;
		cout << encodedData[i];
	}
	cout << endl;

	return 0;
}