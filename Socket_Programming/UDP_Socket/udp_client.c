#define MAXBUF 256

 

int main(){

    int ssock;

    int clen;

    struct sockaddr_in client_addr, server_addr;

    char buf[MAXBUF];

 

    if((ssock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0){

        perror("socket error : ");

        exit(1);

    }

 

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;

    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    server_addr.sin_port = htons(3317);

 

    //recvfrom(ssock, (void*)buf, MAXBUF,0,(struct sockaddr*)&server_addr,sizeof(server_addr));

    printf("Please enter school id : ");

    scanf("%s", buf);

    sendto(ssock, (void*)buf, MAXBUF,0,(struct sockaddr*)&server_addr, sizeof(server_addr));

    recvfrom(ssock,(void*)buf, MAXBUF,0,(struct sockaddr*)&client_addr, &clen);

    printf("%s\n",buf);

    close(ssock);

    return 0;

}