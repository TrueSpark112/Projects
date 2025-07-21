//Name: <Juan Alfredo Torres Molina>
//* Date: <Jan 21 2025> (the day you have lab)
//* Title: Lab3 - Part 1
//* Description: This program ... <simulates a TCP server that accepts a client connection for one file transfer.>
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
    int sockfd, nr;
    char sbuf[1000000000], rbuf[1000000000];
    struct sockaddr_in servAddr;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("Failure to setup an endpoint socket");
    exit(1);
    }
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(5000);
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (connect(sockfd, (struct sockaddr *)&servAddr, sizeof(struct sockaddr))){
    perror("Failure to connect to the server");
    exit(1);
    }

    //scanf("%s", sbuf);
    read(sockfd, rbuf, 1000000000);
    int bytes_read;
    while(( bytes_read = read(sockfd,rbuf,1000000000)) ){
		// writes bytes_read to dst_filename
		write(connection_fd,buf,bytes_read); 
	}
    
    printf("Server: sent message: %s\n", rbuf);
    
    close(sockfd);
    return 0;
}