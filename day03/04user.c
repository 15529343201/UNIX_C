#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<pwd.h>

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		puts("./a.out path");
		return 0;
	}
	struct stat s;
	lstat(argv[1],&s);
	printf("硬链接%lu,用户名%s,字节数%lu\n",
			s.st_nlink,
			getpwuid(s.st_uid)->pw_name,
			s.st_size);
}
/*
./a.out ../
硬链接13,用户名ubuntu,字节数4096
*/
