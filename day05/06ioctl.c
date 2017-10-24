#include<stdio.h>
#include<sys/ioctl.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>

int main()
{
	struct winsize w;
	for(;;){
		ioctl(STDIN_FILENO,TIOCGWINSZ,&w);
		printf("%d行,%d列\n",w.ws_row,w.ws_col);
		usleep(1000000);
	}
}
