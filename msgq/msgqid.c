#include<stdio.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#define MSG_TYPE 1
#define KEY 0X11000110
int main()
{
	char rbuf[50],wbuf[50],buf[50];
	int msqid,ret;
	msqid=msgget(KEY,IPC_CREAT|0664);
	printf("server is waiting for client message\n");
	while(1)
	{
        ret=msgrcv(msqid,rbuf,40,MSG_TYPE,0);
//	printf("%d\n",ret);
//	printf("%ld\n",((long int *)rbuf)[0]);
//	printf("%ld\n",((long int *)rbuf)[1]);
	printf("from client--%s\n",&rbuf[16]);
	((long int *)wbuf)[0]=((long int *)rbuf)[1];
	printf("enter a message to client\n");
	scanf("%[^\n]s",buf);
	__fpurge(stdin);
	strcpy(&wbuf[8],buf);
//	printf("server reply:msgtype= %ld\n",((long int *)wbuf)[0]);
//	printf("server reply:message= %s\n",&wbuf[8]);
	msgsnd(msqid,wbuf,8+strlen(&wbuf[8])+1,0);
	}
	msgctl(msqid,IPC_RMID,0);

	
}
