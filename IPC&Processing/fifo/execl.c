#include<stdio.h>
#include<unistd.h>

int main(){
	execl("/bin/ls","/bin/ls","/tmp",NULL);	
}
