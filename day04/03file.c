#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>//file control

int main(int argc,char* argv[])
{
	if(argc!=3){
		write(1,"./a.out oldfile newfile\n",24);
		return 0;
	}
	int fd1=open(argv[1],O_RDONLY);
	int fd2=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0666);
	if(fd1<0||fd2<0){
		perror("open");
		return -1;
	}
	int n;
	char buf[1024];
	while((n=read(fd1,buf,sizeof(buf)))>0){
		//加密
		int i;
		for(i=0;i<n;i++)
			buf[i]=~buf[i];
		write(fd2,buf,n);
	}
	close(fd1);
	close(fd2);

}
