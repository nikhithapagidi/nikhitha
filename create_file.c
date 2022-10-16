#include<stdio.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
	int fd,ret;
	if(argc>2)
	{
		return -1;
	}
	fd=open(argv[1],O_CREAT,0664);
	if(fd>0)
	{
		printf("creating file successfully\n");
	}
}
