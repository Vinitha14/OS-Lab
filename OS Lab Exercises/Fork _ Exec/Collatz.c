/*
	Shukrithi Rathna
	Collatz Conjecture

*/
/*	Collats Conjecture - Sequence such that 
	any starting term n ultimately leads to 
	1
*/
/*
	To obtain sequence - if Tn is even
		=> Tn+1 = Tn/2
	Tn odd => Tn+1=(3*Tn)+1
*/

#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

int  collatz_conjecture(int k)
{
	int count=0;
	while(k!=1)
	{
		printf("%d ",k);
		if((k%2)==0)
		{
			k=k/2;
		}
		else if((k%2)==1)
		{
			k=(3*k)+1;
		}
		count++;
	}
	printf("%d\t",k);
	return(count);
}

int main()
{
	int n,j;
	pid_t pid;
	printf("\nEnter the number\n");
	scanf("%d",&n);
	pid=fork();

	if(pid==0)
	{
	   j=collatz_conjective(l);
	   printf("\nTotal no.of elements: %d",j);
	}

	return(0);
}
