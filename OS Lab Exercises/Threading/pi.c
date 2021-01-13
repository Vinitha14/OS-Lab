/*
	Shukrithi Rathna
	28-09-18
	Program to calcualte pi using Monte Carlo simulation
*/


#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>

void *pi();// thread calls this function

void *pi()
{
	int i,interval=100;
	double x,y,dist;
	int circle_points=0,square_points=0;
	srand(time(NULL));
	for(i=0;i<(interval*interval);i++)
    {  
		x=(double)(rand()%(interval+1))/interval;
		y=(double)(rand()%(interval+1))/interval;
		double xsquare=(double)pow(x,2);
		double ysquare=(double)pow(y,2);
		dist=sqrt(xsquare+ysquare);
	    if(dist<=1) 
			circle_points++;
		printf(" x value :%f,y value:%f,dist:%f",x,y,dist);
   
    }
	square_points=i;
	printf("circle_points:%d,square_points:%d",circle_points,square_points);
	double pi=4.0*circle_points/square_points;
	printf("\n%f",pi);
		pthread_exit(NULL);
	
}
   
int main()
{
	pthread_t tid; // the thread identifier 
	pthread_attr_t attr; // set of thread attributes 
	pthread_attr_init(&attr);// get the default attributes
	pthread_create(&tid,&attr,Prime,argv[1]);// create the thread
	pthread_join(tid,NULL); wait for the thread to exit 
	
	return(0);
}
