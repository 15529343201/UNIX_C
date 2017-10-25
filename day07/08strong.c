#include<signal.h>
#include<stdio.h>
#include<unistd.h>

//信号处理函数
void func(int sig){//sig为当前处理的信号
	switch(sig){
		case SIGINT:
			puts("我不怕Ctrl+c");
			break;
		case SIGTERM:
			puts("想杀我,没门");
			break;
		case SIGTSTP:
			puts("我是不会停滴");
			break;
	}
}

int main()
{
	signal(SIGINT,func);//登记Ctrl+c信号的处理
	signal(SIGTERM,func);//登记kill的处理
	signal(SIGTSTP,func);//登记ctrl+z信号的处理
	printf("pid=%d\n",getpid());//显示进程id
	for(;;){//反复每10秒打印一个点
		write(STDERR_FILENO,".",1);
		sleep(10);
	}
}
//必杀信号:kill -KILL 进程id
