//msgPump.cpp - The server for multi-client text messages
//              The connection protocol is UDP.
//
// 20-Jan-22  M. Watler         Created.

#include <iostream>
#include <queue>
#include <strsafe.h>
#include <winsock2.h>
#include <ws2tcpip.h>//inet_pton

#pragma comment(lib,"ws2_32.lib") //Winsock Library

using namespace std;

const int PORT = 1153;
const char IP_ADDR[] = "127.0.0.1";
const int BUF_LEN = 4096;
bool is_running;

typedef struct clientIP {
	int clientNo;
	char ipAddr[32];
	int port;
} ClientIP;

typedef struct message {
	int len;
	char buf[BUF_LEN];
} Message;

queue<Message> messageQueue;

HANDLE lock_x;

ClientIP client[] = {//Each client is bound to one of the following addresses.
				 //The server is bound to 127.0.0.1:1153.
	{1,  "127.0.0.1", 2001},
	{2,  "127.0.0.1", 2002},
	{3,  "127.0.0.1", 2003},
	{4,  "127.0.0.1", 2004},
	{5,  "127.0.0.1", 2005},
	{6,  "127.0.0.1", 2006},
	{7,  "127.0.0.1", 2007},
	{8,  "127.0.0.1", 2008},
	{9,  "127.0.0.1", 2009},
	{10, "127.0.0.1", 2010},
	{11, "127.0.0.1", 2011},
	{12, "127.0.0.1", 2012},
	{13, "127.0.0.1", 2013},
	{14, "127.0.0.1", 2014},
	{15, "127.0.0.1", 2015},
	{16, "127.0.0.1", 2016},
};

DWORD WINAPI recv_func(LPVOID lpParam);

BOOL WINAPI ConsoleHandler(DWORD dwType)
{
	switch (dwType) {
	case CTRL_C_EVENT:
		cout << "Ctrl-C intercepted" << endl;
		is_running = false;
		break;
	default:
		cout << "unhandled event " << dwType << endl;
	}
	return TRUE;
}

int main(void)
{
	WSADATA wsa;
	SOCKET s;
	int ret;
	struct sockaddr_in myaddr;
	struct sockaddr_in destaddr;
	socklen_t addrlen = sizeof(destaddr);

	if (!SetConsoleCtrlHandler((PHANDLER_ROUTINE)ConsoleHandler, TRUE)) {
		cout << "Unable to install handler!" << endl;
		return -1;
	}

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		cout << "Failed. Error Code : " << WSAGetLastError() << endl;
		return -2;
	}

	//Create a socket
	if ((s = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
	{
		cout << "Could not create socket : " << WSAGetLastError() << endl;
		WSACleanup();
		return -3;
	}
	cout << "main: s:" << s << endl;

	//Make it non-blocking via an ioctl
	u_long nonBlocking = 1;
	ioctlsocket(s, FIONBIO, &nonBlocking);

	memset((char*)&myaddr, 0, sizeof(myaddr));
	myaddr.sin_family = AF_INET;
	ret = inet_pton(AF_INET, IP_ADDR, &myaddr.sin_addr);
	if (ret == 0) {
		cout << "No such address" << endl;
		closesocket(s);
		WSACleanup();
		return -4;
	}
	myaddr.sin_port = htons(PORT);

	//The server has to bind itself to an address
	memset((char*)&myaddr, 0, sizeof(myaddr));
	inet_pton(AF_INET, "127.0.0.1", &myaddr.sin_addr.s_addr);
	myaddr.sin_family = AF_INET;
	myaddr.sin_port = htons(PORT);

	ret = bind(s, (struct sockaddr*)&myaddr, sizeof(myaddr));
	if (ret < 0) {
		cout << "Cannot bind the socket to the local address" << endl;
		closesocket(s);
		WSACleanup();
		return -5;
	}

    //Create the mutex
	lock_x = CreateMutex(
		NULL,              // default security attributes
		FALSE,             // initially not owned
		NULL);             // unnamed mutex

	if (lock_x == NULL)
	{
		cout << "CreateMutex error: " << GetLastError() << endl;
		return -6;
	}

	is_running = true;
	DWORD tid;
	HANDLE tHandle;
	tHandle = CreateThread(
		NULL,     // default security attributes
		0,        // use default stack size  
		recv_func,// thread function name
		&s,       // argument to thread function 
		0,        // use default creation flags 
		&tid);    // returns the thread identifier 

	if (tHandle == NULL) {
		cout << "Cannot create receive thread" << endl;
		closesocket(s);
		WSACleanup();
		return -7;
	}

	while (is_running) {
		if (messageQueue.size() == 0) Sleep(1);
		else {
			//Lock the mutex
			DWORD dwWaitResult = WaitForSingleObject(
				lock_x,//handle to the mutex
				INFINITE);//no time-out interval
			Message tmpMsg = messageQueue.front();
			messageQueue.pop();
			//unlock the mutex
			ReleaseMutex(lock_x);
			int destClient = atoi(&tmpMsg.buf[1]);
			memset((char*)&destaddr, 0, sizeof(destaddr));
			destaddr.sin_family = AF_INET;
			ret = inet_pton(AF_INET, client[destClient - 1].ipAddr, &destaddr.sin_addr);
			if (ret == 0) {
				cout << "No such address" << endl;
			}
			destaddr.sin_port = htons(client[destClient - 1].port);
			ret = sendto(s, tmpMsg.buf, tmpMsg.len, 0, (struct sockaddr*)&destaddr, sizeof(destaddr));
		}
	}

	cout << "server is quitting..." << endl;
	WaitForSingleObject(tHandle, INFINITE);
	closesocket(s);
	CloseHandle(lock_x);
	WSACleanup();

	return 0;
}

DWORD WINAPI recv_func(LPVOID lpParam)
{
	SOCKET sock = *((SOCKET*)lpParam);
	char buf[BUF_LEN];
	struct sockaddr_in recvaddr;
	socklen_t addrlen = sizeof(recvaddr);

	cout << "recv_func: sock:" << sock << endl;

	while (is_running) {
		int len = recvfrom(sock, buf, BUF_LEN, 0, (struct sockaddr*)&recvaddr, &addrlen);
		if (len < 0) Sleep(1);
		else {
			Message tmpMsg;
			tmpMsg.len = len;
			strncpy_s(tmpMsg.buf, buf, len);
			DWORD dwWaitResult = WaitForSingleObject(
				lock_x,//handle to the mutex
				INFINITE);//no time-out interval
			messageQueue.push(tmpMsg);
			ReleaseMutex(lock_x);
		}
	}

	return 0;
}
