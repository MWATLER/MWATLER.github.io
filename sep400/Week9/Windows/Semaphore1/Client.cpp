//Client.cpp - program to demonstrate semaphores as a synchronization mechanism between thread

#include <windows.h>
#include <iostream>
#include <process.h>

using namespace std;

HANDLE hSemaphore;
LONG cMax = 2;

void Test1(void*);
void Test2(void*);
void Test3(void*);

int main()
{
	hSemaphore = CreateSemaphore(
		NULL,
		cMax,
		cMax,
		NULL
	);

	if (!hSemaphore == NULL)
	{
		if (_beginthread(Test1, 1024, NULL) == -1)
			cout << "Error begin thread " << endl;
		if (_beginthread(Test2, 1024, NULL) == -1)
			cout << "Error begin thread " << endl;
		if (_beginthread(Test3, 1024, NULL) == -1)
			cout << "Error begin thread " << endl;
		Sleep(10000);
		CloseHandle(hSemaphore);
	}
	else
		cout << "error create semaphore" << endl;

	return 0;
}

void Test1(void*)
{
	cout << "Test1 Running" << endl;
	DWORD dwWaitResult = WAIT_FAILED;
	while (dwWaitResult != WAIT_OBJECT_0)
	{
		dwWaitResult = WaitForSingleObject(
			hSemaphore,
			1
		);
		cout << "Test 1 TIMEOUT" << endl;
	}
	Sleep(1000);
	if (ReleaseSemaphore(
		hSemaphore,
		1,
		NULL)
		)
		cout << " ReleaseSemaphore Ok Test1" << endl;
	_endthread();
}

void Test2(void*)
{
	cout << "Test2 Running" << endl;
	DWORD dwWaitResult = WAIT_FAILED;
	while (dwWaitResult != WAIT_OBJECT_0)
	{
		dwWaitResult = WaitForSingleObject(hSemaphore, 1);
		cout << "Test 2 TIMEOUT" << endl;
	}
	Sleep(1000);
	if (ReleaseSemaphore(hSemaphore, 1, NULL))
		cout << " ReleaseSemaphore Ok Test2" << endl;
	_endthread();
}

void Test3(void*)
{
	cout << "Test2 Running" << endl;
	DWORD dwWaitResult = WAIT_FAILED;
	while (dwWaitResult != WAIT_OBJECT_0)
	{
		dwWaitResult = WaitForSingleObject(hSemaphore, 1);
		cout << "Test 3 TIMEOUT" << endl;
	}
	if (ReleaseSemaphore(hSemaphore, 1, NULL))
		cout << " ReleaseSemaphore Ok Test3" << endl;
	_endthread();
}