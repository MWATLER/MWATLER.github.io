//msgClient.cpp - A client for multi-client text messages
//                The connection protocol is UDP.
//
// 20-Jan-22  M. Watler         Created.

#include <iostream>
#include <strsafe.h>
#include <winsock2.h>
#include <ws2tcpip.h>//inet_pton

#pragma comment(lib,"ws2_32.lib") //Winsock Library

using namespace std;

const int PORT=1153;
const char IP_ADDR[]="127.0.0.1";//Address of the server
const int BUF_LEN=4096;
bool is_running;
int clientNo;

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

int main(int argc, char *argv[])
{
    WSADATA wsa;
    SOCKET s;
    int ret, len;
    struct sockaddr_in myaddr;
    struct sockaddr_in servaddr;
    socklen_t addrlen = sizeof(servaddr);
    const int MYPORT_BASE=2000;
    int myport;

    if(argc!=2) {
        cout<<"usage: msgClient <clientNo>"<<endl;
        return -1;
    }

    if (!SetConsoleCtrlHandler((PHANDLER_ROUTINE)ConsoleHandler, TRUE)) {
        cout << "Unable to install handler!" << endl;
        return -2;
    }

    clientNo=atoi(argv[1]);
    myport=MYPORT_BASE+clientNo;

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        cout << "Failed. Error Code : " << WSAGetLastError() << endl;
        return -3;
    }

    //Create a socket
    if ((s = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
    {
        cout << "Could not create socket : " << WSAGetLastError() << endl;
        WSACleanup();
        return -4;
    }
    cout << "main: s:" << s << endl;

    //The client has to bind itself to an address
    memset((char *)&myaddr, 0, sizeof(myaddr));
    inet_pton(AF_INET, "127.0.0.1", &myaddr.sin_addr.s_addr);
    myaddr.sin_family = AF_INET;
    myaddr.sin_port = htons(myport);

    ret = bind(s, (struct sockaddr *)&myaddr, sizeof(myaddr));
    if(ret<0) {
        cout<<"Cannot bind the socket to the local address"<<endl;
        closesocket(s);
        WSACleanup();
        return -5;
    }

    memset((char *)&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    ret = inet_pton(AF_INET, IP_ADDR, &servaddr.sin_addr);
    if(ret==0) {
        cout<<"No such address"<<endl;
        closesocket(s);
        WSACleanup();
        return -6;
    }
    servaddr.sin_port = htons(PORT);

    DWORD tid;
    HANDLE tHandle;
    tHandle = CreateThread(
       NULL,     // default security attributes
       0,        // use default stack size  
       recv_func,// thread function name
       &s,       // argument to thread function 
       0,        // use default creation flags 
       &tid);    // returns the thread identifier 

    if(tHandle==NULL) {
        cout<<"Cannot create receive thread"<<endl;
        closesocket(s);
        WSACleanup();
        return -7;
    }

    is_running = true;
    char message[BUF_LEN];
    int messageNo=1;
    int destClient=1;
    while(is_running) {
        //message = src dst message
        len = sprintf_s(message, "%d %d Test message %d\n", clientNo, destClient, messageNo++)+1;
    	destClient = (destClient++)%12+1;//Wrap around at client 12
        ret = sendto(s, message, len, 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
	    Sleep(1);
    }

    cout<<"client:"<<clientNo<<" is quitting..."<<endl;
    WaitForSingleObject(tHandle, INFINITE);
    closesocket(s);
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

    while(is_running) {
        int len = recvfrom(sock, buf, BUF_LEN, 0, (struct sockaddr *)&recvaddr, &addrlen);
        if(len<0) Sleep(1);
        else {
            int srcMessage=atoi(&buf[0]);
            cout<<"client:"<<clientNo<<" srcMessage:"<<srcMessage<<" recvfrom:"<<buf;
        }
    }
    return 0;
}
