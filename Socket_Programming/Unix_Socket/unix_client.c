#include <sys/types.h>

#include <sys/socket.h>

#include <sys/un.h>

#include <stdio.h>

#include <string.h>

#include <unistd.h>

 

//typedef struct sockaddr addr;

 

 

 

//typedef struct sockaddr_un addr_un;

 

#define NAME "socket"

 

int main(){

    int sock, length, fromlen;

    struct sockaddr_un name;

    char *buf = "This is a message from the client";

 

    sock = socket(PF_UNIX, SOCK_DGRAM, 0);

 

    name.sun_family = PF_UNIX;

    strcpy(name.sun_path, NAME);

 

    bind(sock, (struct sockaddr*)&name, sizeof(name));

 

    sendto(sock, buf, strlen(buf)+1, 0, (struct sockaddr*)&name, sizeof(name));

 

    close(sock);

}