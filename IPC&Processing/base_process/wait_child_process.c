#include<stdio.h>
#include<unistd.h>
#include<wait.h>
#include<stdlib.h>
#include<sys/types.h>
int main(){
	pid_t pid[2];
	pid_t pid_child[2];
	int status[2];
	int sum =0;
	int multi = 1;
	int counter = 1;

	pid[0] = fork();
	switch(pid[0]){
		case 0:
			printf("자식 프로세스 1 실행 \n");
			while(counter<6){
				sum += counter;
				printf("자식1 실행 : %d\n",sum);
				counter++;
				sleep(1);
			}
			return sum;
		default:
			pid[1] = fork();
			switch(pid[1]){
				case 0:
					printf("자식 프로세스 2 실행 \n");
					while(counter<6){
						multi *= counter;
						printf("자식 2 실행 : %d\n",multi);
						counter++;
						sleep(1);
					}
					return multi;
				default:

					for(int i=0;i<2;i++){
						waitpid(pid[i],&status[i],0);
					}
					printf("자식1 pid는 %d이고 자식2 pid는 %d입니다.\n",pid[0],pid[1]);
					pid_child[0] = WEXITSTATUS(status[0]);
					pid_child[1] = WEXITSTATUS(status[1]);
					printf("자식의 합은 %d입니다.\n",pid_child[0]+pid_child[1]);
					printf("부모 프로세스 실행\n");
			}


	}
}
