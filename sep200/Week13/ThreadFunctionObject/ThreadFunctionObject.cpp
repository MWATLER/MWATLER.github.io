//ThreadFunctionObject.cpp - main program for demonstrating function objects with threads

#include <iostream>
#include <thread>
#include <vector>
#include <windows.h>

using namespace std;

const int NT = 10;

class Task {
public:
    Task() {}
    void operator()(int* i) {//Pass by address. This thread can change the value
                             //of the parameter passed by the calling function
        cout << *i << " Thread id = " << this_thread::get_id() << endl;

        //change i here
        *i = *i * 10;
    }
};

int main() {
    // create a vector of not-joinable threads
    std::vector<std::thread> threads;

    // launch execution of each thread
    for (int i = 0; i < NT; i++) {
        int j = i;
        threads.push_back(std::thread(Task(), &j));
        Sleep(1000);//race condition - give the thread a chance to start up.
        cout << "The thread changed j from " << i << " to " << j << endl << endl;
    }

    // synchronize their execution here
    for (auto& thread : threads)
        thread.join();

	return 0;
}
