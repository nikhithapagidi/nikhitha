#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
void main()
{
	int fd,ret,cfd,r;
	char buf[10];
	char wbuf[10];
	char nbuf[4]="bye";
	mkfifo("serfifo",0660);
	while(1)
	{
	fd=open("serfifo",O_RDONLY);
	ret=read(fd,buf,10);
	buf[ret]='\0';
	if(strcmp(buf,nbuf)==0)
		exit(0);
	printf("%s\n",buf);

	cfd=open("clififo",O_WRONLY);
	scanf("%s",wbuf);
	write(cfd,wbuf,strlen(wbuf));
	}
	
}


