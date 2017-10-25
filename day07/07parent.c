#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{//vfork创建子进程不克隆,需要紧接着执行exec函数 if(vfork()==0)也可以
	if(fork()==0){//子进程,加载child
		execl("./child","./child","飞飞",NULL);
		puts("加载./child失败");
		exit(-1);
	}
	else{//父进程,做自己的事情
		for(;;){
			write(1,".",1);
			sleep(1);
		}
	}



}
