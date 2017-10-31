#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void* func(void* p){
	int i;
	int* a=(int*)p;
	for(i=0;i<20;i++){
		a[i]=100+i;
		sleep(1);
	}
	return NULL;
}
int main()
{
	int a[20];
	pthread_t id;
	pthread_create(&id,NULL,func,a);
	sleep(2);//等待辅助线程先工作
	int i;
	for(i=0;i<20;i++){
		printf("%d ",a[i]);fflush(stdout);//立即显示
		sleep(1);
	}
}
