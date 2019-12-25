int main(){

    int ssock;

    int clen;

    struct sockaddr_in server_addr;

    char buf[MAXBUF];

 

    if((ssock = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP)) < 0){

        perror("socket error : ");

        exit(1);

    }

 

    clen = sizeof(server_addr);

 

    memset(&server_addr,0,sizeof(server_addr));

    server_addr.sin_family = PF_INET;

    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    server_addr.sin_port = htons(3318);

 

    if(connect(ssock,(struct sockaddr*)&server_addr, clen) < 0){

        perror("connect error : ");

        exit(1);

    }

 

    memset(buf,0,MAXBUF);

 

    printf("Please enter School ID : ");

    scanf("%s", buf);

 

    if(write(ssock,buf,MAXBUF) <= 0){

        perror("write error : ");

        exit(1);

    }

 

    if(read(ssock,buf,MAXBUF) <= 0){

        perror("read error : ");

        exit(1);

    }

    close(ssock);

 

    printf("\nread : %s\n\n",buf);

    return 0;

}