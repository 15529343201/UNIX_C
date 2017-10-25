#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
int cnt=0;
void func(int sig){
	printf("输入速度是每小时%d字\n",36*cnt);
	exit(0);
}
int main()
{
	signal(SIGALRM,func);
	printf("请输入每个字一行:\n");
	alarm(100);//定时100秒,到时会收到SIGALRM信号
	for(;;){
		char buf[100];
		scanf("%s",buf);
		++cnt;
	}
}

