#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

void* func(void* p){
	*(int*)p=200;
	int i;
	for(i=0;i<20;i++){
		write(1,".",1);
		sleep(1);
	}
	return (void*)8888;
}
int main()
{
	pthread_t id;
	int x=100;
	pthread_create(&id,NULL,func,&x);//创建一个新线程,运行func(&x);
	int i;
	for(i=0;i<10;i++){
		write(1,"*",1);
		sleep(1);
	}
	printf("x=%d\n",x);
	void* v;
	puts("等待辅助线程结束\n");
	pthread_join(id,&v);
	printf("返回值%d\n",(int)v);
}
