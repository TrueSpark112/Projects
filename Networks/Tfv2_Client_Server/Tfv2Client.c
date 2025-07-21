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
#include<sys/select.h>

#define BUFFSIZE 10
#define PORT 8080

//TO COMPILE THIS CODE TYPE ./UDPCLIENT 127.0.0.1 dst.dat


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


int main(int argc, char* argv[]){

    if (argc<3){
        printf("To use this type: ./UDPclient 127.0.0.1 src.dat");
        exit(1);
    }
    struct packet pOut, pIn;
    int sockfd;
    int ackNum =0;
    int ackBack;
    

    //char sbuf[BUFFSIZE];
    struct sockaddr_in servAddr;
    FILE *inFd;
    char* inputFileName = argv[2];

    //host = (struct hostent *)gethostbyname("localhost");
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Failure to setup an endpoint socket");
        exit(1);    
    }
    servAddr.sin_family = AF_INET;
    
    servAddr.sin_port = htons(PORT);
    //char* servIP="127.0.0.1";
    char* servIP=argv[1];
    servAddr.sin_addr.s_addr = inet_addr(servIP);


    inFd =fopen(inputFileName,"r");
    if(inFd<0){
        perror("Couldn't open file");
        fclose(inFd);
        exit(0);
    }
    int continueReading=1;
    //Send file to server
    while(!feof(inFd)){
        sendto(sockfd,&pOut,sizeof(struct packet),0,(struct sockaddr *)&servAddr, sizeof(servAddr));
        if (continueReading!=0){
            int n = fread(pOut.sbuf,1,BUFFSIZE,inFd);
        }
       
        pOut.h.seq_ack=ackNum;
        pOut.h.len=BUFFSIZE;
        pOut.h.checksum = 0;
         char *ptr = (char *)&pOut.sbuf;
         char *end = ptr + sizeof(pOut.sbuf);
         while (ptr < end){
            pOut.h.checksum ^= *ptr++;
        }
    
        //Wait for ACK
            // local variables needed
        struct timeval tv; // timer
        int rv; // select returned value
        // set up reads file descriptor at the beginning of the function to be checked for being ready to read
        fd_set readfds;
        fcntl (sockfd, F_SETFL, O_NONBLOCK);
        // start before calling select
        FD_ZERO (&readfds); //initializes readfds to have zero bits
        FD_SET (sockfd, &readfds); //sets readfds bit
        // set the timer
        tv.tv_sec = 1;
        tv.tv_usec = 0;
        // call select (), which returns the number of ready descriptors contained in the bit masks.
        // if the time limit expires, select returns zero and set errno
        rv = select (sockfd + 1, &readfds, NULL, NULL, &tv);
        if (rv == 0)
        {
        // timeout, no data
        }
        else if (rv == 1)
        {
        //There is data to be received
        // recvfrom(sockfd,&pIn,sizeof(int),0,(struct sockaddr *)&servAddr, sizeof(servAddr));
        // if((pIn.h.seq_ack%2)!=(ackNum%2)){
        //     continueReading=1;
        //     ackNum++;
        // }
        // else{
        //     continueReading =0;
            
        // }
        }

       
        
    }
    printf("\nMission Accomplished: File sent successfully\n");
    fclose(inFd);
    close(sockfd);
    
    return 0;
}
