//ThreadLambda.cpp - main function to demonstrate lambda's with threads

#include <iostream>
#include <thread>
#include <vector>
#include <windows.h>

const int NT = 10;

int main() {
	// create a vector of threads
	std::vector<std::thread> threads;

	// launch the execution of each thread
	for (int i = 0; i < NT; i++) {
		int j = i;
		threads.push_back(std::thread([&]() {//pass by reference
			j = j * 10;
			for (int k = 0; k < 100; ++k) {//takes 10 seconds to complete
				std::cout << i << " Thread id = " << std::this_thread::get_id() << std::endl;
				std::cout.flush();
				Sleep(100);
			}
			}));
		Sleep(1000);//only waiting 1 second to start the next thread
		std::cout << "The thread has changed j from " << i << " to " << j << std::endl << std::endl;
	}

	// synchronize their execution here
	for (auto& thread : threads)
		thread.join();
}
