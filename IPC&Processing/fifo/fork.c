#include<stdio.h>
#include<unistd.h>

int main(){
	int counter = 0;
	pid_t pid;
	printf("자식 프로세스 생성\n");
	pid = fork();

	switch(pid){
		case -1:
			{
				printf("자식 프로세스 생성 실패\n");
				return -1;
			}
		case 0:
			{
				printf("저는 자식 프로세스로 디스카운트하겠습니다.\n");
				while(1){
					printf("자식 : %d\n",counter--);
					sleep(1);
				}
			}
		default:
			{
				printf("저는 부모 프로세스로 카운트 하겠습니다.\n");
				printf("자식 프로세스의 pid는 %d입니다.\n",pid);
				while(1)
				{
					printf("부모 : %d\n",counter++);
					sleep(1);
				}
			}
	}
}
