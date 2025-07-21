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
#include <netinet/in.h>//
#include <strings.h>
#define _OPEN_SYS_SOCK_IPV6
#include <arpa/inet.h>

int BUFSIZE=2048;
//Functions


//Structures 
typedef struct{

}sockaddr;
//MAIN
int main(){
     //Reminders
    //127.0.0.1 (LOCALHOST)
    //port number 8080

    char *n;
    int server_fd,new_socket;
    char *buffer ;

    

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(3490);
    server_addr.sin_addr.s_addr = inet_addr(INADDR_ANY);

    //Creates a file descriptor for the server
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd  < 0){
        perror("cannot create socket");
        return 0;
    }
 

    int backlog;
 
    
    
    
    //Take in the information
    new_socket= connect(server_fd, (struct sockaddr *) &server_addr, (socklen_t )sizeof(&server_addr));
    bzero(buffer, 256);
    

  
    //Opens a file to write 
    int fd; // demo is a pointer of type FILE
    char buffer2[100]; // block of memory (ptr)
    char* filename = "lab3Client.dat";
    fd = open(filename, O_WRONLY | O_CREAT);// open lab3.dat in read mode
    if (fd< 0) { // fopen() error checking
	    fprintf(stderr, "unable to open %s for reading: %i\n",filename, errno);
	    exit(0);
    }
    int bytes_read;
	char* buf = (char*)malloc((size_t)BUFSIZE);   // allocate a buffer to store read data
	// reads up to BUF_SIZE bytes from src_filename
	while((bytes_read = read(new_socket,buf,BUFSIZE)) ){
		// writes bytes_read to dst_filename
		write(fd,buf,bytes_read); 
	}

    
    //Cleanup
    
    close(fd);
    free(buffer);
    return 0;
    return 0;
}