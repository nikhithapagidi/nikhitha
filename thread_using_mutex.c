#include<stdio.h>
#include<pthread.h>
int range;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
void *thread_fun1();
void *thread_fun2();
void main()
{
	pthread_t a,b;
	int *ptr;
	printf("enter range\n");
	scanf("%d",&range);
	pthread_create(&a,NULL,thread_fun1,"nikky");
	pthread_create(&b,NULL,thread_fun2,"nik");
	pthread_join(a,&ptr);
	pthread_join(b,&ptr);
}
void *thread_fun1()
{
	int i;
	for(i=1;i<range;i++)
	{
		sleep(1);
		pthread_mutex_lock(&mutex);
			printf("thread 1--%d\n",i++);
		pthread_mutex_unlock(&mutex);
	}
}

void *thread_fun2()
{
	int i;
	for(i=2;i<range;i++)
	{
		sleep(1);
		pthread_mutex_lock(&mutex);
			printf("thread 2--%d\n",i++);
		pthread_mutex_unlock(&mutex);
	}
}
