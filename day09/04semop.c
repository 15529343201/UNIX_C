#include<sys/ipc.h>
#include<sys/sem.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/wait.h>
int main()
{
   	int id=semget(0x8888,1,IPC_CREAT|0600);
	if(id==-1)
	{
			perror("semget");
			return -1;
	}
	semctl(id,0,SETVAL,5);
	int i;
	for(i=0;i<10;i++){
			if(fork()==0){//子进程
					struct sembuf sb;
					sb.sem_num=0;
					sb.sem_op=-1;
					sb.sem_flg=SEM_UNDO;
					while(semop(id,&sb,1)==-1){}
					srand(getpid());
					printf("%d进程开始工作\n",getpid());
					sleep(rand()%16+5);//工作5-20秒
					printf("%d进程工作完毕\n",getpid());
					sb.sem_op=+1;
					semop(id,&sb,1);
					exit(0);
			}
	}
	while(wait(NULL)!=-1);
	puts("全部子进程结束");
	semctl(id,0,IPC_RMID,NULL);
}

