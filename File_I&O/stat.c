#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
	struct stat statbuf;

	if(argc < 2){
			printf("no file path\n");
			exit(1);
	}
	if(stat(argv[1],&statbuf) != -1){
		printf("inode number : %ld\n",statbuf.st_ino);
		printf("file mode number : %d\n",statbuf.st_mode);
		printf("file UserId : %d\n",statbuf.st_uid);
	}
	return 0;
}
