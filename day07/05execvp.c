#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{//ls -l -d /bin
	char* argv[]={
		"/bin/ls",
		"-l",
		"-d",
		"/bin",
		NULL//必须用一个NULL作为结束元素
	};
	puts("......execute ls -l -d /bin.....");
	execvp("ls",argv);//通过PATH环境变量找可执行文件
	puts("------ERROR------");//看不到这个,除非出错
}
