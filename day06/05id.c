#include<unistd.h>
#include<stdio.h>

int main()
{
	int id=getpid();
	fork();
	int newid=getpid();
	if(newid==id){
		printf("父进程%d\n",id);
		for(;;){
			write(2,".",1);
			sleep(1);
		}
	}
	else{
		printf("子进程%d,父进程%d\n",newid,getppid());
		for(;;){
			write(2,"*",1);
		    sleep(1);
		}
	}
}
