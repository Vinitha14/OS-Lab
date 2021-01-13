/*
	Shukrithi Rathna
	CED16I031
	18-09-18
*/

//Upper Case conversion using Tr command

#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

#define BuffSize 25
#define REnd 0
#define WEnd 1

int main(int argc, char *argv[])
{
	int fd[2];
	char ReadMsg[BuffSize];
	char WriteMsg[BuffSize];
	pid_t pid,cpid;
	int i;

// creating pipe
	if(pipe(fd)<0)
		fprintf("stderr","\nPipe creation unsuccessfull");
	pid=fork();
	
	if(pid<0)
		printf("\nFork unsuccessfull");
	else if(pid>0)
	{
		printf("\nParent process\t Writing to pipe");

		close(fd[REnd]);//Closing reading end
	
		printf("\nEnter msg for conversion");
		gets(WriteMsg);
		dprintf(fd[1], "%s\n", WriteMsg); //Writing 	
		
//		write(fd[1],WriteMsg,sizeof(WriteMsg)+1); - garbage values are also printed

		close(fd[WEnd]);//Closing writing end
	}
	else
	{
		printf("\nChild process\tReading from pipe");
		dup2(fd[0], STDIN_FILENO);  
		
		close(fd[WEnd]);
		close(fd[REnd]);
		
		char *argv[] = {"tr","[A-Z]","[a-z]", NULL}; // create argument vector
   		execvp(argv[0], argv);
	}
	return(0);
}
