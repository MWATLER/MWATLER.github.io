#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
//#define SERVER "192.168.1.104"
#define SERVER "192.168.239.131"
#define PORT 8080

int main() {
   struct addrinfo *ailist;
   struct sockaddr_in *sinp;
   int sockfd, port = PORT, result, fd;
   char message[BUFSIZ], username[11];
   char maze[15][35]; /* maze array */
   socklen_t len = sizeof(struct sockaddr_in);
   fd_set readfds, testfds;

   printf("\n*** Client program starting (enter \"quit\" to stop): \n");
   printf("\n*** Enter user name (up to 10 characters): ");
   fflush(stdout);
   fgets(message, BUFSIZ, stdin);
   message[strlen(message) - 1] = '\0';
   strncpy(username, message, 10);
   username[10] = '\0';
   fflush(stdout);

   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   getaddrinfo(SERVER, NULL, NULL, &ailist);
   sinp = (struct sockaddr_in *)ailist->ai_addr;
   sinp->sin_port = htons(port);
   connect(sockfd, (struct sockaddr *)sinp, len); /* connect to server and */
   write(sockfd, username, strlen(username));     /* send it your username */

   /* Initialize a file descriptor set */
   FD_ZERO(&readfds);
   FD_SET(sockfd, &readfds);
   FD_SET(0, &readfds);  /* Add keyboard to file descriptor set */

   /* Now wait for messages from the server or keyboard */
   while (1) {
      testfds = readfds;
      select(FD_SETSIZE, &testfds, NULL, NULL, NULL);
      /* If there is activity, find which descriptor it's on using FD_ISSET */
      for (fd = 0; fd < 4; fd++) {
         if (FD_ISSET(fd, &testfds)) {
            if (fd == 0)  {  /* Process keyboard activity */
               fgets(message, BUFSIZ, stdin);
               if (strcmp(message, "quit\n") == 0) {
                  close(sockfd);
                  exit(EXIT_SUCCESS);
               } else
                  write(sockfd, message, strlen(message));
            } else { /* message comming from server, so read it */
               result = read(sockfd, message, BUFSIZ);
               message[result] = '\0';
               printf("%s", message);
            }
         }
      }
   }
}


