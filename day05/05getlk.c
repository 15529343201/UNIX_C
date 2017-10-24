#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd=open("01excl.c",O_RDWR);
	if(fd<0){
		perror("open");
		return -1;
	}
	struct flock pos;
	pos.l_type=F_WRLCK;
	pos.l_whence=SEEK_SET;
	pos.l_start=19;
	pos.l_len=17;
	//pos.l_pid=-1;
	if(fcntl(fd,F_GETLK,&pos)==-1){
		perror("getlock");
		return -1;
	}
	if(pos.l_type==F_UNLCK)
		puts("未被加锁");
	else{
		puts("已经被加锁");
		printf("进程id:%d\n",pos.l_pid);
		printf("锁类型:%s\n",pos.l_type==F_RDLCK?"读锁":pos.l_type==F_WRLCK?"写锁":"未加锁");
	}
	return 0;
}
