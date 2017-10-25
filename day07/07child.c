#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char* argv[])
{
	if(argv[1]==NULL){
		return 0;
	}
	for(;;){
		write(1,argv[1],strlen(argv[1]));
		sleep(1);
	}
}
