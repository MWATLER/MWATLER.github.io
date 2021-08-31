//NetworkNode.h - class declaration for a network node

#ifndef _NETWORKNODE_H_
#define _NETWORKNODE_H_

#define DEBUG
#define Log(msg) std::cout<<__func__<<":"<<__LINE__<<":"<<msg<<std::endl;

#include <iostream>
#include <queue>

class NetworkNode {
	enum class MUTEX_STATE {
		MUTEX_LOCKED,
		MUTEX_UNLOCKED
	};
	MUTEX_STATE mutex;
	std::string name;
	bool is_running;
	std::queue<std::string> data;

	void Mutex_Initialize();
	void Mutex_Lock();
	void Mutex_Unlock();
	void ReceiveData(const int& source);
	void ProcessData(const std::string& fileName);
public:
	NetworkNode(std::string _name);
	void Run();
};

#endif// _NETWORKNODE_H_
