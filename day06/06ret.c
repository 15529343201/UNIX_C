#include<stdio.h>
#include<unistd.h>

int main()
{
	if(fork()==0){//子进程
		fork();
		printf("子进程%d,它的父进程%d\n",getpid(),getppid());
	}
	else{//父进程
		printf("父进程%d,它的父进程%d\n",getpid(),getppid());
		sleep(1);
	}
	puts("hello");//父子进程都会执行到这里
}
