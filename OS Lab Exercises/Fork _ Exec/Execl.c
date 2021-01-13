/*
	Shukrithi Rathna
	CED16I031
	execl system call
*/
/*	execl takes input in the form of
	a list instead of vector.
	Path is to be included.
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	pid=fork();

	if(pid<0)
		printf("\nError \n");
	else if(pid==0)
	{
		printf("\nChild process\n");
  		execl("/bin/ls","ls","-l",NULL);
 	}
	else if(pid>0)
 	{
  		wait(NULL);
		printf("\nParent process \n");
 	}
	return(0);
}
