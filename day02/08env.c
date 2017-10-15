#include<stdio.h>
#include<stdlib.h>

int main()
{
	putenv("CLASS=csd1212");
	char* p=getenv("CLASS");
	if(p)
		puts(p);
	setenv("NAME","芙蓉",1);
    p=getenv("NAME");
	if(p)
		puts(p);
}
