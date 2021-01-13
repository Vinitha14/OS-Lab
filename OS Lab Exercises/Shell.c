/*
	Shukrithi Rathna
	CED16I031	
	Command prompt simulation
*/

/*
	This program simulates the command prompt
	Command to be executed is taken as input.
	
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
	int k=1;
	while(k==1)
	{
		char a[10];
	 	printf("\nEnter the command \n");
	 	scanf("%s",a);  
	 	pid_t pid;
	 	pid=vfork();
		if(pid==0)
 		{
			execlp(a,a,NULL);
  			exit(0);
 		} 
 		else if(pid>0)
		{
			wait(NULL);
 			printf("Contiue:\n");
			scanf("%d",&k);
		}
	}
	return(0);
}
