#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<pwd.h>

int main()
{
	daemon(0,0);//把进程设置为服务进程(精灵)进程
	chdir(getpwuid(getuid())->pw_dir);//设置自己的主目录为当前目录
	char c='Z';
	for(;;){
		int fd=open("letter",O_RDWR|O_CREAT,0600);
		read(fd,&c,1);
		if(++c>'Z')
			c='A';
		lseek(fd,0,SEEK_SET);
		write(fd,&c,1);
		close(fd);
		sleep(1);
	}
}
