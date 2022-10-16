#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
	int i,j;
	char *argv[10];
	char str[200];
	printf("enter a command\n");
	scanf("%[^\n]s",str);
	__fpurge(stdin);
	argv[0]=str;
	for(i=0,j=1;str[i]!='\0';i++)
	{
		if(str[i]==' ')
		{
			
			str[i]='\0';
			argv[j]=&str[i+1];
			i++;
			j++;
		}
	}
	argv[j]=0;
	mysys(argv);
}
int mysys(char **argv)
{
	int ret,x,i;
	pid_t pid;
	pid=fork();
	if(pid>0)
	{
		ret=wait(&x);
		return 0;
	}
	else
	{
		execvp(argv[0],argv);
	}
}


		
