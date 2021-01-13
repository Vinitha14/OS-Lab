/*
	Shukrithi Rathna
	Binary search
	04-09-18
*/
/*
	Sorting in parent.
	Searching in child.
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void search(int c[],int beg,int end,int x) 
{
  int flag=0,pos;
  while(beg<=end)
  {
     int mid=(beg+end)/2;
     if(x==c[mid])
     {
	     flag=1;
	     pos=mid;
	     break;
     }
     else if(x<c[mid])
    	end=mid-1;
	 else
		beg=mid+1;
  }
  if(flag==1)
	  printf("\nElement found at position %d\n",pos);
	else
		printf("\nElement not found\n");
}
 
int main()
{
	int n,a[100],p;
    int k,i,j,temp;
  	printf("\nEnter the no of elements:\n");
    scanf("%d",&n);
	printf("\nEnter the elements:");
	for(int i=0;i<n;i++)
 	{
 		scanf("%d", &a[i]);
	}
	
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
	printf("\nSorted array:\n");
	for(int i=0;i<n;i++)
   	{
   		printf("%d ",a[i]);
   	}
	pid_t pid;
	pid=fork();
  	if(pid>0)
    {
    	printf("\nParent process complete");
    	wait(NULL);
	}
	else if(pid==0)
   	{
   		printf("\nExecuting child process");
    	printf("\nEnter the key: ");
		scanf("%d",&p);
	    search(a,0,n,p);
    }
	return(0);
}
