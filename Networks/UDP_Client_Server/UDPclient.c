//Name: <Juan Alfredo Torres Molina>
//* Date: <Jan 28 2025> (the day you have lab)
//* Title: Lab4 - Part 1
//* Description: This program ... <simulates a UDP client>

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
#include <string.h>
#include <netdb.h>//gethostbyname
#define _OPEN_SYS_SOCK_IPV6
#include <arpa/inet.h>


int main(){
    int sockfd;
    char sbuf[1024];
    struct sockaddr_in servAddr;
    struct hostent *host;
    host = (struct hostent *)gethostbyname("localhost");
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Failure to setup an endpoint socket");
        exit(1);    
    }
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(5000);
    char* servIP="127.0.0.1";
    servAddr.sin_addr.s_addr = inet_addr(servIP);
    while(1){
        printf("Client: Type a message to send to Server\n");
        scanf("%s", sbuf);
        sendto(sockfd, sbuf, strlen(sbuf), 0, (struct sockaddr *)&servAddr,sizeof(struct sockaddr));
    }
    return 0;
}
