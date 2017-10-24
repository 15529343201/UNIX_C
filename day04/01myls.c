#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<pwd.h>
#include<grp.h>
#include<string.h>
#include<time.h>

void printtype(int mode)
{
	if(S_ISREG(mode)) putchar('-');//普通文件
	else if(S_ISDIR(mode)) putchar('d');//目录
	else if(S_ISLNK(mode)) putchar('l');//符号链接
	else if(S_ISFIFO(mode)) putchar('p');//管道
	else if(S_ISSOCK(mode)) putchar('s');//网络套接字
	else if(S_ISCHR(mode)) putchar('c');//字符设备
	else if(S_ISBLK(mode)) putchar('b');//块设备
	else putchar('@');//其他
}

void printaccess(int mode)//字符形式打印权限
{//rwxrwxrwx 反复左移
	const char* acc="rwx";//可能的字符权限表
	int i;
	for(i=0;i<9;i++,mode<<=1)//分别测试9个权限
		putchar(mode&0400?acc[i%3]:'-');//B100 000 000

}
void showdetail(const char* name)//显示详细信息
{
	struct stat s;
	lstat(name,&s);//取得详细信息
	printtype(s.st_mode);//类型
	printaccess(s.st_mode&0777);//权限 &0777;
	printf("%2lu",s.st_nlink);//显示硬链接数目
	printf("%5s",getpwuid(s.st_uid)->pw_name);//显示用户名
	printf("%5s",getgrgid(s.st_gid)->gr_name);//显示组名
	printf("%6lu",s.st_size);//字节数
	char buf[20];
	strftime(buf,sizeof(buf),"%F %T",localtime(&s.st_mtime));
	printf("%20s %s\n",buf,name);//时间 文件名
}

void listdetail(void)
{
	DIR* p=opendir(".");
	if(p==NULL){
		perror("opendir");
		return;
	}
	struct dirent* q=NULL;
	while((q=readdir(p))!=NULL){
		if(q->d_name[0]=='.') continue;
		//列出详细信息
		showdetail(q->d_name);
	}
}

int main(int argc,char* argv[])
{
	if(argc>2){//命令行参数个数检查
		printf("%s [目录路径]\n",argv[0]);
		return 0;
	}
	if(argc==2){//命令行带了目录路径
		if(chdir(argv[1])<0){//设为当前目录
			perror("错误");
			return -1;
		}
	}
	listdetail();
}
