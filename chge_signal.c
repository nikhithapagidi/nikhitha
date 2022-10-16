#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void myhandler();
int main()
{
	int signo;
	printf("enter a signal number\n");
	scanf("%d",&signo);

	signal(signo,myhandler);
	while(1)
	{
		printf("%d\n",getpid());
		//alarm(1);
	}
}
void myhandler()
{
	printf("signal recieved\n");
	sleep(60);
}

