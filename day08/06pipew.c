#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
typedef struct{
	char name[20];//XXXchar *name;(错误)
	int age;
	double weight;
}Person;
	
int main()
{
	mkfifo("pipe",0644);
	int fd=open("pipe",O_WRONLY);
	if(fd==-1){
		perror("open");
		return -1;
	}
	puts("打开成功");
	printf("请输入姓名、年龄和体重:\n");
	Person x;
	scanf("%s%d%lf",x.name,&x.age,&x.weight);
	write(fd,&x,sizeof(x));
	close(fd);
	unlink("pipe");
}
