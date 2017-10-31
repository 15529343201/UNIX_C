#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
void* thread(void* p){
	for(;;){
		printf("%s",(char*)p);fflush(stdout);
		sleep(1);
	}
	return NULL;
}
int main()
{
	pthread_t id;
	pthread_create(&id,NULL,thread,".");
	sleep(5);
	pthread_cancel(id);//请求辅助线程终止
	puts("----------------");
	sleep(5);
	pthread_exit(NULL);//本线程终止
	puts("****************");//这个输出应该不会执行
	return 0;
}
