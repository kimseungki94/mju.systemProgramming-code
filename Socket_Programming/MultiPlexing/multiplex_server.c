#include <stdio.h>

#include <unistd.h>

#include <stdlib.h>

#include <string.h>

#include <sys/socket.h>

#include <sys/types.h>

#include <sys/stat.h>

#include <arpa/inet.h>

 

#define MAXBUF  256

 

 

int main()

{

    int ssock, csock;

    int clen, data_len;

    int fd;

    pid_t pid;

    struct sockaddr_in client_addr, server_addr;

    fd_set read_fds, tmp_fds;

    char buf[MAXBUF] = "I like you!";

 

    /* 소켓 생성 */

    if ((ssock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {

        perror("socket error : ");

        exit(1);

    }

 

    /* 서버 옵션 지정 */

    clen = sizeof(client_addr);

 

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family     = AF_INET;

    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    server_addr.sin_port     = htons(3317);

 

 

/* 서버 옵션 설정 */

    if (bind(ssock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {

        perror("bind error : ");

        exit(1);

    }  

                

/* 연결 수신 대기 */

    if (listen(ssock, 5) < 0) {

        perror("listen error : ");

        exit(1);

    }

 

    /* 서버 소켓 파일 디스크립터 설정 */

    FD_ZERO(&read_fds);

    FD_SET(ssock, &read_fds);

 

    while(1) {

 

        tmp_fds = read_fds;

        

        if (select(FD_SETSIZE, &tmp_fds, (fd_set *)0, (fd_set *)0, 

                                                 (struct timeval *)0) < 1) {

            perror("select error : ");

            exit(1);

        }

  

        for(fd=0; fd<FD_SETSIZE; fd++)    // 파일 디스크립터를 하나씩 확인

        {

            if (FD_ISSET(fd, &tmp_fds)) {

                /* 파일 디스크립터 이벤트가 발생했을 경우 */

                if (fd == ssock) {

                    /* 이벤트 발생 파일 디스크립터가 서버 소켓인 경우 */

 

                    /* 연결 처리 */

                    csock = accept(ssock, (struct sockaddr *)&client_addr, &clen);

  /* 파일 디스크립터에 추가 */

                    FD_SET(csock, &read_fds);

                    printf("새로운 클라이언트 %d번 파일 디스크립터 접속\n", csock);

                } else {

                    /* 이벤트 발생 파일 디스크립터가 클라이언트 소켓인 경우 */

 

                    /* 해당 파일 디스크립터 소켓으로부터 데이터를 읽는다 */

                    data_len = read(fd, buf, MAXBUF);

                    if (data_len > 0) {

                        /* 해당 파일 디스크립터 소켓에 데이터를 쓴다 */

                        write(fd, buf, MAXBUF);

                    } else if (data_len == 0){

                        /* 데이터가 읽히지 않은 경우는 해당 소켓을 종료한다 */

                        close(fd);

                        FD_CLR(fd, &read_fds);

 

                        printf("클라이언트 %d번 파일 디스크립터 접속 해제\n", fd);

                    } else if (data_len < 0) {

                        /* 에러가 리턴된 경우 에러 처리 */

                        perror("read error : ");

                        exit(1);

                    }

                }

            }

        }

    }

 

    return 0;

}