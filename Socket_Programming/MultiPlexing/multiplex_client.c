#define MAXBUF  256

 

int main(){

    int ssock;

    int clen, num = 0;

    struct sockaddr_in server_addr;

    char buf[MAXBUF];

 

    if ((ssock = socket(AF_INET, SOCK_STREAM, 0)) < 0){

        perror("socket error : ");

        exit(1);

    }

 

 

    clen = sizeof(server_addr);

 

    memset(&server_addr,0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;

    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    server_addr.sin_port = htons(6888);

 

    if (connect(ssock, (struct sockaddr*)&server_addr, clen) < 0) {

        perror("connect error :");

        exit(1);

    }

 

    while(1){

 

        sprintf(buf, "I miss you already!");

 

        if (write(ssock, buf, MAXBUF) <= 0){

            perror("write error : ");

            exit(1);

        }

 

 

        if (read(ssock, buf, MAXBUF) <= 0){

            perror("read error : ");

            exit(1);

        }

 

        printf("\nread : %s\n", buf);

        sleep(1);

    }

    close(ssock);

 

    return 0;

}