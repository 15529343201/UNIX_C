#include<stdio.h>
extern char** environ;//声明全局变量
int main()
{
	int i;
	for(i=0;environ[i]!=NULL;i++)
		puts(environ[i]);
} 
