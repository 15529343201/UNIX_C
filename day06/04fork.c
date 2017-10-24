#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	puts("hello");//输出hello\n
	fork();//克隆进程
	puts("world");//两份都输出world\n
	printf("good");//两份都输出good到缓冲区
	fork();//两份进程都会在克隆进程(缓冲区也克隆)
	printf(" luck\n");//四份都输出 luck\n
}
