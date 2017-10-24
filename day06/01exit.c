#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void f1(void){puts("f1()");}
void f2(void){puts("f2()");}
void f3(int n,void* p){
	printf("n=0x%x,p=%p\n",n,p);
	free(p);//释放动态内存
}

int onefunc(){
	exit(0);//return 0;
	//_exit(0);//立即结束进程,清理工作不会执行
}

int main()
{
	atexit(f1);//登记f1,
	atexit(f2);//登记f2
	void* q=malloc(10);//申请动态内存
	on_exit(f3,q);//登记f3
	//以上只是登记了f1/f2/f3函数但并没有调用它们
	printf("groupid:%d\n",getpgid(getpid()));
	printf("q=%p\n",q);
	onefunc();//return 0
	//return 0;
	puts("you cannot see me");
	//程序结束,系统会自动调用f1/f2/f3
}
