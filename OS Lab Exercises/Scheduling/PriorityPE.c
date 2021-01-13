/*
	Shukrithi Rathna
	CE16I031
	Priority Queue (Pre-emptive) OS scheduling
*/

/*  Input arrival and burst time for
	each process.
	Maximum 10 procceses.
	Priority 2 > Priority 1
*/


#include <stdio.h>
int main() 
{
  int a[10],b[10],c[10],p[10],tat[10],wt[10];
  int i,j,n,largest,time,count=0;
  int x[10],y[10];//to store copies of burst time and priority
 
//Input number of proccesses
  printf("\nEnter the number of Processes:\n");
  scanf("%d",&n); 
 
//Input arrival and burst times, priority  
  printf("\nEnter Arrival time and Burst time and Priority\nPid A B Pr\n");
  for(i=0;i<n;i++)
  {
    printf("\n%d ",i+1);
    scanf("%d",&a[i]);
    scanf("%d",&b[i]);
    scanf("%d",&p[i]);
  }  
 
  for(i=0;i<n;i++)//store a copy of burst time and priority
  {  
    x[i]=b[i];
    y[i]=p[i];
  }
  
  
  p[10]=0;
 
  for(time=0;count!=n;time++) //time runs until all processes are completed
  {
    largest=10;
    for(i=0;i<n;i++)
    {
      if(a[i]<=time && p[i]>p[largest] && b[i]>0 )//b[i]>0 to ensure process doesn't get repeated after completion.
      {
        largest=i;
      } 
    }
    if(largest==10)
    {
       printf("|Idle|");
    }
    else
    {
      printf("| P%d |",largest+1);
      b[largest]--;
    }
    if(b[largest]==0)
    {
      c[largest]=time+1;
      count++;
    }
  }
 
   for(i=0;i<n;i++)//calculate turnaround and waiting times
  {
  	tat[i]=c[i]-a[i];
  	wt[i]=tat[i]-x[i];
  }
 
  printf("|\nProcess Arrival Burst Completion Waiting Turnaround");
 
  for(i=0;i<n;i++)
  {
    printf("\n%d\t%d\t %d\t%d\t  %d\t  %d",i+1,a[i],x[i],c[i],wt[i],tat[i]);
  }
 
   return 0;
}
