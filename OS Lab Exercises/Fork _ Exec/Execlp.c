/*
	Shukrithi Rathna
	CED16I031
	execlp system call
*/
/*	execlp takes input in the form of
  	a list instead of vector.
  	Path not included
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
		execlp("ls","ls","-a",NULL);
	}
	else if(pid>0)
	{
		 wait(NULL);
		 printf("\nparent process \n");
	}
	return(0);
}
