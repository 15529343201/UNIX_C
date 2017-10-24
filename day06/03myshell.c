#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int isvar(const char* beg,const char* end)
{
	return 1;//检查是否符合变量命名规则
}

int main()
{
	puts("欢迎使用quange shell");
	char cmd[256];
	char *p=NULL;
	for(;;){
		printf("qs> ");
		scanf(" %[^\n]",cmd);//空格表示跳过空白字符直到遇到非空白为止
		if(strcmp(cmd,"furong")==0)
			break;
		if(strncmp(cmd,"cd ",3)==0)//"cd hello"
			//int strncmp(const char *str1,const char *str2,size_t n),若str1与str2的前n个字符相同,则返回0;若s1大于s2,则返回大于0的值;若s1小于s2,则返回小于0的值
			chdir(cmd+3);
		else if((p=strchr(cmd,'='))&&isvar(cmd,p)){//检查命令中是否有=而且等号左边是否是个合法的变量名,也就是检查用户是否想设置环境变量
			*p='\0';//把字符串切割成变量名和变量值
			setenv(cmd,p+1,1);//设置环境变量setenv(环境变量名,环境变量值,是否覆盖) 1如果存在就覆盖
		}
			//extern char *strchr(const char *s,char c),可以查找字符串s中首次出现字符c的位置,返回值:成功则返回要查找字符第一次出现的位置,失败返回NULL
		else
			system(cmd);
	}
	puts("感谢使用qsh!");
}
