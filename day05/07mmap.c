#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<string.h>


int main()
{
	umask(0);
	int fd=open("mmap",O_RDWR|O_CREAT,0777);
	if(fd<0){
		perror("open");
		return -1;
	}
	ftruncate(fd,1024);//把文件截成1k长
	char *p=mmap(0,1024,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);//建立文件和内存的映射
	if(p==MAP_FAILED){
		perror("mmap");
		return -1;
	}
	for(;;){
		int n=read(STDIN_FILENO,p,1024);//键盘输入
		if(n<=0)
			break;//出错退出
	}
	munmap(p,1024);//解除映射
	close(fd);
}


