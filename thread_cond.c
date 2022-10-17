#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
int range;

void *oddthread();
void *eventhread();

int main()
{
        pthread_t ti1,ti2;
	printf("enter a range\n");
	scanf("%d",&range);
        pthread_create(&ti1,NULL,oddthread,NULL);
        pthread_create(&ti2,NULL,eventhread,NULL);
        pthread_join(ti1,NULL);
        pthread_join(ti2,NULL);
	return 0;
}
void *oddthread()
{
        int i;
        for(i=0;i<=range;i++)
        {

	pthread_mutex_lock(&mutex);
                if(i%2!=0)
                        printf("odd---%d\n",i);
		pthread_cond_wait(&cond,&mutex);
                        pthread_mutex_unlock(&mutex);
			//sleep(1);
        }
	pthread_exit(0);
	
}

void *eventhread()
{
        int i;
        for(i=0;i<=range;i++)
        {
        	pthread_mutex_lock(&mutex);
		if(i%2==0)
                        printf("even-- %d\n",i);
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex);
		sleep(1);
                        
        }
	pthread_exit(0);
	
}

