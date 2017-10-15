#include<stdio.h>
#include<sys/mman.h>

int main()
{
	char* p=mmap(NULL,200,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
	if(p!=MAP_FAILED){
		scanf("%[^\n]",p);
		printf("您输入的是%s\n",p);
		munmap(p,200);
	}
}
