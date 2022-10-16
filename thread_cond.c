#include<stdio.h>
#include<pthread.h>
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition=PTHREAD_COND_INITIALIZER;
void *even_num();
void *odd_num();
int x;
int y;
main()
{
	pthread_t ti1,ti2;
	int *ptr;
	printf("enter the min value\n");
	scanf("%d",&x);
	printf("enter the max value\n");
	scanf("%d",&y);
	pthread_create(&ti1,NULL,even_num,NULL);
	pthread_create(&ti2,NULL,odd_num,NULL);
	pthread_join(ti1,&ptr);
	pthread_join(ti2,&ptr);
}
void *even_num()
{
	pthread_mutex_lock(&mutex);
	while(x<=y)
	{
	//	sleep(1);	
		if(x%2==0)
		{
			printf("thread-1 even_num : %d\n",x);
			x++;
			pthread_cond_signal(&condition);
		}
		else
		{	
			pthread_mutex_unlock(&mutex);
		}
	}
	pthread_cond_signal(&condition);
	pthread_exit(0);
}
void *odd_num()
{
	pthread_mutex_lock(&mutex);
	while(x<=y)
	{
		//sleep(1);
		if(x%2!=0)
		{
			printf("thread-2 odd_num : %d\n",x);
			x++;
			pthread_cond_wait(&condition,&mutex);
		}
		else
		{
			pthread_mutex_unlock(&mutex);
		}
	}
	//pthread_exit(0);
}
