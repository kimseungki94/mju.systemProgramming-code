#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>

int main(void){
		umask(0);
		if(creat("foo",S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) < 0)
				perror("foo");
		umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
		if(creat("bar",S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) < 0)
				perror("bar");
		return 0;
}
