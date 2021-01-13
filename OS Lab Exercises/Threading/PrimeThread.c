/*
	Shukrithi Rathna
	21-09-18
	Generation of prime numbers
	using thread
*/

//Upper limit for generation is taken as command line argument

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
//int sum; /* this data is shared by the thread(s) */
void *Prime(void *param); // thread calls this function

int main(int argc, char *argv[])
{
	pthread_t tid; /* the thread identifier */
	pthread_attr_t attr; /* set of thread attributes */
	if (argc != 2)
	{
		fprintf(stderr,"Wrong input");
		return -1;
	}
	if (atoi(argv[1]) < 0)
	{
		fprintf(stderr,"Parameter must be >= 0\n");
		return -1;
	}
	/* get the default attributes */
	pthread_attr_init(&attr);
	/* create the thread */
	pthread_create(&tid,&attr,Prime,argv[1]);
	/* wait for the thread to exit */
	pthread_join(tid,NULL);
	printf("\nPrime numbers generated\n");
}
	/* The thread will begin control in this function */
void *Prime(void *param)
{
	int i,j,flag;
	int limit=atoi(param);
	printf("\nThe prime numbers are: ");
	for (i = 1; i <=limit; i++)
	{
		flag=0;
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			printf("\t%d",i);
	}
}
