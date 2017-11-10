#include<dirent.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
	DIR* p = opendir(".");//打开当前目录
	//if(p==NULL){...}
	struct dirent* q;
	while((q=readdir(p))!=NULL){//逐项读取
		if(q->d_name[0]=='.') continue;//跳过隐藏文件
		printf("%s\n",q->d_name);//显示
	}
	closedir(p);//关闭目录
}
/*
day03.txt
07dir.c
04user.c
08dir.c
a.out
02file.c
furong
03stat.c
01error.c
lfr
06time.c
05now.c
*/
