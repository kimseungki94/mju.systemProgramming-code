#include<unistd.h>
int main(){
	char *av[3];

	av[0] = "ls";
	av[1] = "-l";
	av[2] = (char *)0;

	execv("/bin/ls",av);
}
