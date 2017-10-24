#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
//rename,symlink,chmod,access,remove
int main(int argc,char* argv[])
{
	rename(argv[0],"furong");//把a.out改名为furong
	symlink("furong","lfr");//给furong建符号链接
	chmod("furong",0555);//修改权限
	if(access("furong",F_OK)==0)
		puts("furong存在");
	if(access("furong",R_OK)==0)
		puts("可读");
	if(access("furong",W_OK)==0)
		puts("可写");
	if(access("furong",X_OK)==0)
		puts("可执行");
}
