#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
void func(int sig){//一个信号可能有多个子进程结束
	int info;
	pid_t cid;
	while((cid=waitpid(-1,&info,WNOHANG))>0)//大于0确实有子进程结束,-0没有子进程结束,-1出错
	printf("%d结束,返回%d\n",cid,WEXITSTATUS(info));
}
int main()
{
	int i;
	system("clear");
	signal(SIGCHLD,func);
	for(i=0;i<10;i++){//产生10个子进程
		if(fork()==0){//子进程
			int j;
			char c='A'+i;
			for(j=0;j<20;j++){
				write(2,&c,1);
				sleep(1);
			}
			exit(c);
		}
	}
	//父进程
	for(;;){
		sleep(100);
	}
}
