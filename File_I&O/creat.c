#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>

#define PERMS 0644

char *filename="newfile";

void main(){
		int fd;
		if((fd=open(filename,O_RDWR|O_CREAT,PERMS))==-1)
		{
				printf("cannot ceate %s\n", filename);
				exit(1);
		}
		exit(0);
}
