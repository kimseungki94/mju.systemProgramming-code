#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>
int main(){
	pid_t pid;
	pid = fork();
	int status;
	int fd,fd1;
	char buffer[1024];
	fd = open("myfile.txt",O_CREAT | O_RDWR,0666);
	write(fd,"kimseungki",10);
	switch(pid){
		case 0:
			write(fd,"6015546",8);
			exit(1);
		default:
			wait(&status);
			fd1 = open("myfile.txt",O_RDONLY,0666);
			char buffer[20];
			read(fd1,buffer,18);
			for(int i=0;i<=16;i++){
				printf("%c",buffer[i]);
			}
			printf("\n");
			close(fd);
			close(fd1);
			exit(1);

	}
}
