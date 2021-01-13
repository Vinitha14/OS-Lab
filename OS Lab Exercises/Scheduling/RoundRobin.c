/*
	Shukrithi Rathna
	CE16I031
	Round Robin OS scheduling
*/

/*  Input burst time for
	each process.
	Input time slice
	Maximum 10 procceses.
	
*/

#include<stdio.h>

int main()
{
	int i,j=0,n,time,remain,flag=0,ts;	
	int sum_wait=0,sum_turnaround=0,bt[10],rt[10];
	int ganttP[50],ganttStartTime[50];

//Input number of proccesses
	printf("Enter no of Processes : ");
	scanf("%d",&n);
	
	remain=n;
	
//Input burst times
	printf("\nEnter Burst time \n");
  	for(i=0;i<n;i++)
	{
    	printf("\n%d ",i+1);
    	scanf("%d",&bt[i]);
    	rt[i]=bt[i];
	}
	
	printf("Enter time slice:");
	scanf("%d",&ts);
	
	printf("\n Process   Burst    Turnaround   Waiting \n");
	for(time=0,i=0;remain!=0;)
	{
		if(rt[i]<=ts && rt[i]>0)
		{
			time+=rt[i];
			rt[i]=0;
			flag=1;
		}
		else if(rt[i]>0)
		{
			rt[i]-=ts;
			time+=ts;
		}
		if(rt[i]==0 && flag==1)
		{
			remain--;
			printf("P[%d]\t\t%d\t\t%d\t%d\n",i+1,bt[i],time,time-bt[i]);
			sum_wait+=time-bt[i];
			sum_turnaround+=time;
			flag=0;
		}
		if(i==n-1)
			i=0;
		else
			i++;
	}
		
	return(0);
}













