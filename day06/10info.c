#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

void childprocess(){
	int i;
	printf("myid=%d\n",getpid());
	for(i=0;i<20;i++){
		write(STDOUT_FILENO,"*",1);
		usleep(1000*500);
	}
	printf("结束\n");
	exit(88);
}
int main()
{
	if(fork()==0){//子进程
		childprocess();
	}
	else{//父进程
		puts("等待子进程结束");
		int info;
		pid_t id=wait(&info);
		printf("%d结束\n",id);
		if(WIFEXITED(info)){
			printf("正常结束,返回%d\n",WEXITSTATUS(info));        }
		else
			printf("被信号终止\n");
	}
}
