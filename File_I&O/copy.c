#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

#define BUFSIZE 512

void main(int argc,char *argv[]){
		char buffer[BUFSIZE];
		int current;
		int newFile;
		ssize_t nread;
		long total = 0;

		if((current = open(argv[1],O_RDONLY))== -1 || (newFile = open(argv[2], O_RDWR | O_CREAT,S_IRUSR | S_IWUSR)) == -1){
			exit(1);
		}
		while((nread = read(current,buffer,BUFSIZE)) > 0){
				total += nread;
				if(nread < BUFSIZE){
						if((write(newFile,buffer,nread)) == -1){
								printf("Write Error\n");
								exit(1);
						}
				}
						else{
								if((write(newFile,buffer,BUFSIZE)) == -1){
										printf("Write Error\n");
										exit(1);
								}
						}
						
				}
				close(current);
				close(newFile);
				exit(0);
		}
		
