#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<wait.h>
#define MAX 1024
int avg(int i,int j){
	int sum=0;
	int avg=0;
	for(int k=i;k<=j;k++){
		sum+=k;
	}
	avg = sum/(j-i+1);
	return avg;
}
static void show(){
	char buffer[MAX];
	printf("%d\n",getpid());
	getcwd(buffer,MAX);
	printf("%s\n",buffer);
}
int main(){
	pid_t pid[2];
	pid_t pid_child[2];
	int multi;
	int avg1,avg2;
	int status[2];
	int childvalue1,childvalue2;
	pid[0] = fork();
	switch(pid[0]){
		case 0:
			printf("자식 프로세스 1 실행 \n");
			avg1 = avg(1,10);
			return avg1;
		default:
			pid[1] = fork();
			switch(pid[1]){
				case 0:
					printf("자식 프로세스 2 실행 \n");
					avg2 = avg(50,60);
					return avg2;
				default:
					pid_child[0] = waitpid(pid[0],&status[0],0);
					pid_child[1] = waitpid(pid[1],&status[1],0);
					childvalue1=WEXITSTATUS(status[0]);
					childvalue2=WEXITSTATUS(status[1]);
						printf("부모 프로세스 실행 \n");
						printf("자식 1 : %d 자식 2 : %d\n",pid_child[0],pid_child[1]);
						printf("자식1 value : %d\n",childvalue1);
						printf("자식2 value : %d\n",childvalue2);
						atexit(show);
					}
			}
}
