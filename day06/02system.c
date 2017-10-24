#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	printf("hello-------------------\n");
	system("echo 芙蓉");
	char cmd[100]="ls -l|wc -l>abc";
	system(cmd);//system("ls -l|wc -l>abc");
	if(access("a.out",F_OK)==0)
		system("./a.out");
	printf("world-------------------\n");
}
