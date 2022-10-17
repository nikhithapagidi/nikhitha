#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
void main()
{       
        int fd,ret,cfd;
	char buf[10];
	char wbuf[10];
	while(1)
	{
	fd=open("serfifo",O_WRONLY);
	scanf("%s",wbuf);
	write(fd,wbuf,strlen(wbuf));

	mkfifo("clififo",0660);
        cfd=open("clififo",O_RDONLY);

	ret=read(cfd,buf,9);
	buf[ret]='\0';
	printf("%s\n",buf);
	}
}
