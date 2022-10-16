#include<stdio.h>
#include<pthread.h>
int range;
void *even_fun1();
void *odd_fun2();
void main()
{
        pthread_t a,b;
        int *ptr;
        printf("enter range\n");
        scanf("%d",&range);
        pthread_create(&a,NULL,even_fun1,NULL);
        pthread_create(&b,NULL,odd_fun2,NULL);
        pthread_join(a,&ptr);
        pthread_join(b,&ptr);
}
void *even_fun1()
{
        int i;
        for(i=0;i<=range;i++)
        {
		
                sleep(1);
		if(i%2==0)
		{
                        printf("even--%d\n",i);
		}
        }
}

void *odd_fun2()
{
        int i;
        for(i=0;i<=range;i++)
        {
                sleep(1);
		if(i%2!=0)
		{
                        printf("odd--%d\n",i);
		}
        }
}

