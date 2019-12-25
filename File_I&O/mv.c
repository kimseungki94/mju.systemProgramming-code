#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc,char* argv[])
{
		int fd;
		fd = open(argv[1],O_RDWR, 0666);
		
		if(argc <3){
			printf("./a.out currentName afterName\n");
		}
		if((fd = open(argv[1],O_RDWR,0666))== -1){
			perror("file not open");
			exit(1);
		}
		if(link(argv[1],argv[2]) == -1){
				perror("link");
				exit(1);
		}
		if((unlink(argv[1]) == -1)){
				perror("unlink");
				exit(1);
		}
		close(fd);
		return 0;
}
