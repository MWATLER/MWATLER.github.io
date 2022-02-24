//RightSpeaker.h - class definitions for the center back speaker

#ifndef _RIGHTSPEAKER_H_
#define _RIGHTSPEAKER_H_

#include "MusicSequencerCommon.h"

template<class T>
class RightSpeaker {
	T data[MAX_SEQUENCER_DATA_SIZE];
	const T filter = 0x0f;//0x0000 1111
public:
	T* Transform(const T* dataPtr, int len) {
		for (int i = 0; i < len && i < MAX_SEQUENCER_DATA_SIZE; ++i) {
			data[i] = dataPtr[i] & filter;
		}
		return data;
	}
};

#endif// _RIGHTSPEAKER_H_