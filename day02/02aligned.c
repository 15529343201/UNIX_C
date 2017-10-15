#include<stdio.h>

typedef struct A{
	char a;
	double b;
	char c;
}A;//默认4字节对齐补齐
typedef struct B{
	char a;
	double b;
	char c;
}__attribute__((packed)) B;//内部1字节对齐补齐
#pragma pack(1)//此后都1字节对齐补齐
typedef struct C{
	char a;
	double b;
	char c;
}C;//size=10
//#pragma pack()恢复默认对齐补齐
typedef struct D{
	char a;
	int b;
	char c;
}__attribute__((aligned(8))) D;//内部8字节补齐
int main()
{
	printf("sizeof A=%d\n",sizeof(A));
	printf("sizeof B=%d\n",sizeof(B));
	printf("sizeof C=%d\n",sizeof(C));
	printf("sizeof D=%d\n",sizeof(D));
	D x;
	printf("%p\n",&x);
	printf("%p\n",&x.a);
	printf("%p\n",&x.b);
	printf("%p\n",&x.c);
}
