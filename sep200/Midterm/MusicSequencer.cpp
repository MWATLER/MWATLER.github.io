//MusicSequencer.cpp - main function for a musical sequencer

#include "Vocals.h"
#include "Keyboard.h"
#include "BassGuitar.h"
#include "Guitar.h"
#include "Percussion.h"
#include "MusicSequencerCommon.h"
#include "SequencedData.h"
#include <string>

using namespace std;

int main() {
	const int NUM_ITEMS = 11;
	MusicalItem* item[NUM_ITEMS];

	//QUESTION 1: What is the static type of item[0] and what is its dynamic type?
	item[0] = new Percussion("Snare Drum Set", 1599.00);
	item[1] = new Percussion("Electronic Drum Set", 1799.00);
	item[2] = new BassGuitar("Bass Guitar 1", 688.99);
	item[3] = new BassGuitar("Bass Guitar 2", 688.99);
	item[4] = new Keyboard("Double Keyboard", 7888.99);
	item[5] = new Keyboard("Single Keyboard", 4888.99);
	item[6] = new Guitar("Acoustic Guitar", 1299.99);
	item[7] = new Guitar("Lead Guitar", 1899.99);
	item[8] = new Vocals("Lead Singer", 0.00);
	item[9] = new Vocals("Backup Singer 1", 0.00);
	item[10] = new Vocals("Backup Singer 2", 0.00);

	const int LOOP_COUNT = 5;
	for (int i = 0; i < NUM_ITEMS; ++i) {
		for (int j = 0; j < LOOP_COUNT; ++j) {
			cout << *item[i];
			//QUESTION 2: For item[0], which GenerateData() function(s) is/are called?
			item[i]->GenerateData();
		}
	}

	const unsigned char* dataPtr = nullptr;
	SequencedData<unsigned char> sequencedData;
	CenterBackSpeaker<unsigned char> centerBackSpeaker;
	LeftSpeaker<unsigned char> leftSpeaker;
	RightSpeaker<unsigned char> rightSpeaker;
	CenterFrontSpeaker<unsigned char> centerFrontSpeaker;
	const int PERCUSSION_INDEX = 0;
	const int BASS_GUITAR_INDEX = 2;
	const int KEYBOARD_INDEX = 4;
	const int GUITAR_INDEX = 6;
	const int VOCALS_INDEX = 8;
	for (int i = PERCUSSION_INDEX; i < BASS_GUITAR_INDEX; ++i) {//percussion
		//QUESTION 3: For item[0], which GetData() function is being called?
		dataPtr = item[i]->GetData();
		//QUESTION 4: For item[0], which Transform function(s) is/are called?
		dataPtr = Transform(centerBackSpeaker, dataPtr, LOOP_COUNT * Percussion::DATA_CHUNK_LEN);
		sequencedData.AddData(dataPtr, LOOP_COUNT * Percussion::DATA_CHUNK_LEN);
	}
	for (int i = BASS_GUITAR_INDEX; i < KEYBOARD_INDEX; ++i) {// bass guitars
		dataPtr = item[i]->GetData();
		dataPtr = Transform(centerBackSpeaker, dataPtr, LOOP_COUNT * BassGuitar::DATA_CHUNK_LEN);
		sequencedData.AddData(dataPtr, LOOP_COUNT * BassGuitar::DATA_CHUNK_LEN);
	}
	for (int i = KEYBOARD_INDEX; i < GUITAR_INDEX; ++i) {//keyboards
		dataPtr = item[i]->GetData();
		dataPtr = Transform(leftSpeaker, dataPtr, LOOP_COUNT * Keyboard::DATA_CHUNK_LEN);
		sequencedData.AddData(dataPtr, LOOP_COUNT * Keyboard::DATA_CHUNK_LEN);
	}
	for (int i = GUITAR_INDEX; i < VOCALS_INDEX; ++i) {//guitars
		dataPtr = item[i]->GetData();
		dataPtr = Transform(rightSpeaker, dataPtr, LOOP_COUNT * Guitar::DATA_CHUNK_LEN);
		sequencedData.AddData(dataPtr, LOOP_COUNT * Guitar::DATA_CHUNK_LEN);
	}
	for (int i = VOCALS_INDEX; i < NUM_ITEMS; ++i) {//vocals
		dataPtr = item[i]->GetData();
		dataPtr = Transform(centerFrontSpeaker, dataPtr, LOOP_COUNT * Vocals::DATA_CHUNK_LEN);
		sequencedData.AddData(dataPtr, LOOP_COUNT * Vocals::DATA_CHUNK_LEN);
	}

	//QUESTION 5: What is the length of the sequenced data?
	int len = sequencedData.GetLen();
	for (int i = 0; i < len; ++i) {
		printf(" 0x%02x", sequencedData[i]);
		//QUESTION 6: Why am I adding an endl here?
		if (i % 8 == 7) cout << endl;
	}

	//QUESTION 7: Why don't I simply use delete[] item?
	for (int i = 0; i < NUM_ITEMS; ++i) {
		delete item[i];
	}

	return 0;
}