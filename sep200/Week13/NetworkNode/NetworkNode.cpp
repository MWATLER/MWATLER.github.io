//NetworkNode.cpp - function definitions for a network node

#include <fstream>
#include <string>//to_string()
#include <thread>
#include <windows.h>//Sleep()
#include "NetworkNode.h"

using namespace std;

NetworkNode::NetworkNode(std::string _name) {
	name = _name;
}

void NetworkNode::Run() {
	is_running = true;
	Mutex_Initialize();//mutexes are used to synchronize the access to shared resources

	const string outputFile = "Output.dat";
	thread tout(&NetworkNode::ProcessData, this, outputFile);

	vector<thread> threads;
	const int NUM = 10;
	for (int i = 1; i <= NUM; ++i) {
		threads.push_back(thread(&NetworkNode::ReceiveData, this, i));
		Sleep(1000);
	}

	tout.join();//Run() will not exit until NetworkNode::ProcessData has finished
	for (auto& thread : threads) {
		thread.join();//Run() will not exit until all NetworkNode::ReceiveData threads have finished
	}
}

void NetworkNode::Mutex_Initialize() {
	mutex = MUTEX_STATE::MUTEX_UNLOCKED;
}

void NetworkNode::Mutex_Lock() {
	while (mutex == MUTEX_STATE::MUTEX_LOCKED) Sleep(100);
	mutex = MUTEX_STATE::MUTEX_LOCKED;
}

void NetworkNode::Mutex_Unlock() {
	mutex = MUTEX_STATE::MUTEX_UNLOCKED;
}

void NetworkNode::ReceiveData(const int& source) {
	string fileName = "Input";
	fileName += to_string(source);
	fileName += ".dat";
#ifdef DEBUG
	Log("ReceiveData: " + fileName);
#endif
	ifstream fin(fileName);
	string inputData;
	while (is_running) {
		Mutex_Lock();//the mutex is shared among all threads
		getline(fin, inputData);
		if (inputData == "QUIT") is_running = false;
		else if (fin.peek() == EOF) fin.seekg(0, ios::beg);
		data.push(inputData);//push data on to our shared resource
		Mutex_Unlock();
#ifdef DEBUG
		Log(inputData);
#endif
		Sleep(1000);//slow things down
	}
	fin.close();
}

void NetworkNode::ProcessData(const string& fileName) {
#ifdef DEBUG
	Log("ProcessData: " + fileName);
#endif
	ofstream fout(fileName);
	if (fout.is_open()) {
		string outputData;
		while (is_running) {
			Mutex_Lock();//the mutex is shared among all threads
			while (data.size() > 0) {
				outputData = data.front();//gets data from the queue and processes it
				data.pop();
				outputData += '\n';
				fout << outputData;
#ifdef DEBUG
				Log(outputData);
#endif
			}
			Mutex_Unlock();
			Sleep(5000);//slow things down
		}
		fout.close();
	}
	else {
		cout << "Failed to open the output file" << endl;
	}
}
