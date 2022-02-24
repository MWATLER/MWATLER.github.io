//CenterBackSpeaker.h - class definitions for the center back speaker

#ifndef _CENTERBACKSPEAKER_H_
#define _CENTERBACKSPEAKER_H_

#include "MusicSequencerCommon.h"

//QUESTION 17: What type is T in this computer program?
template<class T>
class CenterBackSpeaker {
	T data[MAX_SEQUENCER_DATA_SIZE];
	//QUESTION 18: Does there have to be an object of type CenterBackSpeaker for the variable filter to exist?
	const T filter = 0x3f;//0x0011 1111
public:
	//QUESTION 19: What type is Transform returning in this computer program?
	//QUESTION 20: Who calls Transform()?
	T* Transform(const T* dataPtr, int len) {
		//QUESTION 21: Is it possible for data[] to overflow?
		for (int i = 0; i < len && i<MAX_SEQUENCER_DATA_SIZE; ++i) {
			//QUESTION 22: What is the below line doing to the data?
			data[i] = dataPtr[i] & filter;
		}
		return data;
	}
};

#endif// _CENTERBACKSPEAKER_H_