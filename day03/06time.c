#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		puts("./a.out path");
		return 0;
	}
	struct stat s;
	if(lstat(argv[1],&s)!=0)
	{
		puts("文件不存在");
	}
	else
	{
		char buf[100];
		strftime(buf,sizeof(buf),"最后修改时间%F %T",localtime(&s.st_mtime));
		puts(buf);
	}
}
				
