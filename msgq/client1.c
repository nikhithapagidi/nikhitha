#include<stdio.h>
#include<sys/msg.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#define MSG_TYPE 1
#define KEY 0X11000110
int main()
{
        char rbuf[50],wbuf[50],buf[50];;
        int msqid,ret;
	((long int *)wbuf)[0]=MSG_TYPE;
	((long int *)wbuf)[1]=getpid();
	printf("%d\n",getpid());
	while(1)
	{
	printf("enter a meassage to server\n");
	scanf("%[^\n]s",buf);
	__fpurge(stdin);
	strcpy(&wbuf[16],buf);
        msqid=msgget(KEY,0);
	msgsnd(msqid,wbuf,16+strlen(&wbuf[16])+1,0);
	msgrcv(msqid,rbuf,40,getpid(),0);
	printf("from server----%s\n",&rbuf[8]);
	}
}
