#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
int main()
{
	char buf[100];
	int opt,ret;
	while(1)
	{
	printf("0 exit\t 1 creating directory\t2 removing directory\n");
	printf("enter option\n");
	scanf("%d",&opt);
	switch(opt)
	{
		case 0: exit(0);
		case 1:printf("enter a name for creating directory\n");
		       scanf("%s",buf);
	               ret=mkdir(buf,0777);
		       printf("%d\n",ret);
		       break;
		case 2:printf("enter a name for removing directory\n");
	               scanf("%s",buf);
		       ret=rmdir(buf);
		       printf("%d\n",ret);
		       break;
	}
	}
}
