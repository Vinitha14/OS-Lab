/*
	Shukrithi Rathna
	CED16I031
*/
/*
	Unidirectional Pipe
*/

#include<stdio.h>
#include<stdarg.h>
#include<unistd.h>
#include<sys/types.h>

#define BuffSize 25
#define REnd 0
#define WEnd 1

int  main()
{
	int fd[2];
	char ReadMsg[BuffSize];
	char WriteMsg[BuffSize]="Hello";
	pid_t pid;
	int pfd;
	
	
// creating pipe
	pfd=pipe(fd);
	
	if(pfd<0)
		printf("\nPipe creation unsuccessfull");
	else
		printf("\nTest");
		pid=fork();
	
	if(pid<0)
		printf("\nFork unsuccessfull");
	else if(pid>0)
	{
		printf("\nParent process\t Writing to pipe");

//Closing reading end
		close(fd[REnd]);

//Writing 		
		//open(fd[WEnd]);
		write(fd[WEnd],WriteMsg,sizeof(WriteMsg)+1);

//Closing writing end
		close(fd[WEnd]);
	}
	else
	{
		printf("\nChild process\tReading from pipe");

//Closing writing end
		close(fd[WEnd]);

//Reading	
		//open(fd[REnd]);	
		read(fd[REnd],ReadMsg,BuffSize);
	
		printf("\n%s\n",ReadMsg);

//Closing reading end
		close(fd[REnd]);
		
	}
		

	return(0);
	
}
