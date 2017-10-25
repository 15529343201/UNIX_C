#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int fd=open("children",O_RDONLY);
	if(fd==-1){
		puts("没有捣乱的子进程");
		return 0;
	}
	char buf[100];
	pid_t cid;
	while(read(fd,&cid,sizeof(cid))==sizeof(cid)){//读取一个进程id
		sprintf(buf,"kill %d 2>/dev/null",cid);
		system(buf);
	}
	close(fd);
	unlink("children");
}
