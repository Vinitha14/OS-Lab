/*
	Shukrithi Rathna
	04-09-18
	Perfect Number
*/

/*	Number is perfect number
	if sum of its factors equals
	itself.
*/

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>

void PerfectNumber(int n);
void PerfectNumber(int n)
{
	int i,j,sum;
	
	for(j=1;j<=n;j++)
	{
		sum=0;
		//printf("Num:%d",j);
		for(i=1;i<j;i++)
		{
			if(j%i==0)
			{
				//printf("\nFactor:%d",i);
				sum=sum+i;
//				printf("\nSum:%d",sum);				
			}
		}
		if(sum==j)
			printf("\n %d is a perfect number\n",j);
		
	}
}

int main()
{
	pid_t cpid;
	int n;

	printf("\nEnter number (Upper bound):");
	scanf("%d",&n);

	cpid=fork();

	if(cpid==0)
	{
		printf("\nExecuting Child process");
		PerfectNumber(n);
	}
	else
		printf("\nParent Process completed");
	

	return(0);	
}
