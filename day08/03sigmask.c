#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main()
{
	sigset_t newset,oldset;
	sigemptyset(&newset);
	sigaddset(&newset,SIGINT);
	sigaddset(&newset,SIGTERM);
	sigprocmask(SIG_BLOCK,&newset,&oldset);//设置屏蔽
	puts("睡眠中,请勿打扰");
	sleep(10);
	puts("睡醒了");
	sigset_t temp;
	sigpending(&temp);
	puts(sigismember(&temp,SIGINT)?"sigint":"noint");
	puts(sigismember(&temp,SIGTERM)?"sigterm":"noterm");

	sigprocmask(SIG_SETMASK,&oldset,NULL);//恢复原样
	puts("没有信号来过");
	return 0;
}
