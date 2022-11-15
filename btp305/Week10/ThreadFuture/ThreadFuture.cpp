//ThreadFuture.cpp - main program to demonstrate a promise and a future

#include <iostream>
#include <thread>//std::thread
#include <future>//std::promise, std::future
#include <windows.h>//Sleep()

void task(std::promise<double>& p) {//solves the race condition
    std::cout << "task: Begin" << std::endl;
    Sleep(5000);
    p.set_value(12.34);//can be set at any point in the thread
    std::cout << "task: Middle" << std::endl;
    Sleep(5000);
    std::cout << "task: End" << std::endl;
}

int main() {
    std::promise<double> p;
    std::future<double> f = p.get_future();
    std::thread t(task, std::ref(p));
    std::cout << "Waiting..." << std::endl;
    Sleep(200);
    std::cout << "Waiting..." << std::endl;
    Sleep(200);
    std::cout << "Waiting..." << std::endl;
    Sleep(200);
    std::cout << "Waiting..." << std::endl;
    Sleep(200);
    std::cout << "Waiting..." << std::endl;
    Sleep(200);

    std::cout << "Value = " << f.get() << std::endl;

    std::cout << "Waiting..." << std::endl;
    Sleep(200);
    std::cout << "Waiting..." << std::endl;
    Sleep(200);
    std::cout << "Waiting..." << std::endl;
    Sleep(200);
    std::cout << "Waiting..." << std::endl;
    Sleep(200);
    std::cout << "Waiting..." << std::endl;
    Sleep(200);
    t.join();
}
