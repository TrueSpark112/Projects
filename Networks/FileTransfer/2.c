// COEN 146L : Lab 1 - template to use for file transfer (steps 3, 4, and 5)
// You need to adapt this template according to the requirements of each of the steps
//NAME:<Juan Torres>
//Date<Jan 7 2025>
//Lab1-task2 
//NAME:<Juan Torres>
//Date<Jan 7 2025>
//Lab1-task2 

#include <stdio.h>   // fprintf(), fread(), fwrite(), fopen(), fclose()
#include <stdlib.h>  // malloc(), free()
#include <pthread.h> // pthread_create()
#include <unistd.h>  // read(), write()
#include <fcntl.h>   // open(), close()
#include <errno.h>   // errno
#include <time.h>    // clock()
#include <sys/mman.h> // mmap()

#define BUF_SIZE 2048 //buffer size



// copies a files form src_filename to dst_filename using syscalls open(), read(), write(), close()
int syscall_copy(char* src_filename, char* dst_filename)  {
	int src_fd,dst_fd;
	src_fd = open(src_filename, O_RDONLY);	// opens a file for reading
	if (src_fd < 0) { // open() error checking
		fprintf(stderr, "unable to open %s for reading: %i\n", src_filename, errno);
		close(src_fd);
		exit(0);
	}
	// O_WRONLY - write only
	// O_CREAT - create file if it doesn't exist
	// O_TRUNC - truncates file to length 0 if it already exists (deletes existing file)
	// opens a file for writing; erases old file/creates a new file
	dst_fd = open(dst_filename, O_WRONLY | O_CREAT | O_TRUNC);	
	if (dst_fd < 0) { // open() error checking
		fprintf(stderr, "unable to open/create %s for writing: %i\n", dst_filename, errno);
		close(dst_fd);
		exit(0);
	}


	// read/ write loop
	//void* buf = malloc((size_t)BUF_SIZE);   // allocate a buffer to store read data
	int buf[BUF_SIZE];
	// reads up to BUF_SIZE bytes from src_filename
	read(src_fd,buf,sizeof(buf));
	// writes bytes_read to dst_filename
	write(dst_fd,buf,sizeof(buf)); 
	// closes src_fd file descriptor
	close(src_fd);
	// closes dst_fd file descriptor
	close(dst_fd);
	// frees memory used for buf
	//free(buf);
	return 0;
}


int main(int argc, char* argv[]) {
	if (argc != 3) {  // check correct usage
		fprintf(stderr, "usage: %s <src_filename> <dst_filename>\n", argv[0]);
		exit(1);
	}
	//get the source and destination files from the command line arguments
	char* inputFile= argv[1];
	char* outputFile = argv[2];
	
	//printf(outputFile,"\n");
	//call the check copy times function
	syscall_copy(inputFile, outputFile);
	return 0;
}
