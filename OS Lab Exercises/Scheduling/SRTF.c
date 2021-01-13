/*
	Shukrithi Rathna
	CE16I031
	Shortest remianing time OS scheduling
*/

/*  Input arrival and burst time for
	each process.
	Maximum 10 procceses.
*/

#include <stdio.h>
int main() 
{
  int a[10],b[10],c[10],tat[10],wt[10];
  int i,n,time,smallest,count=0;
  int x[10]; //to store copy of burst time
  
//input # processes
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

  b[9]=9999;//value for  comparison

  for(time=0;count!=n;time++) //time runs until all processes are completed
  {
    smallest=9;
    for(i=0;i<n;i++)
    {
      if(a[i]<=time && b[i]<b[smallest] && b[i]>0 )//b[i]>0 to ensure process doesn't get repeated after completion.
      smallest=i;
    }
    if(smallest==9)//values has not been updated => no proccess that matches required criteria has arrived thus far
    {
      printf("|Idle|");
    }
    else//run process for one second or given time quanta
    {
      printf("| P%d |",smallest+1);
      b[smallest]--;
    }
    if(b[smallest]==0)
    {
      c[smallest]=time+1;
      count++;
    }
  }
  
  for(i=0;i<n;i++)
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
