#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	pid_t who;
	printf("请输入对方进程id:");
	scanf("%d",&who);
	char buf[100];
	for(;;){
		printf("input:");
		scanf(" %[^\n]",buf);
		int fd;
		for(;;){
			fd=open("data",O_WRONLY|O_CREAT|O_EXCL,0666);
			if(fd>=0)
				break;
			puts("data文件已经存在");
			sleep(1);
		}
		write(fd,buf,strlen(buf));
		close(fd);
		kill(who,SIGUSR1);
	}
}
