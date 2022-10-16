#include<stdio.h>
#include<signal.h>
int main()
{
	
	pid_t pid;
	printf("enter pid of the process\n");
	scanf("%d",&pid);
	kill(pid,9);

}


