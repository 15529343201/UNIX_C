#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main()
{
	sigset_t ss;
	sigemptyset(&ss);//sigfillset(&ss)
	puts(sigismember(&ss,SIGINT)?"sigint":"noint");
	puts(sigismember(&ss,SIGTERM)?"sigterm":"noterm");

	sleep(5);
	sigaddset(&ss,SIGINT);
	sigaddset(&ss,SIGTERM);
	puts(sigismember(&ss,SIGINT)?"sigint":"noint");
	puts(sigismember(&ss,SIGTERM)?"sigterm":"noterm");

	sleep(5);
	sigdelset(&ss,SIGINT);
	puts(sigismember(&ss,SIGINT)?"sigint":"noint");
	puts(sigismember(&ss,SIGTERM)?"sigterm":"noterm");

	sleep(5);
	sigfillset(&ss);
	puts(sigismember(&ss,SIGINT)?"sigint":"noint");
	puts(sigismember(&ss,SIGTERM)?"sigterm":"noterm");
}

	
	
