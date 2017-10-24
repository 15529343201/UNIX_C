#include<stdio.h>
#include<unistd.h>

int main()
{
	uid_t uid=getuid();
	gid_t gid=getgid();
	pid_t pid=getpid();
	pid_t pp=getppid();
	char name[256];
	gethostname(name,256);
	printf("用户id:%d,组id:%d,进程id:%d,父进程id:%d,主机名:%s\n",uid,gid,pid,pp,name);
	pause();//等待遇到某个信号为止,比如Ctrl+C
}
