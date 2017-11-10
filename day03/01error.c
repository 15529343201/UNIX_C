#include<stdio.h>
#include<errno.h>
#include<string.h>

int main()
{
	FILE *fp = fopen("furong","quange");
	if(fp==NULL){//失败,会设置错误码errno
		printf("打开文件furong失败\n");
		if(errno==EINVAL)
			printf("打开方式无效\n");
		printf("errno=%d\n",errno);
		printf("%s\n",strerror(errno));//错误码对应的字符串
		perror("错误信息");//打印当前错误信息
		printf("error string:[ %m]\n");//打印当前错误信息

	}
}
/*
打开文件furong失败
打开方式无效
errno=22
Invalid argument
错误信息:不合法的参数
error string:[ Invalid argument]
*/
