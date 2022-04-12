//ThreadFuture.cpp - main program to demonstrate a promise and a future

#include <iostream>
#include <thread>
#include <future>
#include <windows.h>

void task(std::promise<double>& p) {//solves the race condition
    std::cout << "task:" << std::endl;
    Sleep(5000);
    p.set_value(12.34);//The future value can be set at any point in the task
	Sleep(5000);
	std::cout << "task: END" << std::endl;
}

int main() {
    std::promise<double> p;
    std::future<double> f = p.get_future();
    std::thread t(task, std::ref(p));
    std::cout << "Value = " << f.get() << std::endl;
    t.join();
}
