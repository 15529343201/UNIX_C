#include<sys/socket.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

int main()
{
	int s[2];//套接字,也是文件描述符
	socketpair(AF_LOCAL,SOCK_STREAM,0,s);
	int n;
	char buf[100];	
	if(fork()==0){//子进程
		while((n=read(s[0],buf,sizeof(buf)))>0){
			int i;
			--n;//保留末尾的换行符
			for(i=0;i<n/2;i++){//把内容颠倒顺序
				char c=buf[i];
				buf[i]=buf[n-i-1];
				buf[n-i-1]=c;
			}
			write(s[0],buf,n+1);
		}
	}
	else{//父进程
		for(;;){
			n=read(STDIN_FILENO,buf,sizeof(buf));//读取键盘输入
			if(buf[0]=='q')
				break;
			write(s[1],buf,n);//发送到套接字
			n=read(s[1],buf,sizeof(buf));//读取子进程返回的数据
			write(STDOUT_FILENO,buf,n);//显示到屏幕上
		}
		close(s[1]);
	}
}
