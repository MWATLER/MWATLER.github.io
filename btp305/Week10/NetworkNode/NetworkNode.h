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
	MUTEX_STATE mutex;//protects the shared resource
	std::string name;//Blackberry2
	bool is_running;//set to true to start up, set to false to stop
	std::queue<std::string> data;//the shared resource

	void Mutex_Initialize();
	void Mutex_Lock();//lock the shared resource
	void Mutex_Unlock();//unlock the shared resource
	void ReceiveData(const int& source);//Runs in a thread
	void ProcessData(const std::string& fileName);//Runs in a thread
public:
	NetworkNode(std::string _name);
	void Run();
};

#endif// _NETWORKNODE_H_
