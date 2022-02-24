//MusicSequencerCommon.h - common file for the music sequencer

#ifndef _MUSICSEQUENCERCOMMON_H_
#define _MUSICSEQUENCERCOMMON_H_

const int MAX_SEQUENCER_DATA_SIZE = 8192;

//QUESTION 30: How would we disable debug in this computer program?
#define DEBUG
//QUESTION 31: What are __FILE__, __func__, and __LINE__?
#define Log(msg) std::cout<<__FILE__<<":"<<__func__<<":"<<__LINE__<<":"<<msg<<std::endl;

#include "CenterBackSpeaker.h"
#include "LeftSpeaker.h"
#include "RightSpeaker.h"
#include "CenterFrontSpeaker.h"

//QUESTION 32: What type of polymorphism is this?
//QUESTION 33: What are the possible types for S in this computer program?
//QUESTION 34: What are the possible types for T in this computer program?
template<typename S, typename T> T* Transform(S& sequencer, const T* data, int len) {
	//QUESTION 35: Which Transform() function is called from the following line in main(): dataPtr = Transform(centerBackSpeaker, dataPtr, LOOP_COUNT * BassGuitar::DATA_CHUNK_LEN);
	return sequencer.Transform(data, len);
}

#endif// _MUSICSEQUENCERCOMMON_H_
