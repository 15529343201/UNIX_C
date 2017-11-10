#include<stdio.h>
extern char** environ;//声明全局变量
int main()
{
	int i;
	for(i=0;environ[i]!=NULL;i++)
		puts(environ[i]);
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
*/
