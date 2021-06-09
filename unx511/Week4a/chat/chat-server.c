#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define MAX_CLIENTS 3
#define PORT 8080

int main() {
   struct sockaddr_in server_address;
   int server_sockfd, client_sockfd, reuse = 1, fd, fd2, port = PORT, num_clients = 0, result;
   char kb_message[BUFSIZ];
   char message[BUFSIZ];  
   char client_message[BUFSIZ];
   char usernames[MAX_CLIENTS][11];
   socklen_t server_len = sizeof(server_address);
   fd_set readfds, testfds;

   server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
   setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int));
   server_address.sin_family = AF_INET;
   server_address.sin_addr.s_addr = htonl(INADDR_ANY);
   server_address.sin_port = htons(port);
   bind(server_sockfd, (struct sockaddr *)&server_address, server_len);
   listen(server_sockfd, 5);
  
   FD_ZERO(&readfds);
   FD_SET(server_sockfd, &readfds);
   FD_SET(STDIN_FILENO, &readfds); 
   while (1) {
      testfds = readfds;
      select(4 + MAX_CLIENTS, &testfds, NULL, NULL, NULL);
      for (fd = 0; fd < 4 + MAX_CLIENTS; fd++) {
         if (FD_ISSET(fd, &testfds)) {
            if (fd == server_sockfd) { /* new connection request */
               client_sockfd = accept(server_sockfd, NULL, NULL);
               result = read(client_sockfd, client_message, BUFSIZ);
               client_message[result] = '\0';
               if (num_clients < MAX_CLIENTS) {
                  FD_SET(client_sockfd, &readfds);
                  num_clients++;
                  strcpy(usernames[client_sockfd - 4], client_message);
                  printf("%s has connected\n", usernames[client_sockfd - 4]);
                  fflush(stdout);
                  sprintf(message, "Your ID is %2d\n", client_sockfd);
		  write(client_sockfd, message, strlen(message));
               } else {
                  sprintf(message, "Sorry, too many clients.  Try again later.\n");
                  write(client_sockfd, message, strlen(message));
                  close(client_sockfd);
               }
            } else if (fd == STDIN_FILENO) { /* keyboard activity */
               fgets(kb_message, BUFSIZ, stdin);
               if (strcmp(kb_message, "quit\n") == 0) {
                  sprintf(message, "Server is shutting down.\n");
                  for (fd2 = 4; fd2 < 4 + MAX_CLIENTS; fd2++) {
                     if (FD_ISSET(fd2, &readfds)) {
                        write(fd2, message, strlen(message));
                        close(fd2);
                     }
                  }
                  close(server_sockfd);
                  exit(EXIT_SUCCESS);
               } else {
                  sprintf(message, "Moderator: %s", kb_message);
                  for (fd2 = 4; fd2 < 4 + MAX_CLIENTS; fd2++)
                     if (FD_ISSET(fd2, &readfds))
                        write(fd2, message, strlen(message));
               }
            } else {  /* A client is messaging or leaving */
               if ((result = read(fd, client_message, BUFSIZ)) > 0) {
                  client_message[result] = '\0';
                  printf("%s: %s", usernames[fd - 4], client_message);
                  fflush(stdout);
                  sprintf(message, "%s: %s", usernames[fd - 4], client_message);
                  for (fd2 = 4; fd2 < 4 + MAX_CLIENTS; fd2++)
                     if (fd2 != fd && FD_ISSET(fd2, &readfds))
                        write(fd2, message, strlen(message));
               } else {
                  close(fd);
                  FD_CLR(fd, &readfds);
                  num_clients--;
                  printf("%s has disconnected\n", usernames[fd - 4]);
                  fflush(stdout);
               }
            }
         }
      }
   }
}



