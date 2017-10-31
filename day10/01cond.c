#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
int flag=0;
pthread_mutex_t m;
void* thread1(void* p){
	for(;;){
		pthread_mutex_lock(&m);
		int vflag=flag;//互斥访问flag变量
		pthread_mutex_unlock(&m);
		if(vflag){
			write(1,p,1);
			sleep(1);
		}
	}
}
int main()
{
	pthread_t id1,id2;
	pthread_mutex_init(&m,NULL);
	pthread_create(&id1,NULL,thread1,".");
	pthread_create(&id2,NULL,thread1,"*");
	for(;;){
		char c;
		scanf(" %c",&c);
		pthread_mutex_lock(&m);
		flag=(c=='a');//互斥访问flag
		pthread_mutex_unlock(&m);
	}
}
