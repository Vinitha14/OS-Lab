/*
	Shukrithi Rathna
	CED16I031	
	Bash command prompt simulation
*/

/*
	This program simulates the command prompt and 
	also supports history feature.
	Command to be executed is taken as input.
	For complete history -'!!'
	For n commands, - !n'
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>


int main()
{
	int k=1;
	int i=0;
	int j;
	while(k==1)
	{
		char b[10][10];
		char a[10];
		printf("\nCommand:\n");
		scanf("%s",a); 
		strcpy(b[i],a);
		i++; 
		pid_t pid;
		pid=fork();
		if(pid==0)
		{
			if(a[0]=='!'&&a[1]=='!')
			{
				for(j=0;j<i;j++)
					printf("%s \t", b[j]);
			} 
			else if(a[0]=='!'&&a[1]>=48 && a[1]<=57)
			{
				for(j=i-1;j>i-1-(a[1]-48);j--)
					printf("%s \t", b[j]);
			} 
			else
				execlp(a,a,NULL);
 			exit(0);
 		} 
 		else if(pid>0)
 		{
 			wait(NULL);
 			printf("\nContiue:\n");
			scanf("%d",&k);
 		}
	}
	return(0);
}
