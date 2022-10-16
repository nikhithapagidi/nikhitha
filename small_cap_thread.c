#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
char str[100];
void *small_fun();
void *capital_fun();
void main()
{
        pthread_t a,b;
        int *ptr;
        printf("enter word\n");
        scanf("%[^\n]s",&str);
        pthread_create(&a,NULL,small_fun,NULL);
        pthread_create(&b,NULL,capital_fun,NULL);
        pthread_join(a,&ptr);
        pthread_join(b,&ptr);
}
void *small_fun()
{
        int i;
        for(i=0;str[i]!='\0';i++)
        {
		
		if(str[i]>=97&&str[i]<=122)
		{
			if(str[i]==' ')
			{
				continue;
			}
                        printf("small letters : %c\n",str[i]);
		}
		sleep(1);
        }
}
void *capital_fun()
{
        int i;
        for(i=0;str[i]!='\0';i++)
        {

                if(str[i]>=65&&str[i]<=90)
                {
			if(str[i]==' ')
			{
				continue;
			}
                        printf("capital letters : %c\n",str[i]);
                }
		sleep(1);
        }
}

