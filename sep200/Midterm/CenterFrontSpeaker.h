//CenterFrontSpeaker.h - class definitions for the center back speaker

#ifndef _CENTERFRONTSPEAKER_H_
#define _CENTERFRONTSPEAKER_H_

#include "MusicSequencerCommon.h"

template<class T>
class CenterFrontSpeaker {
	T data[MAX_SEQUENCER_DATA_SIZE];
	T filter = 0xff;//0x1111 1111
public:
	T* Transform(const T* dataPtr, int len) {
		for (int i = 0; i < len && i < MAX_SEQUENCER_DATA_SIZE; ++i) {
			data[i] = dataPtr[i] & filter;
		}
		return data;
	}
};

#endif// _CENTERFRONTSPEAKER_H_