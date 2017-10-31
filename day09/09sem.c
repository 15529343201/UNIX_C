#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
sem_t s;
void* func(void* p){
	int i;
	int* a=p;
	for(i=0;i<10;i++){
		sem_wait(&s);//等待主线程输入一个数据
		int t=a[i];
		int j;//插入法排序
		for(j=i;j>0&&t<a[j-1];j--)
			a[j]=a[j-1];
		a[j]=t;
	}
}

int main()
{
	int a[10];
	sem_init(&s,0,0);
	pthread_t id;
	pthread_create(&id,NULL,func,a);
	int i;
	for(i=0;i<10;i++){
		printf("请输入第%d个数据:",i+1);
		scanf("%d",&a[i]);
		sem_post(&s);//信号量值+1给辅助线程sem_wait放行
	}
	usleep(1);//等待最后一个数据排序完毕
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	sem_destroy(&s);
}
