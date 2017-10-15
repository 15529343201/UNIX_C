#include<stdio.h>
#include<string.h>
#include "str.h"

int main()
{
	char str[100];
	int n;
	printf("请输入一个字符串和一个整数:");
	scanf("%s%d",str,&n);
	puts(str);
	strtoupper(str);
	puts(str);
	strtolower(str);
	puts(str);
	i2str(n,str);
	puts(str);
	printf("%g,%g\n",gvar,gvar+n);
}
