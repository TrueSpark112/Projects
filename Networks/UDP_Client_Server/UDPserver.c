//Name: <Juan Alfredo Torres Molina>
//* Date: <Jan 28 2025> (the day you have lab)
//* Title: Lab4 - Part 1
//* Description: This program ... <simulates a UDP server>

#include <stdio.h>   // fprintf(), fread(), fwrite(), fopen(), fclose()
#include <stdlib.h>  // malloc(), free()
#include <pthread.h> // pthread_create()
#include <unistd.h>  // read(), write()
#include <fcntl.h>   // open(), close()
#include <errno.h>   // errno
#include <time.h>    // clock()
#include <sys/mman.h> // mmap()
#include <sys/socket.h> //socket()
#include <netinet/in.h>
#include <strings.h>
#define _OPEN_SYS_SOCK_IPV6
#include <arpa/inet.h>

int main(){

    char rbuf[1024];
    int sockfd;
    struct sockaddr_in servAddr, clienAddr;
    socklen_t addrLen = sizeof(struct sockaddr);
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("Failure to setup an endpoint socket");
    exit(1);
    }
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(5000); //Port 5000 is assigned
    char* servIP = "127.0.0.1";
    servAddr.sin_addr.s_addr = inet_addr(servIP); //Local IP address if ((bind(sockfd,
    bind(sockfd,(struct sockaddr *)&servAddr,addrLen);

    if (((struct sockaddr *)&servAddr, sizeof(struct sockaddr)) < 0){
        perror("Failure to bind server address to the endpoint socket");
        exit(1);
    }
    while (1){
        printf("Server waiting for messages from client: \n");
        int nr = recvfrom(sockfd, rbuf, 1024, 0, (struct sockaddr *)&clienAddr,
        &addrLen);
        rbuf[nr] = '\0';
        printf("Client with IP: %s and Port: %d sent message: %s\n",
        inet_ntoa(clienAddr.sin_addr),ntohs(clienAddr.sin_port), rbuf);
    }
    return 0;



        return 0;
}