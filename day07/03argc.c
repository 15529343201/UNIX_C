#include<stdio.h>

int main(int argc,char* argv[])
{
	int cnt=0;
	while(argv[cnt]!=NULL)
		++cnt;
	printf("cnt=%d,argc=%d\n",cnt,argc);
}
