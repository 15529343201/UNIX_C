#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{//ls -l -d /bin
/*	char* argv[]={
		"/bin/ls",
		"-l",
		"-d",
		"/bin",
		NULL//必须用一个NULL作为结束元素
	};*/
	puts("......execute ls -l -d /bin.....");
	execl("/bin/ls","/bin/ls","-l","-d","/bin",NULL);//execl把execv中的argv所有元素依次摆出来作为参数,包括最后的NULL
	puts("------ERROR------");//看不到这个,除非出错
}
