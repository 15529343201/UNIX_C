#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("pagesize:%d\n",getpagesize());
	int *p = sbrk(0);//返回当前终点,有效内存地址不包含终点。
	printf("end:%p\n",p);
	//int n = *p;//段错误
	brk(p+8);//终点后移8*4字节,操作系统把扩展的这段虚拟内存映射到物理内存,但映射以页为基本单位,实际映射的内存会是一页。
	int i;
	for(i=0;i<18;i++)//越界但不会段错误
		p[i]=10+i;
	for(i=0;i<18;i++)
		printf("%d ",p[i]);
	printf("\n");
	//p[1024]=111;//超越内存页了,段错误
	printf("p+8=%p\n",p+8);
	printf("+4:%p\n",sbrk(4070));//32+4070超过一页,会映射下一页虚拟内存地址到物理内存
	p[1024]=111;//正常了
	sbrk(-6);//回退6字节,最后一页的映射就不需要了,操作系统会解除这一页映射。
	//p[1024]=111;//又会段错误。
	return 0;
}
