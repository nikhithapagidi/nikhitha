#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
	
	int fd1,fd2,ret;
	char rbuf1[100],rbuf[100];

	if(argc>3)
	{
		return -1;
	}

	fd1=open(argv[1],O_CREAT|O_RDONLY,0664); //opening file 1
	ret=read(fd1,rbuf,100); //reading data from file 1
	rbuf[ret]='\0';
	printf("before swapping\n***************\n");
	printf("%s\n",rbuf);


//	ret=truncate(argv[1],0);  //removing file 1 data
	//printf("trunacte--%d\n",ret);

	fd2=open(argv[2],O_CREAT|O_RDONLY,0664); //oepning file 2
	ret=read(fd2,rbuf1,100); //reading file 2
	rbuf1[ret]='\0';
	printf("%s\n",rbuf1);
	

//	truncate(argv[2],0); //removing file 2 contet

	fd2=open(argv[2],O_WRONLY);  //writing file 1 data to file 2
	ret=write(fd2,rbuf,strlen(rbuf));
	//printf("%d\n",ret);

	fd1=open(argv[1],O_WRONLY); //writing file 2 data to file 1 
	ret=write(fd1,rbuf1,strlen(rbuf1));
	//printf("%d\n",ret);
	printf("after swapping\n***********\n");
	printf("%s\n",rbuf1);
	printf("%s\n",rbuf);
	
	close(fd1);
	close(fd2);

}
