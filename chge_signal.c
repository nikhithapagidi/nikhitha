#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void myhandler();
void main()
{

	signal(14,myhandler);
	while(1)
	{
		printf("%d\n",getpid());
		alarm(1);
	}
}
void myhandler()
{
	printf("signal recieved\n");
}

