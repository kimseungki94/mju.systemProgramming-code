#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

#define BUFSIZE 512

void main(){
		char buffer[BUFSIZE];
		int fd;
		ssize_t nread;
		long total = 0;

		if((fd = open("testfile", O_RDONLY)) == -1)
				exit(1);

		while((nread = read(fd,buffer,BUFSIZE)) > 0)
				total += nread;
		close(fd);

		printf("Number of characters in testfile : %ld\n",total);
		exit(0);
}
