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
/*
LANG=en_US.UTF-8
SUDO_GID=1000
USERNAME=root
SUDO_COMMAND=/bin/bash
USER=root
PWD=/home/ubuntu/UNIX_C/day02
HOME=/home/ubuntu
SUDO_USER=ubuntu
SUDO_UID=1000
MAIL=/var/mail/root
SHELL=/bin/bash
TERM=xterm
SHLVL=1
LOGNAME=root
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin
_=./a.out
OLDPWD=/home/ubuntu/UNIX_C
环境变量LANG的值为en_US.UTF-8
*/
