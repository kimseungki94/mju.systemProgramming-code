#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<error.h>
#include<stdio.h>
#include<stdlib.h>
#define BUFSIZE 20
int main(int argc, char *argv[]){
		int fd;
		char buffer[BUFSIZE];

		if(argc != 2)
				printf("usage: a.out <pathname>\n");

		//모든 파일의 접근을 OK한다는 것
		if(access(argv[1], F_OK) <0){
				fd = creat(argv[1],S_IWUSR | S_IRUSR);
				write(fd,"hello world",12);
		}else{
			// 파일이 재대로 creat가 안될시 예외처리
				if((fd = open(argv[1],O_RDWR | O_CREAT)) == -1){
					printf("file not open");
					exit(1);
				} else{
					//read write를 통한 buffer에 파일에 있는 값 처리
					read(fd,buffer,20);
					write(1,buffer,20);
				}
				close(fd);
		}
				return 0;
}
