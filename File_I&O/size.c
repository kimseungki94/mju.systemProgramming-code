#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>

int main(){
		int fd;
		fd = open("test.txt",O_RDWR);
		if(fd  == -1)
			perror("no file");
		off_t size;
		size = lseek(fd,(off_t)0,SEEK_END);
		printf("The size of test.txt is %ld bytes\n",size);
		close(fd);
		return 0;
		}
