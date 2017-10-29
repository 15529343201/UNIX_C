#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<pwd.h>

void func(int sig)
{//...
	getpwnam("root");
	//...
}
int main()
{
	signal(SIGINT,func);
	struct passwd* p=getpwnam("ubuntu");
	sleep(100);
	printf("uid=%d\n",p->pw_uid);
}
	
