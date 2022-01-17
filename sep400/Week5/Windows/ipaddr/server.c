//server.c - Server code to demonstarte Windows sockets
//           Taken from: https://www.binarytides.com/winsock-socket-programming-tutorial/

/*
	Live Server on port 1153
*/
#include<io.h>
#include<stdio.h>
#include<winsock2.h>
#include<ws2tcpip.h>//inet_pton

#pragma comment(lib,"ws2_32.lib") //Winsock Library
#define BUFSIZE 2000
#define PORT 1153

int main(int argc, char* argv[])
{
	WSADATA wsa;
	SOCKET s, new_socket;
	struct sockaddr_in server, client;
	int c;
	int recv_size;
	char message[BUFSIZE], client_reply[BUFSIZE];

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

	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	inet_pton(AF_INET, "127.0.0.1", &server.sin_addr.s_addr);
	server.sin_port = htons(PORT);

	//Bind
	if (bind(s, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR)
	{
		printf("Bind failed with error code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}

	puts("Bind done");

	//Listen to incoming connections
	listen(s, 3);

	//Accept and incoming connection
	puts("Waiting for incoming connections...");

	c = sizeof(struct sockaddr_in);

	if ((new_socket = accept(s, (struct sockaddr*)&client, &c)) != INVALID_SOCKET)
	{
		puts("Connection accepted");
		//Send to the client
		strcpy_s(message, BUFSIZE, "Hello Client , I have received your connection.\n");
		if (send(new_socket, message, strlen(message), 0) < 0) {
			puts("Send failed");
		}
		else {
			puts("Data Sent\n");
		}

		//Receive a message from the client
		if ((recv_size = recv(new_socket, client_reply, BUFSIZE, 0)) == SOCKET_ERROR)
		{
			puts("recv failed");
		}
		else {
			puts("Reply received:\n");
			//Add a NULL terminating character to make it a proper string before printing
			client_reply[recv_size] = '\0';
			puts(client_reply);
		}
	} else {
		printf("accept failed with error code : %d", WSAGetLastError());
	}

	closesocket(s);
	WSACleanup();

	return 0;
}