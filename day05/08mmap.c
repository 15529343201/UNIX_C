#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<string.h>

int main()
{
	int fd=open("mmap",O_RDWR);
	if(fd<0){
		perror("open");
		return -1;
	}
	char *p=mmap(0,1024,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(p==MAP_FAILED){
		perror("mmap");
		return -1;
	}
	int cnt=0;
	for(;;){
		if(p[0]!='\0'){
			printf("%s",p);
			memset(p,0,strlen(p));
			cnt=0;
		}else{
			if(++cnt==20)
				break;//10秒闲置则退出
		}
		usleep(1000*500);//休息0.5秒
	}
	munmap(p,1024);
	close(fd);
}
