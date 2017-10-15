#include "welcome.h"

int main(int argc,char* argv[])
{
	if(argc!=2) { printf("usage:%s name\n",argv[0]);}
	else welcome(argv[1]);
}

