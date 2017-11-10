#include<stdio.h>

void f1()__attribute__((constructor));
void f2()__attribute__((destructor));
int main()
{
	puts("main function()");
}
void f1(){puts("before main");}
void f2(){puts("after main");}

/*
before main
main function()
after main
*/
