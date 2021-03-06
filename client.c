#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>


#define MAX 80
#define PORT 3490
#define SA struct sockaddr


int main() {
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    } else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // connect the client socket to server socket
    if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) != 0) {
        printf("connection with the server failed...\n");
        exit(0);
    } else
        printf("connected to the server..\n");


    char serverMsg[1024];
    for (int i = 0; i < 5; ++i) {
        if (recv(sockfd, serverMsg, sizeof(serverMsg), 0) > 0) {
            serverMsg[1023] = '\0';
            printf("%s\n", serverMsg);
        }
    }


}