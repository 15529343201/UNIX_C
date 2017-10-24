#include<stdio.h>
#include<unistd.h>

int main()
{
	int i;
	if(fork()==0){//子进程
		for(i=0;i<10;i++){
			printf("进程id:%d,父进程%d\n",getpid(),getppid());
			sleep(1);
		}
	}
	else{//父进程
		for(i=0;i<3;i++){
			printf("我是%d\n",getpid());
			sleep(1);
		}
	}
}
