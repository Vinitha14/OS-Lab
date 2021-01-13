/*
	Shukrithi Rathna
	21-09-18
	Mean Median Mode using threads
*/

/*
	Input array for calculation is 
	taken as command line argument
	with first arg as size of array.
	Array size should be less than 100
*/
//multi threading, processing, programming, tasking
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

//Threads call these functions
void *mean(void *param[]); 
void *median(void *param[]);
void *mode(void *param[]);
 
int main(int argc, char *argv[])
{
	pthread_t tid[4];//the thread identifiers
	pthread_attr_t attr;// set of thread attributes
	int i;
	if (argc<3)
	{
		fprintf(stderr,"Wrong input");
		return -1;
	}
	if (atoi(argv[1]) < 0)
	{
		fprintf(stderr,"\n First argument must be >= 0\n");
		return -1;
	}
	pthread_attr_init(&attr);
	
	pthread_create(&tid[0],&attr,mean,argv);//Create thread for mean
	pthread_create(&tid[1],&attr,median,argv);//Create thread for median
	pthread_create(&tid[2],&attr,mode,argv);//Create thread for mode
	
	for(i=0;i<3;i++)
	{
		pthread_join(tid[i],NULL);//wait for the thread to exit
	}
	printf("\nMean, Median and Mode generated\n");
}

//The threads will begin control in their appropriate functions

void *mean(void *param[])
{
	int i,j,sum=0;
	int n=atoi(param[1]);
	float mean;
	for (i = 1; i <=n; i++)
	{
		sum=sum+atoi(param[i+1]);
	}
	mean=(double)sum/n;
	printf("\nMean of given numbers is %f",mean);
}

void *median(void *param[])
{
	int i,j,k,temp;
	int n=atoi(param[1]);
	float median;
	int a[n];
	for(i=0;i<n;i++)
	{
		a[i]=atoi(param[i+2]);
	}
	//sorting input
	for(i=0;i<n;i++)
	{
	   for(j=0;j<n-1;j++)
   	   {
		  if(a[j]>a[j+1])
		   {
			  temp=a[j];
			  a[j]=a[j+1];
			  a[j+1]=temp;
		   }
	   }
	}
	/*for(i=0;i<n;i++)
	{
		printf("\n%d",a[i]);
	
	}*/
	int m=n/2;
	//printf("\nn%2 %d, m= %d",n%2,m);
	if(n%2==0)
	{
		median=(double)(a[m-1]+a[m])/2;
		
	}
	else
	{
		median=a[m];
		
	}
	printf("\nMedian of given numbers is %f",median);
}

void *mode(void *param[])
{
	int i,j,temp,freq=1,maxfreq=1;
	int n=atoi(param[1]);
	int a[n];
	for(i=0;i<n;i++)
	{
		a[i]=atoi(param[i+2]);
	}
	//sorting input
	for(i=0;i<n-1;i++)
	{
	   for(j=0;j<n-1;j++)
   	   {
		  if(a[j]>a[j+1])
		   {
			  temp=a[j];
			  a[j]=a[j+1];
			  a[j+1]=temp;
		   }
	   }
	}
	int number = a[0];
	int mode = number;
	
	
	for (i=1;i<n;i++)
	{
    	if (a[i]==number) 
    	   	++freq;// count frequency of the current number
      	else //this is a different number
        { 
            if (freq>maxfreq) 
            {
                  maxfreq=freq; 
                  mode=number;
            }
           freq=1; // reset freq for the next number
           number=a[i];
  		}
	}
	printf("\nMode of given numbers is %d",mode);
}
