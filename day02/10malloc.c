#include<stdio.h>
#include<stdlib.h>

int main()
{
	char* p1=malloc(0x20);
	char* p2=malloc(0x20);
	printf("p1=%p,p2=%p\n",p1,p2);
	return 0;
}
/*
p1=0x563559d0c010,p2=0x563559d0c040
*/
