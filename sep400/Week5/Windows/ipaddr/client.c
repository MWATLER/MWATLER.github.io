//client.c - Client code to demonstarte Windows sockets
//           Taken from: https://www.binarytides.com/winsock-socket-programming-tutorial/

#include<stdio.h>
#include<winsock2.h>
#include<ws2tcpip.h>//inet_pton

#pragma comment(lib,"ws2_32.lib") //Winsock Library
#define BUFSIZE 2000
#define PORT 1153

int main(int argc, char* argv[])
{
	WSADATA wsa;
	SOCKET s;
	struct sockaddr_in server;
	char message[BUFSIZE], server_reply[BUFSIZE];
	int recv_size;

	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		return 1;
	}

	printf("Initialised.\n");

	//Create a socket
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d", WSAGetLastError());
	}

	printf("Socket created.\n");


	inet_pton(AF_INET, "127.0.0.1", &server.sin_addr.s_addr);
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);

	//Connect to remote server
	if (connect(s, (struct sockaddr*)&server, sizeof(server)) < 0)
	{
		puts("connect error");
		return 1;
	}

	puts("Connected");

	//Receive a reply from the server
	if ((recv_size = recv(s, server_reply, BUFSIZE, 0)) == SOCKET_ERROR)
	{
		puts("recv failed");
	}
	else {
		//Add a NULL terminating character to make it a proper string before printing
		puts("Reply received:\n");
		server_reply[recv_size] = '\0';
		puts(server_reply);
	}

	//Send some data
	strcpy_s(message, BUFSIZE, "Hello server, from a client.");
	if (send(s, message, strlen(message), 0) < 0)
	{
		puts("Send failed");
	}
	else {
		puts("Data Sent\n");
	}

	closesocket(s);
	WSACleanup();

	return 0;
}