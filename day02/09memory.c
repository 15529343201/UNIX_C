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
