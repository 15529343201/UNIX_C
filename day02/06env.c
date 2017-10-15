#include<stdio.h>
#include<string.h>

int main(int argc,char* argv[],char* env[])
{//env是环境变量数组,以NULL为结束元素
	int i;
	char *p=NULL;
	for(i=0;env[i]!=NULL;i++){
		puts(env[i]);//显示环境变量字符串
		if(strncmp(env[i],"LANG=",5)==0)
			p=env[i]+5;
	}
	if(p!=NULL)
		printf("环境变量LANG的值为%s\n",p);

}

