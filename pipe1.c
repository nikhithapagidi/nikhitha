#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
void main()
{
	int ret,i,ret1,len;
	pid_t pid;
	char buf[100],buf1[100];
	char rbuf[100],wbuf[100];
	int fd[2];
	int fd1[2];
	ret=pipe(fd);
	pipe(fd1);
	pid=fork();
	if(pid>0)
	{
		//printf("parent\n");
		while(1)
		{
			close(fd[0]);//close read operation
			printf("enter data to send for child\n");
			scanf("%[^\n]s",wbuf);
			__fpurge(stdin);
			ret=write(fd[1],wbuf,strlen(wbuf));

			close(fd1[1]);//close write operation
			ret1=read(fd1[0],rbuf,100);
			rbuf[ret1]='\0';
			printf("parent--%s\n",rbuf);
		}

	}
	else
	{
	        //printf("child\n");
		while(1)
		{

			close(fd[1]);//close write operation
			ret=read(fd[0],buf,100);
			buf[ret]='\0';
			printf("child---%s\n",buf);

			close(fd1[0]);//close read operation
			printf("enter data to send for parent\n");
			scanf("%[^\n]s",buf1);
			__fpurge(stdin);
			write(fd1[1],buf1,strlen(buf1));
		}

	}
}
