#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
	mkdir("mydir",0755);//在当前目录下创建一个目录
	chdir("mydir");//进入这个目录
	char buf[100];
	getcwd(buf,sizeof(buf));//取得当前目录绝对路径
	puts(buf);
	chdir("..");//回到上级目录
	sleep(10);//等待10秒
	rmdir("mydir");//删除目录
}
