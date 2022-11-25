//mCounter.cpp - main program for counting m's in a text file

#include <fstream>
#include <functional>//bind()
#include <future>
#include <iostream>
#include <thread>

using namespace std;

int counter(const char* dataChunk, const int len, const char searchChar) {
	int count = 0;
	for (int i = 0; i < len; ++i) {
		if (dataChunk[i] == searchChar) ++count;
	}
	return count;
}

int main() {
	const char fileName[] = "script.txt";
	const char theChar = 'm';
	ifstream input;
	input.open(fileName);
	if (!input) {
		cout << "Error opening the file " << fileName << endl;
		return -1;
	}

	//copy from file to memory
	input.seekg(0, ios::end);
	int size = (int)input.tellg();

	char* data = new char[size];

	input.seekg(ios::beg);//return to the beginning of the file
	for (int i = 0; i < size; ++i) {//read the data
		input >> data[i];
	}
	input.close();

	//using only the main thread
	int num = counter(data, size, theChar);
	cout << "The number of m's using only main is " << num << endl;

	//using four threads
	//Divide the data into four parts and call the encode thread
	//TEST: if size=19
	int begin1 = 0;//0
	int begin2 = size / 4;//19/4 = 4.75 -> 4
	int begin3 = size / 2;//19/2 = 9.5 -> 9
	int begin4 = 3 * size / 4;//19*3/4 = 57/4 = 14.25 -> 14
	
	// Bind and set up packaged tasks for futures/threads
	auto func = std::bind(counter, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
	std::packaged_task<int(const char*, const int, const char)> pt1(func);
	std::packaged_task<int(const char*, const int, const char)> pt2(func);
	std::packaged_task<int(const char*, const int, const char)> pt3(func);
	std::packaged_task<int(const char*, const int, const char)> pt4(func);

	std::vector<std::future<int>> fvec;
	fvec.push_back(pt1.get_future());
	fvec.push_back(pt2.get_future());
	fvec.push_back(pt3.get_future());
	fvec.push_back(pt4.get_future());

	std::vector<std::thread> tvec;
	tvec.push_back(std::thread(std::move(pt1), &data[begin1], begin2 - begin1, theChar));
	tvec.push_back(std::thread(std::move(pt2), &data[begin2], begin3 - begin2, theChar));
	tvec.push_back(std::thread(std::move(pt3), &data[begin3], begin4 - begin3, theChar));
	tvec.push_back(std::thread(std::move(pt4), &data[begin4], size - begin4, theChar));

	for (size_t i = 0; i < tvec.size(); ++i)
		tvec[i].join();

	num = 0;
	for (auto& x : fvec)
		num += x.get();

	cout << "The number of m's using four threads is " << num << endl;

	return 0;
}