#include<sys/types.h> /*unlink.c */
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(){
		int fd,len;
		char buf[20];

		fd = open("tempfile",O_RDWR | O_CREAT | O_TRUNC, 0666);
		if(fd == -1) perror("open1 error"); 
		unlink("tempfile"); //목록에선 사라짐
		len = write(fd,"How are you?",12);
		if(len != 12) perror("write");
		lseek(fd, 0L,SEEK_SET);
		len = read(fd,buf,sizeof(buf));
		if(len < 0 ) perror("read");
		buf[len] = '\n';
		printf("%s\n",buf);
		close(fd);
		fd = open("tempfile",O_RDWR);
		if(fd == -1) perror("open2 error");
		close(fd);
		return 0;
}
