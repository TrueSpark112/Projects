//Name: <Juan Alfredo Torres Molina>
//* Date: <Feb 11 2025> (the day you have lab)
//* Title: Lab5 - Part 1
//* Description: This program ... <simulates a UDP server> with checksums and acknowledgement numbers.

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

#define PORT 8080
#define BUFFSIZE 1024

// Structures for this lab
typedef struct header{
    int seq_ack;
    int len;
    int checksum;

};
typedef struct packet{
    char sbuf[BUFFSIZE];//data
    struct header h;
};


int main(){

    char rbuf[BUFFSIZE];
    FILE *fp;
    int sockfd;
    struct sockaddr_in servAddr, clienAddr;
    socklen_t addrLen = sizeof(struct sockaddr);
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("Failure to setup an endpoint socket");
    exit(1);
    }
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(PORT); //Port 8080 is assigned
    char* servIP = "10.0.0.1"; //If my code doesn't work uncomment this
    servAddr.sin_addr.s_addr = inet_addr(servIP); 
    //servAddr.sin_addr.s_addr=INADDR_ANY;
    bind(sockfd,(struct sockaddr *)&servAddr,addrLen);

    printf("\nServer waiting for file transfer from the client\n");
    if (((struct sockaddr *)&servAddr, sizeof(struct sockaddr)) < 0){
        perror("Failure to bind server address to the endpoint socket");
        exit(1);
    }
    fp =fopen("dst.dat","wb");
    if (fp==NULL){
        perror("Failed to create file for writing");
        close(sockfd);
        exit(1);
    }
    int n;
    struct packet pIn, pOut;
    int seqNum =0;
    while((n=recvfrom(sockfd,&pIn,sizeof(struct packet),0,(struct sockaddr *) &clienAddr,&addrLen))>0)
    {
        //Setup the ACK
        pOut.h.len=0;

        int checksumCheck = 0;
        char *ptr = (char *)&pIn.sbuf;
        char *end = ptr + sizeof(pIn.sbuf);
        while (ptr < end){
            checksumCheck ^= *ptr++;
        }
        if(((seqNum%2)==(pIn.h.seq_ack%2))&&checksumCheck==pIn.h.checksum){
            fwrite(rbuf,1,n,fp);
            if(n<BUFFSIZE){
                break;
            }
            seqNum++;
            pOut.h.seq_ack=seqNum;
            sendto(sockfd,&pOut,sizeof(struct packet),0,(struct sockaddr *)&servAddr, sizeof(servAddr));
            
        }
        else{
            pOut.h.seq_ack=seqNum;
            sendto(sockfd,&pOut,sizeof(struct packet),0,(struct sockaddr *)&servAddr, sizeof(servAddr));
        }
    }
    
    printf("File received on server end");
    //Cleanup
    fclose(fp);
    close(sockfd);


    return 0;
}