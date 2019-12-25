#include<sys/types.h>
#include<sys/stat.h>
#include<error.h>
#include<stdio.h>

int main(){
		struct stat statbuf;
		/* stat와 chmod를 통해 권한을 부여 rwx를 처리함 */
		if(stat("foo",&statbuf) <0)
				perror("stat(foo)");
		if(chmod("foo",(statbuf.st_mode & ~ S_IXGRP) | S_ISGID) <0)
				perror("chmod(foo)");
		if(chmod("bar",S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
				perror("chmod(bar)");
		return 0;
}
