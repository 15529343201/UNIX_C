#include<arpa/inet.h>
#include<stdio.h>
int main()
{
	union{
		int ival;
		unsigned char ch[4];
	}v;
	v.ival=0x12345678;
	printf("%x %x %x %x\n",v.ch[0],v.ch[1],v.ch[2],v.ch[3]);
	v.ival=htonl(v.ival);
	printf("%x %x %x %x\n",v.ch[0],v.ch[1],v.ch[2],v.ch[3]);
}
//小端
