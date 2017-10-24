#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	char buf[100];
	int n;
	if((n=readlink("ep",buf,sizeof(buf)))==-1){
		perror("readlink");
		return -1;
	}
	buf[n]=0;//'\0'
	puts(buf);
	unlink("ep");
}
