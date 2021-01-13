/*
	Shukrithi Rathna
	CE16I031
	Highest response ratio next OS scheduling
*/

/*  Input arrival and burst time and priority for
	each process.
	Maximum 10 procceses.
*/
#include <stdio.h>
int main() 
{
  int a[10],b[10],c[10],tat[10],wt[10];
  float rr[10];
  int i,n,time,highest,count=0;
  int x[10]; //to store copy of burst time 
 
//Input number of proccesses   
  printf("\nEnter the number of Processes:\n");
  scanf("%d",&n); 
 
//Input arrival and burst times
  printf("\nEnter Arrival time and Burst time\nP A B\n");
  for(i=0;i<n;i++)
  {
    printf("\n%d ",i+1);
    scanf("%d",&a[i]);
    scanf("%d",&b[i]);
  }  
 
  for(i=0;i<n;i++)
  {  
    x[i]=b[i]; //save a copy of burst time;
  }
 
  rr[9]=0;
  time=0;
 
  while(count!=n) //time runs until all processes are completed
  {
    highest=9;
    for(i=0;i<n;i++)//iterate through all the processes and find one which has arrived in the given time and has least burst time.
    {
      if(b[i]>0)
	      rr[i]=(time-a[i]+b[i])/b[i];
      if(a[i]<=time && rr[i]>rr[highest] && b[i]>0 )//b[i]>0 to ensure process doesn't get repeated after completion.
	      highest=i;
    }
    if(highest==9)
    {
      printf("|Idle|");
      time++;      
    }
    else
    {
      while(b[highest]>0)
      {
	      printf("| P%d |",highest+1);
	      b[highest]--;
	      time++;        
          c[highest]=time;
      }
      count++; 
    }
    
  }
 
  for(i=0;i<n;i++)//calculate turnaround and waiting times
  {
  	tat[i]=c[i]-a[i];
  	wt[i]=tat[i]-x[i];
  }
 
  printf("\n");
 
  for(i=0;i<time;i++)
  {
  	printf("%d     ",i);
  }
 
  printf("|\nProcess Arrival Burst  Waiting Turnaround Completion");
  
  for(i=0;i<n;i++)
  {
    printf("\n%d\t%d\t %d\t%d\t  %d\t  %d",i+1,a[i],x[i],wt[i],tat[i],c[i]);
  }
 
  return 0;
}
