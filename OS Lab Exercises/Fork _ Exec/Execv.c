/*
	Shukrithi Rathna
	CED16I031
	execl system call
*/
/*	execv takes input in the form of
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
	char *cmd[]={"ls","-l",NULL};
	if(pid<0)
			printf("\nError \n");
 	else if(pid==0)
	{
 		printf("\nChild process \n");
		execv("/bin/ls",cmd);
	}
	else if(pid>0)
	{
		wait(NULL);
		printf("\nParent process \n");
	}
	return(0);
}	
