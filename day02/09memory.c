#include<stdio.h>
int sum=0;
int main()
{
	int d;
	printf("&sum=%p,&d=%p\n",&sum,&d);
	for(;;){
		printf("请输入一个整数:");
		scanf("%d",&d);
		sum += d;
		printf("&sum=%p,sum=%d\n",&sum,sum);
	}
	return 0;
}
/*
sum=0x561f06ce7014,&d=0x7ffcca36fc44
请输入一个整数:30
&sum=0x561f06ce7014,sum=30
请输入一个整数:31
&sum=0x561f06ce7014,sum=61
请输入一个整数:32
&sum=0x561f06ce7014,sum=93
*/

