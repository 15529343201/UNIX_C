#include<stdio.h>
#include<string.h>

int main()
{
	char a[32];
	strcpy(a,"ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd");//越界,破坏栈,可能崩溃
}
