/*
	Shukrithi Rathna
	CE16I031
	First cum First Serve OS scheduling
*/

/*  Input arrival and burst time and priority for
	each process.
	Maximum 10 procceses.
*/
#include <stdio.h>
int main() 
{
  int a[10],b[10],c[10],tat[10],wt[10];//AT,BT,CT,TAT,WT
  int i,n,time,earliest,count=0;
  int x[10]; //to store copy of burst time 
  
//input number of proccesses
  printf("\nEnter the number of Processes:\n");
  scanf("%d",&n); 
  
//input arrival and burst times
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
  
  a[9]=100;//value for comparison
  time=0;//starting time

  while(count!=n) //time runs until all processes are completed. count=n=>all proccess have completed.
  {
    earliest=9;
    for(i=0;i<n;i++)//iterate through all the processes and find one which has arrived in the given time.
    {
      if(a[i]<=time && a[i]<a[earliest] && b[i]>0 )//b[i]>0 to ensure process doesn't get repeated after completion.
      earliest=i;
    }
    if(earliest==9)//value has not been updated => no proccess that matches required criteria has arrived thus far.
    {
      printf("|Idle|");
      time++;      
    }
    else
    {
      while(b[earliest]>0)//run proccess till comlpletion with increase in time.
      {
	      printf("| P%d ",earliest+1);
	      b[earliest]--;
	      time++;        
              c[earliest]=time;//store completion time
      }
      count++; //increase proccess completion count.
    }
    
  }
  for(i=0;i<n;i++)//Calculating waiting and turnaround times
  {
  	tat[i]=c[i]-a[i];
  	wt[i]=tat[i]-x[i];
  }
  printf("|\nProcess Arrival Burst Completion Waiting Turnaround");
  for(i=0;i<n;i++)
  {
    printf("\n%d\t%d\t %d\t%d\t  %d\t  %d",i+1,a[i],x[i],c[i],wt[i],tat[i]);
  }
  printf("\n");
  return 0;
}

