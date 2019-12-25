int main(){

    int ssock, csock;

    int clen;

    struct sockaddr_in server_addr, client_addr;

    char buf[MAXBUF];

    int otp;

 

    if((ssock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){

        perror("socket error : ");

        exit(1);

    }

 

    memset(&server_addr,0,sizeof(server_addr));

    server_addr.sin_family = PF_INET;

    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    server_addr.sin_port = htons(3318);

 

    if(bind(ssock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){

        perror("bind error : ");

        exit(1);

    }

 

    if(listen(ssock, 8) < 0){

        perror("listen error : ");

        exit(1);

    }

    while(1){

        csock = accept(ssock, (struct sockaddr*)&client_addr, &clen);

 

        if(read(csock,buf,MAXBUF) <= 0){

            perror("read error : ");

            exit(1);

        }

        printf("%s\n", buf);

        sprintf(buf, "%d", otp);

        if(write(csock,buf,MAXBUF) <= 0){

            perror("write error : ");

            exit(1);

        }

        close(csock);

    }

    return 0;

}