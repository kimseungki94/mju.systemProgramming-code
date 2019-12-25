#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

#define FIFO_READ "/tmp/fifo_c"
#define FIFO_WRITE "/tmp/fifo_s"

int main(){
	int fp_w;
	int fp_r;

	int i=0;

	umask(0000);
	int sv1 = mkfifo(FIFO_READ,0666);
	if(sv1!=0)
	{
		perror("mkfifo failure");
	}
	if((fp_r = open(FIFO_READ,O_RDWR)) < 0){
		perror("open error : ");
		exit(0);
	}
	if((fp_w = open(FIFO_WRITE,O_RDWR)) < 0){
		perror("oopen error : ");
		exit(0);
	}

	while(read(fp_r,(void *)&i,sizeof(int))>0){
		printf("클라이언트로 부터 데이터 읽음 %d\n",i);
		i = i*2;
		write(fp_w,(void *)&i,sizeof(int));
	}
	exit(1);
}
