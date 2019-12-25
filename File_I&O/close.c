#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main(){
		int filedes;
		char fname[] = "afile";
		// fd 받은거 close를 통해 재대로 닫음
		if ((filedes = open(fname,O_RDWR)) == -1){
				printf("%s cannot be opened.\n",fname);
		}
		close(filedes);
		return 0;
}

