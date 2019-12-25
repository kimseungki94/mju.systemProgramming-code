#include<unistd.h>
#include<stdlib.h>
int main(){
		if((write(1,"Welcome to System Programming",27)) != 27)
				//문장길이 27까지만 출력
				// 버퍼에 있는 내용이 27보다 작더라도 메모리 공간에서 27까지 읽어서 사용할 수 있는 환경이라면 27번째 문장까지 출력
			write(2, "A write error has occurred on file descriptor 1\n",47);
		exit(0);
}
