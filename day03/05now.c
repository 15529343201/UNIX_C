#include<stdio.h>
#include<time.h>

int main()
{
	time_t now = time(NULL);
	printf("now=%lu\n",now);
	struct tm *p=localtime(&now);
	printf("%d年%d月%d日 星期%d %02d:%02d:%02d\n",
			p->tm_year+1900,p->tm_mon+1,p->tm_mday,
			p->tm_wday,p->tm_hour,p->tm_min,p->tm_sec);
	char buf[100];
	strftime(buf,sizeof(buf),"%F %w %T",p);
	puts(buf);
	return 0;
}
/*
now=1510324213
2017年11月10日 星期5 22:30:13
2017-11-10 5 22:30:13
*/
